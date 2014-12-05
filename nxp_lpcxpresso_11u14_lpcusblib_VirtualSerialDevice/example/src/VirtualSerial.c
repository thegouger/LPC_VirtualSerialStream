/*
 * @brief Make your board becomes a USB Virtual Com

 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * Copyright(C) Dean Camera, 2011, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "VirtualSerial.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/


/** LPCUSBlib CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface = {
	.Config = {
		.ControlInterfaceNumber         = 0,

		.DataINEndpointNumber           = CDC_TX_EPNUM,
		.DataINEndpointSize             = CDC_TXRX_EPSIZE,
		.DataINEndpointDoubleBank       = false,

		.DataOUTEndpointNumber          = CDC_RX_EPNUM,
		.DataOUTEndpointSize            = CDC_TXRX_EPSIZE,
		.DataOUTEndpointDoubleBank      = false,

		.NotificationEndpointNumber     = CDC_NOTIFICATION_EPNUM,
		.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE,
		.NotificationEndpointDoubleBank = false,
		.PortNumber             = 0,
	},
};

/** Standard file stream for the CDC interface when set up, so that the virtual CDC COM port can be
 *  used like any regular character stream in the C APIs
 */
static FILE* USBSerialStream;

/** Select example task, currently lpc11Uxx and lpc17xx don't support for bridging task
 * Only LPC18xx has this feature */

/*****************************************************************************
 * Private functions
 ****************************************************************************/

volatile bool output;

void SysTick_Handler(void)
{
	output = true;
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
static void SetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	USB_Init(VirtualSerial_CDC_Interface.Config.PortNumber, USB_MODE_Device);

	/* Enable and setup SysTick Timer at a 10Hz rate */
	SysTick_Config(SystemCoreClock / 10);

	/* Create a blocking usb serial stream (blocks on fgetc) */
	USBSerialStream = CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface);
	setbuf(USBSerialStream, NULL);
}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
int main(void)
{
	SetupHardware();

	for (;; ) {
		if(output)
		{
			/* Print a string to the stream */
			static uint8_t i = 0;
			fprintf(USBSerialStream, "Hello %d\n", ++i);

			/* Echo any received characters */
			while(CDC_Device_BytesReceived(&VirtualSerial_CDC_Interface))
			{
				fputc(fgetc(USBSerialStream), USBSerialStream);
			}
			output = false;
		}

		USB_USBTask(VirtualSerial_CDC_Interface.Config.PortNumber, USB_MODE_Device);
	}
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);

	//	LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

void EVENT_CDC_Device_LineEncodingChanged(USB_ClassInfo_CDC_Device_t *const CDCInterfaceInfo)
{
	/*TODO: add LineEncoding processing here
	 * this is just a simple statement, only Baud rate is set */
	// Serial_Init(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS, false);
}

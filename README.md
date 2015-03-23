# LPC Virtual Serial Stream Example

Modified VirtualSerial example and USB libraries from NXPUSBLib to provide support for C FILE streams.
Note that this requires the use of Newlib or an arm libc which supports cookie based custom streams.

Usage
-----

Include the modified
`CDCClassDevice.c`
`CDCClassDevice.h`

Create a file stream:

```c
static FILE* USBSerialStream; // global file stream

/* Create a blocking usb serial stream (blocks on fgetc) */
USBSerialStream = CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface);
setbuf(USBSerialStream, NULL);
```

Use file stream for input and output:
```c
fprintf(USBSerialStream, "Hello\n");
```

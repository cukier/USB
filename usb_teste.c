/*
 * usb_teste.c
 *
 *  Created on: 6 de out de 2015
 *      Author: cuki
 */

#include <18F4550.h>

#fuses HS, PLL1, VREGEN, USBDIV
#use delay(clock=8MHz)
#use rs232(uart1, baud=9600)

#DEFINE USB_HID_DEVICE  TRUE

#define USB_EP1_TX_ENABLE  USB_ENABLE_INTERRUPT
#define USB_EP1_TX_SIZE    64
#define USB_EP1_RX_ENABLE  USB_ENABLE_INTERRUPT
#define USB_EP1_RX_SIZE    64
#define USB_CONFIG_HID_TX_SIZE 16
#define USB_CONFIG_HID_RX_SIZE 16

#define USB_CONFIG_PID 1        //Chnage Vendor Id and Product Id
#define USB_CONFIG_VID 4660        //So that they will work with my Application

#include <pic18_usb.h>
#include <usb_desc_hid.h>
#include <usb.c>

int main(void) {

	setup_oscillator(OSC_8MHZ);
	usb_init_cs();
	delay_ms(500);

	while (TRUE) {
		usb_task();
		printf("enum%u\n\r", usb_enumerated());
		printf("att%u\n\r", usb_attached());
		delay_ms(1500);
	}
	return 0;
}

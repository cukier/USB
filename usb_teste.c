/*
 * usb_teste.c
 *
 *  Created on: 6 de out de 2015
 *      Author: cuki
 */

#include <18F4550.h>

#fuses HSPLL, MCLR, NOWDT, NOPROTECT, NOLVP, NODEBUG, USBDIV, PLL2, CPUDIV1, VREGEN, NOPBADEN
#use delay (clock = 48000000, crystal=8000000)
#use rs232(uart1, baud=9600)

#include <usb_desc_cdc.h>
#include <usb_cdc.h>

int main(void) {
	int cont;

	usb_cdc_init();
	usb_init();
	delay_ms(500);

	while (TRUE) {
		usb_task();
		printf("con%u\n\r", usb_cdc_connected());
		printf("enum%u\n\r", usb_enumerated());
		printf("att%u\n\r\n\r", usb_attached());
		printf(usb_cdc_putc, "%d\n\r", ++cont);
		delay_ms(1500);
	}
	return 0;
}

/*
 * usb_teste.c
 *
 *  Created on: 6 de out de 2015
 *      Author: cuki
 */

#include <24FJ64GB004.h>

#fuses HS, PR

#use delay(clock=15MHz)
#pin_select U1TX=PIN_B0
#pin_select U1RX=PIN_B1
#use rs232(uart1, baud=9600)

int main(void) {
	while (TRUE) {
		printf("Hello\n\r");
		output_toggle(PIN_B2);
		delay_ms(1000);
	}
	return 0;
}

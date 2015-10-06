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
#pin_select U2TX=PIN_B2
#pin_select U2RX=PIN_B3
#use rs232(uart1, baud=9600, stream=IO1)
#use rs232(uart2, baud=9600, stream=IO2)

int main(void) {
	while (TRUE) {
		fprintf(IO1, "Hello 1\n\r");
		fprintf(IO2, "Hello 2\n\r");
		output_toggle(PIN_B2);
		delay_ms(1000);
	}
	return 0;
}

#include <18F4550.h>
#fuses HSPLL,NOMCLR,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN,NOPBADEN //Fuses do PIC

#use delay(clock=48MHz)

#include <usb_cdc.h>
#include <usb_desc_cdc.h>

#define LED PIN_d1

long q, q1;
float p;

int main(void) {

	output_low(LED);

	usb_cdc_init();
	usb_init();

	while (!usb_cdc_connected())
		;

	while (TRUE) {
		usb_task();
		q1 = 0;
		setup_adc_ports(AN0 | VSS_VDD);
		setup_adc(ADC_CLOCK_INTERNAL);
		set_adc_channel(0);

		if (usb_enumerated()) {

			q = read_adc();

			if (q != q1) {
				output_high(LED);
				p = 5.0 * q / 1024.0;
				printf(usb_cdc_putc, "\r Voltage=%01.2fV", p);
			}
			q1 = q;
			output_low(LED);
			delay_ms(100);
		}
	} //infinete loop
	return 0;
} //main

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>
/*
 * connections:
 * 8 LEDs on PORTA
 * 8 SWITCHES on PORTC
 * COM of LEDS on pin 0 PORTD
 */
void main(void) {
	DDRA = 255;
	DDRC = 0;
	PORTC = 255;
	DDRD = 1;
	CLR_BIT(PORTD, 0);
	while (1) {
		switch (PINC) {
		case 1:
			PORTA = 255;
			_delay_ms(500);
			PORTA = 0;
			_delay_ms(500);
			break;
		case 2:
			for (s8 pin = 7; pin >= 0; pin--) {
				SET_BIT(PORTA, pin);
				_delay_ms(250);
				CLR_BIT(PORTA, pin);
			}
			break;
		case 4:
			for (u8 pin = 0; pin < 8; pin++) {
				SET_BIT(PORTA, pin);
				_delay_ms(250);
				CLR_BIT(PORTA, pin);
			}
			break;
		case 8:
			for (u8 pin = 0; pin <= 3; ++pin) {
				SET_BIT(PORTA, pin);
				SET_BIT(PORTA, (7-pin));
				_delay_ms(300);
				CLR_BIT(PORTA, pin);
				CLR_BIT(PORTA,  (7-pin));
			}
			break;
		case 16:
			for (s8 pin = 3; pin >= 0; --pin) {
				SET_BIT(PORTA, pin);
				SET_BIT(PORTA,  (7-pin));
				_delay_ms(300);
				CLR_BIT(PORTA, pin);
				CLR_BIT(PORTA,  (7-pin));
			}
			break;
		case 32:
			for (u8 pin = 0; pin < 7; pin++) {
				SET_BIT(PORTA, pin);
				_delay_ms(250);
				CLR_BIT(PORTA, pin);
			}
			for (s8 pin = 7; pin >= 1; pin--) {
				SET_BIT(PORTA, pin);
				_delay_ms(250);
				CLR_BIT(PORTA, pin);
			}
			break;
		case 64:
			for (u8 pin = 0; pin < 8; ++pin) {
				SET_BIT(PORTA, pin);
				_delay_ms(250);
			}
			PORTA = 0;
			break;
		case 128:
			for (u8 pin = 0; pin < 8; ++pin) {
				SET_BIT(PORTA, pin);
				SET_BIT(PORTA,  (7-pin));
				_delay_ms(300);
				CLR_BIT(PORTA, pin);
				CLR_BIT(PORTA,  (7-pin));
			}
			break;
		}
	}
}

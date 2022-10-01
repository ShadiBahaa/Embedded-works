#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "NUMBERS.h"
void main(void) {
	/*
	 * Connections:
	 * PORTA is connected to the seven segment that shows the left digit
	 * PORTB is connected to the seven segment that shows the right digit
	 * PORTC pins (0,1,2) are connected to (yellow,green,red) LEDs respectively
	*/
	DDRA = 255;
	DDRB = 255;
	DDRC = 255;
	PORTC = 1;
	u8 cnt = 0;
	u8 numbers[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SEX, SEVEN, EIGHT, NINE};
	for (s8 seg1 = 9; seg1>=0 ; --seg1){
		for (s8 seg2 = 9; seg2>=0; --seg2){
			if (cnt==10 && PORTC==1){
				PORTC = 2;
				cnt = 0;
			}else if (cnt==3 && PORTC==2){
				PORTC = 4;
				cnt = 0;
			}else if (cnt==10 && PORTC==4){
				PORTC = 1;
				cnt = 0;
			}
			PORTA = numbers[seg1];
			PORTB = numbers[seg2];
			_delay_ms(1000);
			cnt++;
		}
		if (seg1==0)seg1 = 10;
	}
}

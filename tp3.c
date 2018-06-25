
#include "iq.h"
#include "iq_adc.h"
#define byte unsigned char

byte *trisb = (byte *)0xf93 ;
byte *portb = (byte *)0xf81 ;
byte *trisc = (byte *)0xf94 ;
byte *portc = (byte *)0xf82 ;


void init_adc();
byte lecture_analogique();


void main(void) {
	*trisb=0;
	*trisc=1;
	init_adc();
	
	*portc = 0;
	while(1) {
		unsigned char temperature = convert_hex_dec(lecture_analogique()/5);
	  	*portb = temperature;   // Read result
		
		if (temperature < 20) {
			*portc = *portc & 0x04;
			*portc = *portc | 0x02;
		}
		else {
			*portc = *portc & 0x02;
			*portc = *portc | 0x04;
		}
	}
}
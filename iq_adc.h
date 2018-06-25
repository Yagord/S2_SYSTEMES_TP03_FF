

#include<delays.h>
#include<adc.h>

void init_adc()
{
 OpenADC( ADC_FOSC_32      &
         ADC_RIGHT_JUST   &
         ADC_16_TAD,
         ADC_CH0          &
         ADC_REF_VDD_VSS  &
         ADC_INT_OFF, 12  );


Delay10TCYx( 5 );     // Delay for 50TCY

}

unsigned char lecture_analogique()
{
ConvertADC();         // Start conversion\par
while( BusyADC() );   // Wait for completion\par
return(ReadADC() >> 2);   // Read result\par
}

unsigned char convert_hex_dec(unsigned char hex) {

	unsigned char deb;
	unsigned char fin;	
	
	deb = hex % 10;
	fin = hex / 10;
	
	return deb + fin*16;
}


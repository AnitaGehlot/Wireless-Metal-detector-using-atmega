#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
	/* motion at a2 metal at a1
	IR at d2 d3
	MOTOR B0,B1,B2,B3 */

	DDRA&=~(1<<0);
	PORTA|=(1<<0);
	
	DDRA&=~(1<<1);
	PORTA|=(1<<1);
	
	

	USARTInit(95);
	InitLCD(0);

	LCDClear();
	LCDWriteStringXY(0,0,"WELCOME");
	_delay_ms(500);

	while(1)
	{
		if((!(PINA&1))&&(!(PINA&2)))
		{
			LCDClear();
			LCDWriteStringXY(0,0," METAL DETECTED");			
			LCDWriteStringXY(1,1,"MOTION DETECTED ");
			USARTWriteChar('a');
			_delay_ms(5);
		}
		else if((!(PINA&1))&&(PINA&2))
		{
			LCDClear();
			LCDWriteStringXY(0,0," METAL DETECTED ");			
			LCDWriteStringXY(1,1," NO MOTION  ");
			USARTWriteChar('b');
			_delay_ms(5);
		}
		else if((PINA&1)&&(!(PINA&2)))
		{
			LCDClear();
			LCDWriteStringXY(1,0," NO METAL");			
			LCDWriteStringXY(1,1,"MOTION DETECTED ");
			USARTWriteChar('c');
			_delay_ms(5);
		}
		else if((PINA&1)&&(PINA&2))
		{
			LCDClear();
			LCDWriteStringXY(1,0," NO METAL");			
			LCDWriteStringXY(1,1," NO MOTION  ");
			USARTWriteChar('d');
			_delay_ms(5);
		}
		}
}
			


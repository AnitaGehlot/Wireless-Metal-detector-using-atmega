#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
void main()
{
	InitLCD(0);
	USARTInit(95);
	LCDClear();	
	LCDWriteStringXY(5,0,"WELCOME");
	_delay_ms(500);

	LCDClear();	
	LCDWriteStringXY(0,0,"DEVICE READY TO");
	LCDWriteStringXY(5,1,"RECEIVE..");
	_delay_ms(150);
	char data;
	
	while(1)
	{
	data=USARTReadChar();
		if(data=='a')
		{
			LCDClear();
			LCDWriteStringXY(0,0," METAL DETECTED");			
			LCDWriteStringXY(1,1,"MOTION DETECTED ");
			_delay_ms(20);
		}
		else if(data=='b')
		{
			LCDClear();
			LCDWriteStringXY(0,0," METAL DETECTED ");			
			LCDWriteStringXY(1,1," NO MOTION  ");
			_delay_ms(20);
		}
		else if(data=='c')
		{
			LCDClear();
			LCDWriteStringXY(1,0," NO METAL");			
			LCDWriteStringXY(1,1,"MOTION DETECTED ");
			_delay_ms(20);
		}
		else if(data=='d')
		{
			LCDClear();
			LCDWriteStringXY(1,0," NO METAL");			
			LCDWriteStringXY(1,1," NO MOTION  ");
			_delay_ms(20);
		}
}}

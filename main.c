/*
 * Using Buttons To Display Numbers On 8Seg.c
 *
 * Created: 6/02/2020 8:43:56 PM
 * Author : bulle
 */ 



#define F_CPU 8000000UL // Clock SpeedThis is a macro that will be used by the compiler to calculate delay loops, and states it to be 8MHz, without this line the program defaults to some other value (1000000) and all the timing would be wrong.
#include <util/delay.h> // included to use delay function
#include <avr/io.h> // include the chip


 
int main(void)
{
  DDRC=0xFF; // Setting PORTC as outputs(LED)
  DDRA =0x00;// Setting PORTA as inputs (Switches)

PORTC-0x00;// initial Value turned off
	
#define NUM1 (!(PINA& (1<<0))) // Setting this as active when its 0..
#define NUM2 (!(PINA& (1<<1)))
#define NUM3 (!(PINA& (1<<2)))
#define NUM4 (!(PINA& (1<<3)))

#define NUM5 PINA & (1<<4)
#define NUM6 PINA & (1<<5)
#define NUM7 PINA & (1<<6)   // will be checking for n bit 
#define NUM8 PINA & (1<<7)

#define N1 PORTC=0x01;
#define N2 PORTC =0x02;  // definding number as PORTS
#define N3 PORTC=0x03;
#define N4 PORTC =0x04;
#define N5 PORTC =0x05;
#define N6 PORTC =0x06;
#define N7 PORTC =0x07;
#define N8 PORTC =0x08;


    while (1) 
    {
	
		if(NUM1)
		{
			N1;

		}
		else if (NUM2)
		{
			N2;
		} 
		else if (NUM3)
		{
			N3;
		}
		
		else if (NUM4)
		{
			N4;
		}
		else if (NUM5)
		{
			N5;
		}
		
		else if (NUM6)
		{
			N6;
		}
	
		else if (NUM7)
		{
			N7;
		}
			
		else if(NUM8)
		{
			N8;
		}
		else
		{
			_delay_ms(500);
			PORTC=0xFF;
			
		}
	}
    
}
/* Ways to test PINS 
To test if a bit is on (logical 1), the two following statements can be used. 
These functions perform a logical AND with both the PIN register and the bit 
(represented as an 8-bit number).
 If the result is zero, the if statement will not be executed because 
 if statements only execute when the condition is non-zero. 


if ( PINB & (0b00000001))
or
if ( PINB & (1 << n)) where n = bit under test (0 - 7)
Testing for a logical 0 is easily done by using the negation operator before the main test (!)

if ( !(PINB & (0b00000001)) )
or
if ( !(PINB & (1 << n)) ) where n = bit under test (0 – 7)
*/ 




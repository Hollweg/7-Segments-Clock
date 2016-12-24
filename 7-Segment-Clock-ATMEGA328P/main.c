/*
 * 7-Segments-Display-ATMEGA328P.c
 *
 * Created: 29/11/2016 17:52:26
 * Author : Hollweg
 * Available on www.github.com/hollweg
 */ 

#define F_CPU 16000000UL
#define PORT_ON(port,pin) port |= (1<<pin)
#define PORT_OFF(port,pin) port &= ~(1<<pin)
#define true 1
#define false 0

#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include <stdbool.h>

void CalculateSeconds (bool time_display);
void CalculateMinutes (bool time_display);
void CalculateHours (bool time_display);
void WriteDisplays(uint8_t digit, uint8_t displaynum);
void InitADC();
uint16_t ReadADC(uint8_t channel);

uint8_t hour = 0;
uint8_t minutes = 0;
uint8_t seconds = 0;

uint8_t seven_seg_digits[10][7] = {						
								{ 1,1,1,1,1,1,0 },  // = 0
								{ 0,1,1,0,0,0,0 },  // = 1
								{ 1,1,0,1,1,0,1 },  // = 2
								{ 1,1,1,1,0,0,1 },  // = 3
								{ 0,1,1,0,0,1,1 },  // = 4
								{ 1,0,1,1,0,1,1 },  // = 5
								{ 1,0,1,1,1,1,1 },  // = 6
								{ 1,1,1,0,0,0,0 },  // = 7
								{ 1,1,1,1,1,1,1 },  // = 8
								{ 1,1,1,0,0,1,1 }   // = 9
};

/***********************************************
 * Name:
 *    CalculateSeconds
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Function to write on 7 segments display
 *    It receives two arguments: the digit  
 *    and the display number to to be writed 
 *
 ************************************************/
void CalculateSeconds (bool time_display)
{
	switch (time_display){
		case 0:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					WriteDisplays(seconds,0);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(seconds%10,0);
				}
	
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(0,0);
				}
		break;
		
		case 1:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					_delay_ms(25);
					WriteDisplays(seconds,0);
					_delay_ms(25);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(seconds%10,0);
					_delay_ms(25);
				}
				
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(0,0);
					_delay_ms(25);
				}
		break;
	}
}//~~ end of CalculateSeconds

/***********************************************
 * Name:
 *    CalculateMinutes
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Function to write on 7 segments display
 *    It receives two arguments: the digit  
 *    and the display number to to be writed 
 *
 ************************************************/
void CalculateMinutes (bool time_display)
{
	switch (time_display){
		case 0:
				if (minutes/10 == 0 && minutes < 10){
					WriteDisplays(0,1);
					WriteDisplays(minutes, 0);
				}
	
				else if (minutes%10 == 0){
					WriteDisplays(minutes/10, 1);
					WriteDisplays(0,0);
				}
	
				else if (minutes%10 != 0){
					WriteDisplays(minutes/10, 1);
					WriteDisplays(minutes%10,0);
				}
		break;
		
		case 1:
				if (minutes/10 == 0 && minutes < 10){
					WriteDisplays(0,1);
					_delay_ms(25);
					WriteDisplays(minutes, 0);
					_delay_ms(25);
				}
				
				else if (minutes%10 == 0){
					WriteDisplays(minutes/10, 1);
					_delay_ms(25);
					WriteDisplays(0,0);
					_delay_ms(25);
				}
				
				else if (minutes%10 != 0){
					WriteDisplays(minutes/10, 1);
					_delay_ms(25);
					WriteDisplays(minutes%10,0);
					_delay_ms(25);
				}
		break;
	}	
}//~~ end of CalculateMinutes

/***********************************************
 * Name:
 *    CalculateHours
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Function to write on 7 segments display
 *    It receives two arguments: the digit  
 *    and the display number to to be writed 
 *
 ************************************************/
void CalculateHours (bool time_display)
{
	switch (time_display){
		case 0:
				if (hour/10 == 0){
					WriteDisplays(0,3);
					WriteDisplays(hour,2);
				}
	
				else{
					WriteDisplays(1,3);	
					WriteDisplays(hour%10,2);	
				}
		break;
		
		case 1:
				if (hour/10 == 0){
					WriteDisplays(0,3);
					_delay_ms(50);
					WriteDisplays(hour,2);
					_delay_ms(50);
				}
				
				else{
					WriteDisplays(1,3);
					_delay_ms(50);
					WriteDisplays(hour%10,2);
					_delay_ms(50);
				}
				break;	
	}
}//~~ end of CalculateHours

/***********************************************
 * Name:
 *    WriteDisplays
 * In:
 *    int digit, int displayNum
 * Out:
 *    --
 * Description:
 *    Function to write on 7 segments display
 *    It receives two arguments: the digit  
 *    and the display number to to be writed 
 *
 ************************************************/
void WriteDisplays(uint8_t digit, uint8_t display_num) 
{
	uint8_t pin = 2;
	PORTD &= 0b00000000;
	PORTB &= (0<<PB0);
	PORTB &= (0<<PB1);
		
	if (display_num == 0){							
		PORTB &= (0<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 1){
		PORTB &= (0<<PB3);
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 2){
		PORTB &= (0<<PB4);
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 3){
		PORTB &= (0<<PB5);		
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB4);
	}
	
	for (int segCount = 0; segCount < 7; ++segCount){
		if (pin < 8)
			PORTD |= (seven_seg_digits[digit][segCount]<<pin);
		else
			PORTB |= (seven_seg_digits[digit][segCount]<<0);
		++pin;
	}
}//~~end of WriteDisplays

/***********************************************
 * Name:
 *    InitADC
 * In:
 *    int digit, int display_num
 * Out:
 *    --
 * Description:
 *	  Function to initialized ADC conversion
 * 
 *
 ************************************************/
void InitADC ()
{
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);		// ADEN: Set to turn on ADC , by default it is turned off
	ADMUX = 0x00 | (1<<REFS0);							//ADPS2: ADPS2 and ADPS0 set to make division factor 32
														// ADC input set to channel 0 and Vref <- AVcc
}//~~ end of InitADC

/***********************************************
 * Name:
 *    ReadADC
 * In:
 *    uint8_t channel
 * Out:
 *    adc_value
 * Description:
 *    Function to Read ADC Value
 *	  The channel to be read is entered as input
 *
 ************************************************/
uint16_t ReadADC (uint8_t channel)
{
	uint16_t adc_value;

	ADMUX &= 0xF0;                    			//Clear the older channel that was read
	ADMUX = channel | (1<<REFS0);				// ADC input channel set to channel and Vref <- AVcc
	ADCSRA |= (1<<ADSC);						// Start conversion
	while (ADCSRA & (1<<ADSC));					// wait for conversion to complete
	
	adc_value = ADCW;							//Store ADC value
	return adc_value;
}//~~ end of ReadADC

/***********************************************
 * Name:
 *    main
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Main function
 *
 *
 ************************************************/
int main(void)
{
	uint8_t pin, digit;
	uint16_t adc_value;
										  //Data Direction Register: 1 - output    0 - input
	DDRD = 0b11111100;                    //7 segments bus control: PORTB(2,3,4,5)
	DDRB = 0b00111111;					  //7 segments multiplexed leds: Arduino UNO pins 2 - 7: PORTD(2,3,4,5,6,7) and 8: PORTB0
										  //Arduino pin 9: PB1 --- white LED 
	PORTB |= (0<<PB2);
	PORTB |= (1<<PB3);
	PORTB |= (1<<PB4);
	PORTB |= (1<<PB5);
	
	InitADC();
	
	OCR1A = 0x3D08;							//Timer definitions
	TCCR1B |= (1 << WGM12); 				// Mode 4, CTC on OCR1A
	TIMSK1 |= (1 << OCIE1A);   				//Set interrupt on compare match
	TCCR1B |= (1 << CS12) | (1 << CS10);  	// set prescaler to 1024 and start the timer
	sei();									// enable interrupts
	
	PORT_OFF(PORTB,1);
	
    for(;;) 
    {	
		/*adc_value = ReadADC(0);
		if (adc_value > 750){
			cli();
			seconds += 1;
			if (seconds > 59){
				minutes += 1;
				seconds = 0;
			}
					
			if (minutes > 59){
				hour += 1;
				minutes = 0;
			}
					
			if (hour > 12){
				hour = 0;
			}
			
			//CalculateSeconds(1);
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}*/
		
		adc_value = ReadADC(1);
		if (adc_value > 750) {
			cli();
			minutes += 1;
			
			if (minutes > 59){
				hour += 1;
				minutes = 0;
			}
					
			if (hour > 11){
				hour = 0;
			}

			//CalculateSeconds(1);
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}
		
		adc_value = ReadADC(2);
		if (adc_value > 750) {
			cli();	
			hour += 1;
							
			if (hour > 11){
				hour = 0;
			}
			
			//CalculateSeconds(1);
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}
		
		//CalculateSeconds(0);
		CalculateMinutes(0);
		CalculateHours(0);
	}
}

ISR (TIMER1_COMPA_vect)
{
	//action to be done every 1 sec
	
		if (seconds > 59){
			minutes += 1;
			seconds = 0;
		}
		
		if (minutes > 59){
			hour += 1;
			minutes = 0;
		}
		
		if (hour > 11){
			hour = 0;
		}
		seconds += 1;
}//~~ end of interruption

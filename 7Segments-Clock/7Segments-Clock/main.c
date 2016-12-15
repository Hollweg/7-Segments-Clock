/*
 * 7Segments-Clock.c
 *
 * Created: 27/11/2016 12:55:24
 * Author : Guilherme
 */ 

#include <avr/io.h>
#include "util/delay.h"

int seven_seg_digits[10][7] = {						//array contendo os valores dos digitos para o display de 7seg
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
 *    WriteDisplays
 * In:
 *    int digit, short int displayNum
 * Out:
 *    --
 * Description:
 *    Funcao para escrita no display 7 segmentos
 *    Recebe 2 argumentos, o dígito a ser escrito e
 *    o display a ser escrito
 *
 ************************************************/
void WriteDisplays(int digit, short int displayNum) {
	int pin = 0;
	
	if (displayNum == 0){							//verifica o display a ser escrito
		PORTD |= (0<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
	}
	else if (displayNum == 1){
		PORTD |= (1<<PD0);
		PORTD |= (0<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
	}
	else if (displayNum == 2){
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (0<<PD2);
		PORTD |= (1<<PD3);
	}

	else if (displayNum == 3){
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (0<<PD3);
	}
		
	for (int segCount = 0; segCount < 7; ++segCount){			//escreve no display o digito solicitado
		if (pin > 6)											//necessario verificar o pino ate a posicao 6 pois o ATMEGA328 nao possui 1 byte
			PORTB |= (seven_seg_digits[digit][segCount]<<pin);	//completamente acessivel. 
		else
			PORTD |= (seven_seg_digits[digit][segCount]<<5);
		++pin;
	}
}
int main(void)
{
	DDRD = 0b00101111;                    //pin 11 g of 7 segment bus led ---- D0,D1,D2,D3 - 7 segments control leds
	DDRB = 0b00111111;					  //pins 8 - 13: 7 segments bus leds
										  //Os pinos de escrita no display foram (PORTB 0 a 5) e (PORTD 5) pois nem o PORTD nem o PORTB permitem
										  //acesso total ao usuario
	PORTD |= (1<<PD0);
	PORTD |= (1<<PD1);
	PORTD |= (1<<PD2);
	PORTD |= (1<<PD3);
	
    while (1) 
    {
		WriteDisplays(5,0);
		_delay_ms(500);
		WriteDisplays(5,1);
		_delay_ms(500);
		WriteDisplays(5,0);
		_delay_ms(500);
		WriteDisplays(5,1);
		_delay_ms(500);
    }
}



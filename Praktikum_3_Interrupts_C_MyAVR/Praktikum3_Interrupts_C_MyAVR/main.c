/*
 * Praktikum3_Interrupts_C_MyAVR.c
 *
 * Created: 10.12.2018 16:17:11
 * Author : andrei
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 3600000UL // Taktfrequenz für den ATMega328P
#include <util/delay.h>

const uint8_t aus = 0;
const uint8_t rot = 1;
const uint8_t gruen = 2;

uint8_t state = 0;

ISR (INT0_vect){
	
	if(state == aus){
		state = gruen;
	}else if(state == gruen){
		state = aus;
	}else if(state == rot){
		state = gruen;
	}
	
	_delay_ms(200);
	
	
}

ISR (INT1_vect){
	
	if(state == aus){
		state = rot;
	}else if(state = rot){
		state = aus;
	}else if(state == gruen){
		state = rot;
	}
	
	
	_delay_ms(200);
	
	
}

void initializeISR(){
	
	DDRD = (0 << PD2) | (0 << PD3);
	PORTD = (1 << PD2) | (1 << PD3);
	GICR  = (1 << INT0) | (1 << INT1);
	MCUCR = (1 << ISC11) | (1 << ISC01);
	sei();
}

void initializeApp(){
	
	DDRB = 0xFF;
}



int main(void)
{
	initializeApp();
	initializeISR(); //Den Interrupt-Service einrichten
	
	while (1)
	{
		
		if(state == aus){
			PORTB = 0b0000000;
		}
		
		if(state == rot){
			PORTB = (1 << PB0);
		}
		
		if(state == gruen){
			PORTB = (1 << PB1);
		}
		
		_delay_ms(500);
		PORTB = 0b00000000; //Alle LEDs gehen aus
		_delay_ms(500);
		
		
	}
}


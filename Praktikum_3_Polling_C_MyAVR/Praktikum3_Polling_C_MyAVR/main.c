/*
 * Praktikum3_Polling_C_MyAVR.c
 *
 * Created: 10.12.2018 16:06:05
 * Author : andrei
 */ 

#define F_CPU 3600000UL
#include <avr/io.h>


#include <util/delay.h>
int state = 0;

void init(){
	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0xFF;
}



int main(void)
{
	/* Replace with your application code */
	
	init();
	
	
	while (1)
	{
		
		if(PIND == 0b11111011){
			if(state == 1){
				state = 0; //aus
				}else if(state == 2){
				state = 1; // blau
				}else if(state == 0){
				state = 1; //blau
			}
			}else if(PIND == 0b11110111){
			if(state == 2){
				state = 0; // aus
				}else if(state = 1){
				state = 2; //grün
				}else if(state = 0){
				state = 2; //grün
			}
		}
		
		if(state == 1){
			PORTB = 0b00000001; //Blau leuchtet
			}else if(state == 2){
			PORTB = 0b00000010;	//Grün leuchtet
		}
		
		_delay_ms(500);
		PORTB = 0b00000000; //Alle LEDs gehen aus
		_delay_ms(500);
	}
}


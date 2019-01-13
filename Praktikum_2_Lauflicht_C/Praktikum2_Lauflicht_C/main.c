/*
 * Praktikum2_Lauflicht_C.c
 *
 * Created: 25.10.2018 16:27:36
 * Author : andrei
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL // hier muss die passende Taktfrequenz rein
#include <util/delay.h>

#define erstes 1
#define zweites 2
#define drittes 4

int main(void)
{
    /* Replace with your application code */
	DDRB = 0b00000111;
	
    
	
	while (1) 
    {
		
		_delay_ms(200.0);
		PORTB = erstes;
		_delay_ms(200.0);
		PORTB = zweites;
		_delay_ms(200.0);
		PORTB = drittes;
		_delay_ms(200.0);
		PORTB = zweites;

    }
}


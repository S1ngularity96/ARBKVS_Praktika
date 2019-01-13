;
; Praktikum_1_Lauflicht.asm
;
; Created: 15.10.2018 13:02:57
; Author : andrei
;

.include "m328Pdef.inc"	; Prozessordefinitionen laden

.org 0x000		; Reset Vector
	rjmp start
;Rest der Tabelle bleibt ungenutzt

start:
	
	;PB0 PB1 PB2 als Output
	ldi r16,0b00000111 ; SET HIGH für OUTPUT
	out DDRB, r16 ; Datadirectionbit
	ldi r16, 0b0000001
	
main:
	out PORTB,r16
	lsl r16
	rcall delay
	out PORTB, r16
	lsl r16
	rcall delay	
	out PORTB, r16
	lsr r16
	rcall delay
	out PORTB, r16
	lsr r16
	rcall delay
	out PORTB, r16
	
	
	rjmp main		;Ruecksprung

delay: ; 3 verschachtelte schleifen
ldi r21, 255
schleife:
	ldi r22, 10
	schleife2:
		ldi r23, 255
		schleife3:
			nop
			dec r23
			BRNE schleife3
		dec r22
		BRNE schleife2
	dec r21
	BRNE schleife	
	ret
	
	


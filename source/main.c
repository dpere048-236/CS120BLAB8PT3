/*	Author: David Perez  dpere048
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab6 #  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //initialize DDRA as inputs
	DDRB = 0xFF; PORTB = 0x00; //init port B to 0s and outputs
	DDRD = 0xFF; PORTD = 0x00;
//	TimerSet(300); //leds timer light for 300ms
//	TimerOn();
	ADC_init();
	unsigned short upper = 500;
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	if(x > upper){
		upper = x;
	}
	if(x >= upper/2){
		tmpB = 0x00;
	}
	else{
		tmpB = 0x01;
	}

	PORTB = tmpB;    }
    return 0;
}

/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#include "timer.h"

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    TimerSet(1000);
    TimerOn();
    
    unsigned char led = 0x01;

    /* Insert your solution below */
    while (1) {
        if((led == 0x01)){
	    led =0x02;
        }
        else if ((led == 0x02)){
	    led =0x04;
        }
        else {
            led = 0x01;
        }
        //led = (led == 0x03)? 0x01:0x03;
        PORTB = led;

	while (!TimerFlag){};
	TimerFlag = 0;
	



    }
    return 1;
}

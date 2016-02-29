/********************************
 * Ivan Cordoba
 * Nathaniel Christianson
 * Alex Levine
 * Jordan Jeffries
 * 
 * ECE 372A
 * LAB 2 PART 1
 *******************************/

#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "lcd.h"
#include "keypad.h"
#include "interrupt.h"

volatile unsigned int val = 0;

int main(void) {
    initTimer(1,0,4);
    initLCD();
    
    initKeypad();
    
    char s[32];
    
    while(1) {
        itoa(val, s, 10);
        printStringLCD(s);
    }
    
    return(0);
}

void __ISR(_ADC_VECTOR, IPL7AUTO) _ADCInterrupt(void) {
    IFS0bits.AD1IF = 0;
    AD1CHSbits.CH0SA = 0;
    val = ADC1BUF0;
}
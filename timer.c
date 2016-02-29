/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer(int timer, int PR, int priority) {
    switch(timer) {
        case(1):
            PR1 = PR;
            TMR1 = 0;
            T1CONbits.TCKPS = 3;
            T1CONbits.TCS = 0;
            IEC0bits.T1IE = 1;
            IFS0bits.T1IF = 0;
            IPC1bits.T1IP = priority;
            T1CONbits.ON = 0;
            break;
        case(2):
            PR2 = PR;
            TMR2 = 0;
            T2CONbits.TCKPS = 3;
            T2CONbits.TCS = 0;
            IEC0bits.T2IE = 1;
            IFS0bits.T2IF = 0;
            IPC2bits.T2IP = priority;
            T2CONbits.ON = 0;
            break;
    }    
}

void delayUs(unsigned short t)
{
    T1CONbits.TCKPS = 1;
    T1CONbits.TCS = 0;
    IPC2bits.T2IP = 4;
    TMR1 = 0;
    T1CONbits.ON = 1;
    while(TMR1 < t);
    T1CONbits.ON = 0;    
} 

void delayMs(unsigned int delay){
    for(delay = delay; delay > 0; delay--) {
        delayUs(1000);
    }
}
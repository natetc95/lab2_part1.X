#include <xc.h>
adcnclude "timer.h"

void initADC(void) {
    
    //AD1CON1bits
    
    AD1CON1bits.FORM = 0;
    AD1CON1bits.SSRC = 7;
    AD1CON1bits.ASAM = 1;
    
    //AD1CON2bits
    
    AD1CON2bits.VCFG = 0;
    AD1CON2bits.CSCNA = 0;
    AD1CON2bits.SMPI = 8;
    AD1CON2bits.BUFM = 0;
    AD1CON2bits.ALTS = 0;
    
    //AD1CON3bits
    
    AD1CON3bits.ADRC = 0;
    AD1CON3bits.SAMC = 2;
    AD1CON3bits.ADCS = 1;
    
    //AD1CHSbits
    
    AD1CHSbits.CH0NA = 0;
    AD1CHSbits.CH0SA = 0;
    
    //AD1CSSLbits
    
    AD1CSSLbits.CSSL = 21; // Scan pins AN0, AN2, and AN4
    
    //ADC Interrupts
    
    IFS0bits.AD1IF = 0;
    IPC5bits.AD1IP = 7;
    IEC0bits.AD1IE = 1;
    
    //Turn the ADC On
    
    AD1CON1bits.ADON = 1;
}

void initKeypad(void) {
    initADC();
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB4 = 0;
}
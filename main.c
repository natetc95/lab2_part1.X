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

int main(void) {
    initTimer(1,0,4);
    initLCD();
    
    initKeypad();
    
    while(1) {
        
    } 
    return(0);
}

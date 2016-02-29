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
#include "switch.h"
#include "timer.h"
#include "lcd.h"

#define row1_tris TRISDbits.TRISD0
#define row2_tris TRISDbits.TRISD0
#define row3_tris TRISDbits.TRISD0
#define row4_tris TRISDbits.TRISD0

#define row1_power LATDbits.LATD0
#define row2_power LATDbits.LATD0
#define row3_power LATDbits.LATD0
#define row4_power LATDbits.LATD0

#define col1_tris TRISDbits.TRISD0
#define col2_tris TRISDbits.TRISD0
#define col3_tris TRISDbits.TRISD0

#define col1_read PORTDbits.RD0
#define col2_read PORTDbits.RD0
#define col3_read PORTDbits.RD0

#define INPUT 1
#define OUTPUT 0

typedef enum rowsEnum {
	r1,r2,r3,r4
}row;

typedef enum colsEnum {
	c1,c2,c3, n0
}col;

volatile row state = r1;
volatile col curr = c1;
volatile bit wait = 0;
volatile col out;

int main(void) {
	
	row1_tris = OUTPUT;
	row2_tris = OUTPUT;
	row3_tris = OUTPUT;
	row4_tris = OUTPUT;
	
	col1_tris = INPUT;
	col2_tris = INPUT;
	col3_tris = INPUT;
	
	while(1) {
		switch(state) {
			case(r1):
				row1_power = 1;
				row2_power = 0;
				row3_power = 0;
				row4_power = 0;
				if(wait == 0) {
					state = r2;
					delayUs(250);
				}
				break;
			case(r2):
				row1_power = 0;
				row2_power = 1;
				row3_power = 0;
				row4_power = 0;
				if(wait == 0) {
					state = r3;
					delayUs(250);
				}
				break;
			case(r3):
				row1_power = 0;
				row2_power = 0;
				row3_power = 1;
				row4_power = 0;
				if(wait == 0) {
					state = r4;
					delayUs(250);
				}
				break;
			case(r4):
				row1_power = 0;
				row2_power = 0;
				row3_power = 0;
				row4_power = 1;
				if(wait == 0) {
					state = r1;
					delayUs(250);
				}
				break;
		}
		if(out != n0) {
			switch(state) {
				case(r2):
			}
		}
	}
	return(0);
}

void __ISR(33,IPL4SRS) _CNInterrupt(void) {
	if(col1_read == 0 || col2_read == 0 || col3_read == 0) {
		if(wait == 0) {
			wait = 1;
			if(col1_read == 0) {
				curr = c1;
			}
			else if(col2_read == 0) {
				curr = c2;
			}
			else if(col3_read == 0) {
				curr = c3;
			}
		}
	}
	else if(col1_read == 1 || col2_read == 1 || col3_read == 1) {
		switch(curr) {
			case(c1):
				if(col1_read == 1) out = c1;
				else out = n0;
				break;
			case(c2):
				if(col2_read == 1) out = c2;
				else out = n0;
				break;
			case(c3):
				if(col3_read == 1) out = c3;
				else out = n0;
				break;
		}
		curr = n0;
		wait = 0;
	}
}

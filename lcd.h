/********************************
 * Ivan Cordoba
 * Nathaniel Christianson
 * Alex Levine
 * Jordan Jeffries
 * 
 * ECE 372A
 * LAB 2 PART 1
 *******************************/

#ifndef LCD_H
#define	LCD_H

void writeLCD(unsigned char word, unsigned int commandType, unsigned int delay);
void writeFourBits(unsigned char word, unsigned int commandType, unsigned int delayAfter, unsigned int lower);
void initLCD(void);
void clearLCD(void);
void moveCursorLCD(unsigned char x, unsigned char y);
void printCharLCD(char c);
void printStringLCD(const char* a);
void testLCD();

#endif
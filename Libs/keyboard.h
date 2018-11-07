#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "string.h"
#include "system.h"
#include "screen.h"

void readIn(string buffer)
{
	// char buffer[256];
	uint8 i = 0, l = 1;
	while (l)
	{
		if (inportb(0x64) & 0x1)
		{
			switch(inportb(0x60))
			{
				case 2:
					printChar('1');
					buffer[i] = '1';
					++i;
					break;
				case 3:
					printChar('2');
					buffer[i] = '2';
					++i;
					break;
				case 4:
					printChar('3');
					buffer[i] = '3';
					++i;
					break;
				case 5:
					printChar('4');
					buffer[i] = '4';
					++i;
					break;
				case 6:
					printChar('5');
					buffer[i] = '5';
					++i;
					break;
				case 7:
					printChar('6');
					buffer[i] = '6';
					++i;
					break;
				case 8:
					printChar('7');
					buffer[i] = '7';
					++i;
					break;
				case 9:
					printChar('8');
					buffer[i] = '8';
					++i;
					break;
				case 10:
					printChar('9');
					buffer[i] = '9';
					++i;
					break;
				case 11:
					printChar('0');
					buffer[i] = '0';
					++i;
					break;
				case 12:
					printChar('-');
					buffer[i] = '-';
					++i;
					break;
				case 13:
					printChar('=');
					buffer[i] = '=';
					++i;
					break;
				case 14:
					printChar(8);
					buffer[--i] = 0;
					break;
				case 15:
					printChar(9);
					// buffer[i] = '=';
					// ++i;
					break;
				case 16:
					printChar('q');
					buffer[i] = 'q';
					++i;
					break;
				case 17:
					printChar('w');
					buffer[i] = 'w';
					++i;
					break;
				case 18:
					printChar('e');
					buffer[i] = 'e';
					++i;
					break;
				case 19:
					printChar('r');
					buffer[i] = 'r';
					++i;
					break;
				case 20:
					printChar('t');
					buffer[i] = 't';
					++i;
					break;
				case 21:
					printChar('y');
					buffer[i] = 'y';
					++i;
					break;
				case 22:
					printChar('u');
					buffer[i] = 'u';
					++i;
					break;
				case 23:
					printChar('i');
					buffer[i] = 'i';
					++i;
					break;
				case 24:
					printChar('o');
					buffer[i] = 'o';
					++i;
					break;
				case 25:
					printChar('p');
					buffer[i] = 'p';
					++i;
					break;
				case 26:
					printChar('[');
					buffer[i] = '[';
					++i;
					break;
				case 27:
					printChar(']');
					buffer[i] = ']';
					++i;
					break;
				case 28:
					printChar('\n');
					l = 0;
					break;
				case 30:
					printChar('a');
					buffer[i] = 'a';
					++i;
					break;
				case 31:
					printChar('s');
					buffer[i] = 's';
					++i;
					break;
				case 32:
					printChar('d');
					buffer[i] = 'd';
					++i;
					break;
				case 33:
					printChar('f');
					buffer[i] = 'f';
					++i;
					break;
				case 34:
					printChar('g');
					buffer[i] = 'g';
					++i;
					break;
				case 35:
					printChar('h');
					buffer[i] = 'h';
					++i;
					break;
				case 36:
					printChar('j');
					buffer[i] = 'j';
					++i;
					break;
				case 37:
					printChar('k');
					buffer[i] = 'k';
					++i;
					break;
				case 38:
					printChar('l');
					buffer[i] = 'l';
					++i;
					break;
				case 39:
					printChar(';');
					buffer[i] = ';';
					++i;
					break;
				case 40:
					printChar('\'');
					buffer[i] = '\'';
					++i;
					break;
				case 41:
					printChar('`');
					buffer[i] = '`';
					++i;
					break;
				/*case 42:
					printChar('');
					buffer[i] = 'a'; left shift
					++i;
					break;*/
				case 43:
					printChar('\\');
					buffer[i] = '\\';
					++i;
					break;
				case 44:
					printChar('z');
					buffer[i] = 'z';
					++i;
					break;
				case 45:
					printChar('x');
					buffer[i] = 'x';
					++i;
					break;
				case 46:
					printChar('c');
					buffer[i] = 'c';
					++i;
					break;
				case 47:
					printChar('v');
					buffer[i] = 'v';
					++i;
					break;
				case 48:
					printChar('b');
					buffer[i] = 'b';
					++i;
					break;
				case 49:
					printChar('n');
					buffer[i] = 'n';
					++i;
					break;
				case 50:
					printChar('m');
					buffer[i] = 'm';
					++i;
					break;
				case 51:
					printChar(',');
					buffer[i] = ',';
					++i;
					break;
				case 52:
					printChar('.');
					buffer[i] = '.';
					++i;
					break;
				case 53:
					printChar('/');
					buffer[i] = '/';
					++i;
					break;
				case 57:
					printChar(' ');
					buffer[i] = ' ';
					++i;
					break;
				/*case 72:
					printChar(''); up key
					break;*/
				/*case 75:
					printChar(''); left key
					break;*/
				/*case 77:
					printChar(''); right key
					break;*/
				/*case 80:
					printChar(''); down key
					break;*/
				/*case 83:
					printChar(''); delete key
					break;*/
			}
		}
	}
	buffer[i] = 0;
	return;
}

#endif
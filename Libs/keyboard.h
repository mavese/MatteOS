#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "string.h"
#include "system.h"
#include "screen.h"

string readIn()
{
	string buffer;
	uint8 i = 0, l = 1;
	while (l)
	{
		if (inportb(0x64) & 0x1)
		{
			switch(inportb(0x60))
			{
				case 2:
					printchar('1');
					buffer[i] = '1';
					++i;
					break;
				case 3:
					printchar('2');
					buffer[i] = '2';
					++i;
					break;
				case 4:
					printchar('3');
					buffer[i] = '3';
					++i;
					break;
				case 5:
					printchar('4');
					buffer[i] = '4';
					++i;
					break;
				case 6:
					printchar('5');
					buffer[i] = '5';
					++i;
					break;
				case 7:
					printchar('6');
					buffer[i] = '6';
					++i;
					break;
				case 8:
					printchar('7');
					buffer[i] = '7';
					++i;
					break;
				case 9:
					printchar('8');
					buffer[i] = '8';
					++i;
					break;
				case 10:
					printchar('9');
					buffer[i] = '9';
					++i;
					break;
				case 11:
					printchar('0');
					buffer[i] = '0';
					++i;
					break;
				case 12:
					printchar('-');
					buffer[i] = '-';
					++i;
					break;
				case 13:
					printchar('=');
					buffer[i] = '=';
					++i;
					break;
				case 14:
					printchar(8);
					buffer[--i] = 0;
					break;
				case 15:
					printchar(9);
					// buffer[i] = '=';
					// ++i;
					break;
				case 16:
					printchar('q');
					buffer[i] = 'q';
					++i;
					break;
				case 17:
					printchar('w');
					buffer[i] = 'w';
					++i;
					break;
				case 18:
					printchar('e');
					buffer[i] = 'e';
					++i;
					break;
				case 19:
					printchar('r');
					buffer[i] = 'r';
					++i;
					break;
				case 20:
					printchar('t');
					buffer[i] = 't';
					++i;
					break;
				case 21:
					printchar('y');
					buffer[i] = 'y';
					++i;
					break;
				case 22:
					printchar('u');
					buffer[i] = 'u';
					++i;
					break;
				case 23:
					printchar('i');
					buffer[i] = 'i';
					++i;
					break;
				case 24:
					printchar('o');
					buffer[i] = 'o';
					++i;
					break;
				case 25:
					printchar('p');
					buffer[i] = 'p';
					++i;
					break;
				case 26:
					printchar('[');
					buffer[i] = '[';
					++i;
					break;
				case 27:
					printchar(']');
					buffer[i] = ']';
					++i;
					break;
				case 28:
					printchar('\n');
					l = 0;
					break;
				case 30:
					printchar('a');
					buffer[i] = 'a';
					++i;
					break;
				case 31:
					printchar('s');
					buffer[i] = 's';
					++i;
					break;
				case 32:
					printchar('d');
					buffer[i] = 'd';
					++i;
					break;
				case 33:
					printchar('f');
					buffer[i] = 'f';
					++i;
					break;
				case 34:
					printchar('g');
					buffer[i] = 'g';
					++i;
					break;
				case 35:
					printchar('h');
					buffer[i] = 'h';
					++i;
					break;
				case 36:
					printchar('j');
					buffer[i] = 'j';
					++i;
					break;
				case 37:
					printchar('k');
					buffer[i] = 'k';
					++i;
					break;
				case 38:
					printchar('l');
					buffer[i] = 'l';
					++i;
					break;
				case 39:
					printchar(';');
					buffer[i] = ';';
					++i;
					break;
				case 40:
					printchar('\'');
					buffer[i] = '\'';
					++i;
					break;
				case 41:
					printchar('`');
					buffer[i] = '`';
					++i;
					break;
				/*case 42:
					printchar('');
					buffer[i] = 'a'; left shift
					++i;
					break;*/
				case 43:
					printchar('\\');
					buffer[i] = '\\';
					++i;
					break;
				case 44:
					printchar('z');
					buffer[i] = 'z';
					++i;
					break;
				case 45:
					printchar('x');
					buffer[i] = 'x';
					++i;
					break;
				case 46:
					printchar('c');
					buffer[i] = 'c';
					++i;
					break;
				case 47:
					printchar('v');
					buffer[i] = 'v';
					++i;
					break;
				case 48:
					printchar('b');
					buffer[i] = 'b';
					++i;
					break;
				case 49:
					printchar('n');
					buffer[i] = 'n';
					++i;
					break;
				case 50:
					printchar('m');
					buffer[i] = 'm';
					++i;
					break;
				case 51:
					printchar(',');
					buffer[i] = ',';
					++i;
					break;
				case 52:
					printchar('.');
					buffer[i] = '.';
					++i;
					break;
				case 53:
					printchar('/');
					buffer[i] = '/';
					++i;
					break;
				case 57:
					printchar(' ');
					buffer[i] = ' ';
					++i;
					break;
				/*case 72:
					printchar(''); up key
					break;*/
				/*case 75:
					printchar(''); left key
					break;*/
				/*case 77:
					printchar(''); right key
					break;*/
				/*case 80:
					printchar(''); down key
					break;*/
				/*case 83:
					printchar(''); delete key
					break;*/
			}
		}
	}
	buffer[i] = 0;
	return buffer;
}

#endif
#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "string.h"
#include "system.h"

const uint8 screenWidth = 80, screenHeight = 25, screenDepth = 2;
uint8 cursorY = 0, cursorX = 0, color = 0x0f;

void updateCursor()
{
	uint16 pos = cursorY * screenWidth + cursorX;
 
	outportb(0x3D4, 0x0F);
	outportb(0x3D5, (uint8) (pos & 0xFF));
	outportb(0x3D4, 0x0E);
	outportb(0x3D5, (uint8) ((pos >> 8) & 0xFF));
	return;
}

void clearLines(uint8 _start, uint8 _end)
{
	uint16 i = _start * screenWidth * screenDepth;
	char *vidMemPointer = (char*) 0xb8000;
	uint16 final = (_end + 1) * screenWidth * 2;
	while (i < final)
	{
		vidMemPointer[i] = 0x0;
		i += 2;
	}
	return;
}

void clearScreen()
{
	clearLines(0,screenHeight-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
	return;
}

void scrollUp(uint8 _numLines)
{
	string vidMemPointer = (string) 0xb8000;
	for (uint16 i = 0; i < screenHeight * screenWidth * screenDepth; i += 2)
	{
		vidMemPointer[i] = vidMemPointer[i + _numLines * screenWidth * screenDepth];
		vidMemPointer[i + 1] = color;
	}
	cursorY -= _numLines;
	updateCursor();
	return;
}

// if the current text is going off the screen scroll up 1 line
void newLine()
{
	if (cursorY >= screenHeight)
	{
		scrollUp(1);
	}
}

void printChar(char ch)
{
	string vidMemPointer = (string) 0xb8000;
	switch(ch)
	{
		case 0x8:
			if (cursorX)
			{
				--cursorX;
				vidMemPointer[(cursorY * screenWidth * screenDepth) + (cursorX * screenDepth)] = 0x0;
			}
			break;
		case '\n':
			++cursorY;
			cursorX = 0;
			break;
		case '\r':
			cursorX = 0;
			break;
		default:
			vidMemPointer[(cursorY * (screenWidth * screenDepth)) + (cursorX * screenDepth)] = ch;
			vidMemPointer[(cursorY * (screenWidth * screenDepth)) + (cursorX * screenDepth + 1)] = color;
			++cursorX;
			break;
	}
	newLine();
	updateCursor();
	return;
}

void print(string _str)
{
	for (uint8 strPtr = 0; strPtr < len(_str); ++strPtr)
	{
		printChar(_str[strPtr]);
	}
	return;
}

void printLn(string _str)
{
	print(_str);
	printChar('\n');
	return;
}

void printInt(uint32 i)
{
	if (i > 0)
	{
		printInt(i/10);
		printChar((uint8)i%10+48);
	}
}

void printIntLn(uint32 i)
{
	printInt(i);
	printChar('\n');
}

void changeColor(uint8 _color)
{
	color = _color;
	return;
}

void enableCursor(uint8 cursor_start, uint8 cursor_end)
{
	outportb(0x3D4, 0x0A);
	outportb(0x3D5, (inportb(0x3D5) & 0xC0) | cursor_start);
 
	outportb(0x3D4, 0x0B);
	outportb(0x3D5, (inportb(0x3D5) & 0xE0) | cursor_end);
}

#endif
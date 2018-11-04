#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "string.h"
#include "system.h"

const uint8 screenWidth = 80, screenHeight = 25, screenDepth = 2;

void clearScreen()
{
	char* vidMemPointer = (char*) 0xb8000;
	unsigned short j = 0;

	while(j < screenWidth * screenHeight * screenDepth)
	{
		vidMemPointer[j] = 0x0;
		vidMemPointer[j+1] = 0x0;
		j += 2;
	}
}

void clearLines(uint8 _start, uint8 _end)
{
	uint16 i = _start * screenWidth * screenDepth;
	char *vidMemPointer = (char*) 0xb8000;
	uint16 final = (_end + 1) * screenWidth * 2;
	while (i < final)
	{
		vidMemPointer[i] = 0x0;
		++i;
	}
}

void print(string _str)
{
	uint8 strPtr = 0;
	char * vidMemPointer = (char *) 0xb8000;
	for (uint16 i = 0; strPtr < len(_str); i += 2, ++strPtr)
	{
		vidMemPointer[i] = _str[strPtr];
		vidMemPointer[i+1] = 0x0f;
	}
}

#endif
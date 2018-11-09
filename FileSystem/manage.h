#ifndef MANAGE_H
#define MANAGE_H

#include "string.h"

char files [5000];
uint16 topPntr = 0;

void newFile(string fname)
{
	uint8 length = len(fname);
	for (int i = 0; i < length; ++i)
	{
		files[topPntr++] = fname[i];
	}
	files[topPntr++] = 0;
	files[topPntr++] = 0;
}

uint16 findFile(string fname)
{
	uint16 i = 0;
	uint16 offset = 0;
	string name = "";
	while (!strCmp(fname, name))
	{
		name = "";
		while (files[offset + i])
		{
			name[i] = files[offset + i];
		}
		offset += i + 2;
		offset += files[offset];
		i = 0;
	}
	if (strCmp(fname, name))
	{
		return i + offset;
	}
	return -1;
}

#endif
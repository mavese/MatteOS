#ifndef STRING_H
#define STRING_H

#include "types.h"

// Count length of a string
uint16 len(string ch)
{
	uint16 l = 0;
	while(ch[l++]);
	return --l;
}

#endif
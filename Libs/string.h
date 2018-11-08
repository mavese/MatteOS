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

uint8 strCmp(string s1, string s2)
{
	uint8 result = 1;
	uint8 length = len(s1);
	if (length != len(s2))
	{
		result = 0;
	}
	else
	{
		for (uint8 i = 0; i < length; ++i)
		{
			if (s1[i] != s2[i])
			{
				result = 0;
				break;
			}
		}
	}
	return result;
}

int16 strContainsChar(string s, char c)
{
	int16 result = -1;
	for (uint8 i = 0; i < len(s); ++i)
	{
		if (s[i] == c)
		{
			result = i;
		}
	}
	return result;
}

#endif
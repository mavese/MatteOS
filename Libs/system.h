#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

// read data at specified port
uint8 inportb(uint16 _port)
{
	uint8 rval;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rval) : "dN" (_port));
	return rval;
}

// write data to a port
void outportb(uint16 _port, uint8 _val)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_val));
}

#endif
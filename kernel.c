#include "Libs/screen.h"
// #include "Libs/types.h"
#include <stdio.h>

void kmain()
{
	enableCursor(0,24);
	clearScreen();
	println("Welcome to MatteOS");
	print("\nThis operating system is currently under development");
	return;
}
// #include "Libs/screen.h"
#include "Libs/keyboard.h"

void kmain()
{
	enableCursor(0,24);
	clearScreen();
	printLn("Welcome to MatteOS");
	printLn("\nThis operating system is currently under development");
	while(1)
	{
		print("MatteOS/>");
		char s[256];
		readIn(s);
	}
	return;
}
#include "Libs/keyboard.h"
#include "Libs/commands.h"

void kmain()
{
	enableCursor(0,24);
	clearScreen();
	printLn("Welcome to MatteOS");
	printLn("\nThis operating system is currently under development");
	while(1)
	{
		print("MatteOS/>");
		string s;
		readIn(s);
		processCommand(s);
	}
	return;
}
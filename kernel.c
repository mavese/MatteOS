// #include "Libs/screen.h"
#include "Libs/keyboard.h"

void kmain()
{
	enableCursor(0,24);
	clearScreen();
	println("Welcome to MatteOS");
	println("\nThis operating system is currently under development");
	while(1)
	{
		print("MatteOS/>");
		string s = readIn();
		println(s);
	}
	return;
}
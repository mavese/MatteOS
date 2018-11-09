#ifndef COMMANDS_H
#define COMMANDS_H

#include "string.h"
#include "screen.h"

const uint8 NUMOFCOMMANDS = 2;
string commands [2] = {"clear", "help"};

int8 getCommand(string command)
{
	int8 i = -1;
	for (int8 j = 0; j < NUMOFCOMMANDS; ++j)
	{
		if (strCmp(command, commands[j]))
		{
			i = j;
			break;
		}
	}
	return i;
}

void clear()
{
	clearScreen();
}

void help()
{
	printLn("This is an opensource OS built by Matthew (Matteo) Mantese for the betterment of mankind.");
	printLn("The available commands are: clear, help");
}

void processCommand(string command)
{
	switch(getCommand(command))
	{
		case -1:
			printLn("This is not a supported command. Type help for options.");
			break;
		case 0:
			clear();
			break;
		case 1:
			help();
			break;
	}

}

#endif
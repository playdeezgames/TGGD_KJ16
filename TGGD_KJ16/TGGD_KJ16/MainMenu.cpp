#include "MainMenu.h"
#include "Terminal.h"

void MainMenu::Run()
{
	bool done = false;
	while (!done)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Main Menu:");
		Terminal::WriteLine("1) Quit");
		auto input = Terminal::ReadLine();
		if (input == "1")
		{
			done = true;
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input!");
		}
	}
}
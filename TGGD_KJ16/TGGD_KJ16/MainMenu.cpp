#include "MainMenu.h"
#include "ConfirmMenu.h"
#include "Terminal.h"
#include "Game.h"
#include "InPlay.h"

void MainMenu::Run()
{
	bool done = false;
	while (!done)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("The Spider Slaying and Prophesy Fulfilling Chosen One of SPLORR!!");
		Terminal::WriteLine();
		Terminal::WriteLine("Main Menu:");
		Terminal::WriteLine("1) Start");
		Terminal::WriteLine("0) Quit");
		auto input = Terminal::ReadLine();
		if (input == "0")
		{
			done = ConfirmMenu::Run("Are you sure you want to quit?");
		}
		else if (input == "1")
		{
			Game::Start();
			InPlay::Run();
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input!");
		}
	}
	Terminal::WriteLine();
	Terminal::WriteLine("Thanks for playing!");
}
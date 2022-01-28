#include "MainMenu.h"
#include "ConfirmQuit.h"
#include "Terminal.h"
#include "Game.h"
#include "InPlay.h"

void MainMenu::Run()
{
	bool done = false;
	while (!done)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Main Menu:");
		Terminal::WriteLine("1) Start");
		Terminal::WriteLine("0) Quit");
		auto input = Terminal::ReadLine();
		if (input == "0")
		{
			done = ConfirmQuit::Run();
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
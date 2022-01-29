#include "InPlay.h"
#include "Character.h"
#include "Terminal.h"
#include <format>
#include "ConfirmMenu.h"
#include "TurnMenu.h"
#include "MoveMenu.h"
void InPlay::Run()
{
	while (Character::IsAlive())
	{
		Terminal::WriteLine();
		Terminal::WriteLine(std::format("Location: ({}, {}) facing {}", Character::GetX(), Character::GetY(), (int)Character::GetFacing()));
		Terminal::WriteLine("1) Turn");
		Terminal::WriteLine("2) Move");
		Terminal::WriteLine("0) Abandon Game");
		auto input = Terminal::ReadLine();
		if (input == "0")
		{
			if (ConfirmMenu::Run("Are you sure you want to abandon this session?"))
			{
				return;
			}
		}
		else if (input == "1")
		{
			TurnMenu::Run();
		}
		else if (input == "2")
		{
			MoveMenu::Run();
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input.");
		}
	}
}
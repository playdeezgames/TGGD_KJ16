#include "InPlay.h"
#include "Character.h"
#include "Terminal.h"
#include <format>
#include "ConfirmMenu.h"
#include "TurnMenu.h"
#include "MoveMenu.h"
#include "School.h"
void InPlay::Run()
{
	while (Character::IsAlive())
	{
		Terminal::WriteLine();
		if (School::IsInside(Character::GetX(), Character::GetY()))
		{
			Terminal::WriteLine("You are inside the school.");
		}
		else
		{
			if (Character::GetX() < School::GetMinimumX())
			{
				Terminal::WriteLine("School is to the east.");
			}
			if (Character::GetX() > School::GetMaximumX())
			{
				Terminal::WriteLine("School is to the west.");
			}
			if (Character::GetY() < School::GetMinimumY())
			{
				Terminal::WriteLine("School is to the south.");
			}
			if (Character::GetY() > School::GetMaximumY())
			{
				Terminal::WriteLine("School is to the north.");
			}
		}
		switch (Character::GetFacing())
		{
		case Direction::NORTH:
			Terminal::WriteLine("You are facing north.");
			break;
		case Direction::EAST:
			Terminal::WriteLine("You are facing east.");
			break;
		case Direction::SOUTH:
			Terminal::WriteLine("You are facing south.");
			break;
		case Direction::WEST:
			Terminal::WriteLine("You are facing west.");
			break;
		}
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
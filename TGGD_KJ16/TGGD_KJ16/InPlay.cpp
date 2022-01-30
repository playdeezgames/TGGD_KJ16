#include "InPlay.h"
#include "Character.h"
#include "Terminal.h"
#include <format>
#include "ConfirmMenu.h"
#include "TurnMenu.h"
#include "MoveMenu.h"
#include "School.h"
#include "Prophecies.h"
#include "FulfillMenu.h"
#include "Spiders.h"
void InPlay::Run()
{
	while (Character::IsAlive() && !Prophecies::AreAllFulfilled())
	{
		Terminal::WriteLine();
		int x = Character::GetX();
		int y = Character::GetY();
		auto prophesyIndex = Prophecies::GetProphesy(x,y);
		if (School::IsInside(x,y))
		{
			Terminal::WriteLine("You are inside the school.");
			if (Spiders::Exists(x, y))
			{
				if (Spiders::IsAlive(x, y))
				{
					Terminal::WriteLine("There is a spider here! Kill it, quick!");
				}
				else
				{
					Terminal::WriteLine("There is a smushed spider here.");
				}
			}
			if (prophesyIndex && !Prophecies::IsFulfilled(*prophesyIndex))
			{
				Terminal::WriteLine("There is an unfulfilled prophecy here.");
			}
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
		if (prophesyIndex.has_value() && !Prophecies::IsFulfilled(*prophesyIndex))
		{
			Terminal::WriteLine("3) Attempt to fulfill prophecy!");
		}
		if (Spiders::IsAlive(x, y))
		{
			Terminal::WriteLine("4) Smush spider.");
		}
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
		else if (input == "3" && prophesyIndex.has_value() && !Prophecies::IsFulfilled(*prophesyIndex))
		{
			FulfillMenu::Run(*prophesyIndex);
		}
		else if (input == "4" && Spiders::IsAlive(x, y))
		{
			Terminal::WriteLine();
			Terminal::WriteLine("You smush the spider. My hero!");
			Spiders::Kill(x, y);
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input.");
		}
	}
	if (Prophecies::AreAllFulfilled())
	{
		Terminal::WriteLine();
		Terminal::WriteLine("You have fulfilled all of the prophesies, and have proven yerself to truly be the chosen one!");
	}
	else if (!Character::IsAlive())
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Yer dead. Game over.");
	}
}
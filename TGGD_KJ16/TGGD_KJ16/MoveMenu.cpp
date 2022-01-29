#include "MoveMenu.h"
#include "Terminal.h"
#include "Character.h"
void MoveMenu::Run()
{
	for (;;)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Move:");
		Terminal::WriteLine("1) Forward");
		Terminal::WriteLine("2) Left");
		Terminal::WriteLine("3) Right");
		Terminal::WriteLine("4) Back");
		Terminal::WriteLine("0) Never mind");
		auto input = Terminal::ReadLine();
		if (input == "1")
		{
			Terminal::WriteLine();
			Terminal::WriteLine("You move forward.");
			Character::Move(Move::FORWARD);
			return;
		}
		else if (input == "2")
		{
			Terminal::WriteLine();
			Terminal::WriteLine("You move left.");
			Character::Move(Move::LEFT);
			return;
		}
		else if (input == "3")
		{
			Terminal::WriteLine();
			Terminal::WriteLine("You move right.");
			Character::Move(Move::RIGHT);
			return;
		}
		else if (input == "4")
		{
			Terminal::WriteLine();
			Terminal::WriteLine("You move back.");
			Character::Move(Move::BACKWARD);
			return;
		}
		else if (input == "0")
		{
			return;
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input.");
		}
	}
}
#include "TurnMenu.h"
#include "Terminal.h"
#include "Character.h"
void TurnMenu::Run()
{
	for(;;)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Turn:");
		Terminal::WriteLine("1) Left");
		Terminal::WriteLine("2) Right");
		Terminal::WriteLine("3) Around");
		Terminal::WriteLine("0) Never mind");
		auto input = Terminal::ReadLine();
		if (input == "1")
		{
			Character::Turn(Turn::LEFT);
			Terminal::WriteLine();
			Terminal::WriteLine("You turn left");
			return;
		}
		else if (input == "2")
		{
			Character::Turn(Turn::RIGHT);
			Terminal::WriteLine();
			Terminal::WriteLine("You turn right");
			return;
		}
		else if (input == "3")
		{
			Character::Turn(Turn::AROUND);
			Terminal::WriteLine();
			Terminal::WriteLine("You turn around");
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
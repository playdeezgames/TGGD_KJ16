#include "InPlay.h"
#include "Character.h"
#include "Terminal.h"
#include <format>

void InPlay::Run()
{
	while (Character::IsAlive())
	{
		Terminal::WriteLine();
		Terminal::WriteLine(std::format("Location: ({}, {})", Character::GetX(), Character::GetY()));
		Terminal::WriteLine("0) Abandon Game");
		auto input = Terminal::ReadLine();
		if (input == "0")
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
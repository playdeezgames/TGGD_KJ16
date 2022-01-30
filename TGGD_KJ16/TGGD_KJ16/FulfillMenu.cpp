#include "FulfillMenu.h"
#include "Prophecies.h"
#include "Terminal.h"
#include "Character.h"
void FulfillMenu::Run(size_t index)
{
	Terminal::WriteLine();
	Terminal::WriteLine("To fulfill the prophecy, you must answer the following question:");
	Terminal::WriteLine(Prophecies::GetQuestion(index));
	auto answer = Terminal::ReadLine();
	if (answer == Prophecies::GetAnswer(index))
	{
		Prophecies::Fulfill(index);
		Terminal::WriteLine();
		Terminal::WriteLine("The prophecy is fulfilled!");
	}
	else
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Incorrect! Apparently you weren't the chosen one after all!");
		Character::Die();
	}
}
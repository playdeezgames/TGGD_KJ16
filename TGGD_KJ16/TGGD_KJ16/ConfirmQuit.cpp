#include "ConfirmQuit.h"
#include "Terminal.h"

bool ConfirmQuit::Run()
{
	for(;;)
	{
		Terminal::WriteLine();
		Terminal::WriteLine("Are you sure you want to quit?");
		Terminal::WriteLine("1) Yes");
		Terminal::WriteLine("0) No");
		auto input = Terminal::ReadLine();
		if (input == "0")
		{
			return false;
		}
		else if (input == "1")
		{
			return true;
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input.");
		}
	}
}
#include "ConfirmMenu.h"
#include "Terminal.h"

bool ConfirmMenu::Run(const std::string& prompt)
{
	for(;;)
	{
		Terminal::WriteLine();
		Terminal::WriteLine(prompt);
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
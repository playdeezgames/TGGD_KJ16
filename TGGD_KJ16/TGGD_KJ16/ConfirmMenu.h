#pragma once
#include <string>
struct ConfirmMenu
{
	ConfirmMenu() = delete;
	static bool Run(const std::string& prompt);
};

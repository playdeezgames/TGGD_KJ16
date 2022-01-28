#pragma once
#include <string>
struct Terminal
{
	Terminal() = delete;
	static void WriteLine(const std::string& text="");
	static std::string ReadLine();
};

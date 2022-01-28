#include "Terminal.h"
#include <stdio.h>

void Terminal::WriteLine(const std::string& text)
{
	puts(text.c_str());
}

static char line_buffer[256] = {};

std::string Terminal::ReadLine()
{
	gets_s(line_buffer, sizeof(line_buffer));
	return line_buffer;
}

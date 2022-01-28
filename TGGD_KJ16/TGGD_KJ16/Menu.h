#pragma once
#include <string>
#include <functional>
struct Menu
{
	Menu() = delete;
	static void Clear();
	static void Add(const std::string& text, std::function<void()> action);
	static void Prompt(std::function<void()> report);
};

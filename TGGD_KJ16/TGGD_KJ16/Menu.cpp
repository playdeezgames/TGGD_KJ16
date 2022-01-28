#include "Menu.h"
#include "Terminal.h"
#include <vector>
#include <map>
#include <format>
#include <algorithm>
#include <iterator>

struct MenuItem
{
	MenuItem(const std::string text, std::function<void()> action) 
		:text(text), 
		action(action) {}
	std::string text;
	std::function<void()> action;
};

static std::vector<MenuItem> menuItems{};

void Menu::Clear()
{
	menuItems.clear();
}

void Menu::Add(const std::string& text, std::function<void()> action)
{
	menuItems.emplace_back(text, action);
}

void Menu::Prompt(std::function<void()> report)
{
	std::map<std::string, std::function<void()>> commandMap{};
	std::vector<std::string> menu{};
	int index = 0;
	std::transform(
		menuItems.begin(),
		menuItems.end(),
		std::inserter(commandMap, commandMap.end()),
		[&index, &menu](const auto& menuItem)
		{
			++index;
			std::string commandText = std::format("{}", index);
			menu.push_back(std::format("{}) {}", commandText, menuItem.text));
			return std::make_pair(commandText, menuItem.action);
		});
	bool found = false;
	do
	{
		report();
		std::for_each(menu.begin(), menu.end(), Terminal::WriteLine);
		auto iter = commandMap.find(Terminal::ReadLine());
		if (iter != commandMap.end())
		{
			found = true;
			iter->second();
		}
		else
		{
			Terminal::WriteLine();
			Terminal::WriteLine("Invalid input.");
		}
	} while (!found);
}

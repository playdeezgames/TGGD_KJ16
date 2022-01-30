#include "Spiders.h"
#include "School.h"
#include <ranges>
#include <map>
#include <tuple>
#include <algorithm>
struct Spider
{
	int hp;
};
static std::map<std::tuple<int, int>, Spider> spiders{};
void Spiders::Start()
{
	spiders.clear();
	for (auto x : std::views::iota(School::GetMinimumX(), School::GetMaximumX() + 1))
	{
		for (auto y : std::views::iota(School::GetMinimumY(), School::GetMaximumY() + 1))
		{
			Spider spider = { 1 };
			spiders.emplace(std::make_tuple(x,y), spider);
		}
	}
}
bool Spiders::Exists(int x, int y)
{
	auto iter = 
		std::find_if(
			spiders.begin(), 
			spiders.end(), 
			[x,y](const auto& entry) 
			{
				return x == std::get<0>(entry.first) && y == std::get<1>(entry.first);
			});
	return iter != spiders.end();
}

bool Spiders::IsAlive(int x, int y)
{
	auto iter = spiders.find(std::make_tuple(x, y));
	if (iter != spiders.end())
	{
		return iter->second.hp > 0;
	}
	return false;
}

void Spiders::Kill(int x, int y)
{
	auto iter = spiders.find(std::make_tuple(x, y));
	if (iter != spiders.end())
	{
		iter->second.hp = 0;
	}
}

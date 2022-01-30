#include "Spiders.h"
#include "School.h"
#include <ranges>
#include <map>
#include <tuple>
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
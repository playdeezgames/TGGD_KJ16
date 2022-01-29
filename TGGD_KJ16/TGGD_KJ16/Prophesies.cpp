#include "Prophesies.h"
#include <string>
#include <vector>
#include "RNG.h"
#include "School.h"
#include <algorithm>
#include <format>
static constexpr size_t PROPHESY_COUNT = 7;

struct Prophesy
{
	Prophesy(int x, int y, const std::string question, const std::string answer, bool fulfilled)
		: x(x)
		, y(y)
		, question(question)
		, answer(answer)
		, fulfilled(fulfilled)
	{

	}
	int x;
	int y;
	std::string question;
	std::string answer;
	bool fulfilled;
};

static std::vector<Prophesy> prophesies;

void Prophesies::Start()
{
	prophesies.clear();
	while (prophesies.size() < PROPHESY_COUNT)
	{
		int x = RNG::FromRange(School::GetMinimumX(), School::GetMaximumX());
		int y = RNG::FromRange(School::GetMinimumY(), School::GetMaximumY());
		if (std::find_if(
			prophesies.begin(), 
			prophesies.end(), 
			[x,y](const auto& prophesy) 
			{
				return prophesy.x == x && prophesy.y == y;
			}) == prophesies.end())
		{
			auto first = RNG::FromRange(1000, 10000);
			auto second = RNG::FromRange(1000, 10000);
			prophesies.emplace_back(x, y, std::format("{} + {} = ?", first, second), std::format("{}", first + second), false);
		}
	}
}

std::optional<size_t> Prophesies::GetProphesy(int x, int y)
{
	auto iter = std::find_if(
		prophesies.begin(), 
		prophesies.end(), 
		[x,y](const auto& prophesy) 
		{
			return prophesy.x == x && prophesy.y == y;
		});
	if (iter != prophesies.end())
	{
		return iter - prophesies.begin();
	}
	return std::nullopt;
}

bool Prophesies::IsFulfilled(size_t index)
{
	return prophesies.at(index).fulfilled;
}

void Prophesies::Fulfill(size_t index)
{
	prophesies.at(index).fulfilled = true;
}

bool Prophesies::AreAllFulfilled()
{
	return std::all_of(
		prophesies.begin(), 
		prophesies.end(), 
		[](const auto& prophesy) 
		{
			return prophesy.fulfilled;
		});
}

std::string Prophesies::GetQuestion(size_t index)
{
	return prophesies.at(index).question;
}

std::string Prophesies::GetAnswer(size_t index)
{
	return prophesies.at(index).answer;
}

#pragma once
#include <optional>
#include <string>
struct Prophecies
{
	Prophecies() = delete;
	static void Start();
	static std::optional<size_t> GetProphesy(int x, int y);
	static bool IsFulfilled(size_t index);
	static void Fulfill(size_t index);
	static bool AreAllFulfilled();
	static std::string GetQuestion(size_t index);
	static std::string GetAnswer(size_t index);
};

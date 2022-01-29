#pragma once
struct RNG
{
	RNG() = delete;
	static int FromRange(int minimum, int maximum);
};

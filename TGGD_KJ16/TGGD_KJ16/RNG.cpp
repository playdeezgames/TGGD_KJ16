#include "RNG.h"
#include <random>

static std::random_device device;
static std::mt19937 random_engine(device());

int RNG::FromRange(int minimum, int maximum)
{
	auto dist = std::uniform_int_distribution<int>(minimum, maximum);
	return dist(random_engine);
}

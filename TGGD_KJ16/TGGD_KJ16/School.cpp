#include "School.h"
#include "RNG.h"

static int schoolX;
static int schoolY;

static constexpr int SCHOOL_WIDTH = 8;
static constexpr int SCHOOL_HEIGHT = 8;

void School::Start()
{
	schoolX = RNG::FromRange(-16, 16);
	schoolY = RNG::FromRange(-16, 16);
}

int School::GetMinimumX()
{
	return schoolX;
}

int School::GetMinimumY()
{
	return schoolY;
}

int School::GetMaximumX()
{
	return GetMinimumX() + SCHOOL_WIDTH - 1;
}

int School::GetMaximumY()
{
	return GetMinimumY() + SCHOOL_HEIGHT - 1;
}

bool School::IsInside(int x, int y)
{
	return x >= GetMinimumX() && x <= GetMaximumX() && y >= GetMinimumY() && y <= GetMaximumY();
}

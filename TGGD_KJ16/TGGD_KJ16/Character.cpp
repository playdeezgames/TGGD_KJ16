#include "Character.h"
#include "Direction.h"

static Direction characterFacing{};
static int characterX{};
static int characterY{};

void Character::Start()
{
	characterFacing = Direction::NORTH;
	characterX = 0;
	characterY = 0;
}

int Character::GetX()
{
	return characterX;
}

int Character::GetY()
{
	return characterY;
}

Direction Character::GetFacing()
{
	return characterFacing;
}

bool Character::IsAlive()
{
	return true;
}

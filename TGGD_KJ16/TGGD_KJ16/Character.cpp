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

static constexpr void TurnAround()
{
	characterFacing =
		(characterFacing == Direction::NORTH) ? (Direction::SOUTH) :
		(characterFacing == Direction::EAST) ? (Direction::WEST) :
		(characterFacing == Direction::SOUTH) ? (Direction::NORTH) :
		(Direction::EAST);
}

static constexpr void TurnLeft()
{
	characterFacing =
		(characterFacing == Direction::NORTH) ? (Direction::WEST) :
		(characterFacing == Direction::EAST) ? (Direction::NORTH) :
		(characterFacing == Direction::SOUTH) ? (Direction::EAST) :
		(Direction::SOUTH);
}

static constexpr void TurnRight()
{
	characterFacing =
		(characterFacing == Direction::NORTH) ? (Direction::EAST) :
		(characterFacing == Direction::EAST) ? (Direction::SOUTH) :
		(characterFacing == Direction::SOUTH) ? (Direction::WEST) :
		(Direction::NORTH);
}

void Character::Turn(::Turn turn)
{
	switch (turn)
	{
	case ::Turn::AROUND:
		TurnAround();
		break;
	case ::Turn::LEFT:
		TurnLeft();
		break;
	case ::Turn::RIGHT:
		TurnRight();
		break;
	}
}
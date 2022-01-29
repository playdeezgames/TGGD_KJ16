#include "Character.h"
#include "Direction.h"
#include "School.h"
#include "RNG.h"

static Direction characterFacing{};
static int characterX{};
static int characterY{};

void Character::Start()
{
	switch (RNG::FromRange(1, 5))
	{
	case 1:
		characterFacing = Direction::NORTH;
		break;
	case 2:
		characterFacing = Direction::EAST;
		break;
	case 3:
		characterFacing = Direction::SOUTH;
		break;
	case 4:
		characterFacing = Direction::WEST;
		break;
	}
	do
	{
		characterX = RNG::FromRange(-12, 12);
		characterY = RNG::FromRange(-12, 12);
	} while (School::IsInside(characterX, characterY));

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

void Character::Move(::Move move)
{
	auto oldFacing = characterFacing;
	switch (move)
	{
	case ::Move::LEFT:
		Turn(Turn::LEFT);
		break;
	case ::Move::RIGHT:
		Turn(Turn::RIGHT);
		break;
	case ::Move::BACKWARD:
		Turn(Turn::AROUND);
		break;
	}
	int deltaX =
		(characterFacing == Direction::EAST) ? (1) :
		(characterFacing == Direction::WEST) ? (-1) :
		(0);
	int deltaY =
		(characterFacing == Direction::SOUTH) ? (1) :
		(characterFacing == Direction::NORTH) ? (-1) :
		(0);
	characterFacing = oldFacing;
	characterX += deltaX;
	characterY += deltaY;
}
#pragma once
#include "Direction.h"
#include "Turn.h"
#include "Move.h"
struct Character
{
	Character() = delete;
	static void Start();
	static int GetX();
	static int GetY();
	static Direction GetFacing();
	static bool IsAlive();
	static void Turn(Turn turn);
	static void Move(Move move);
};

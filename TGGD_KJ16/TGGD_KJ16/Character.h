#pragma once
#include "Direction.h"
#include "Turn.h"
struct Character
{
	Character() = delete;
	static void Start();
	static int GetX();
	static int GetY();
	static Direction GetFacing();
	static bool IsAlive();
	static void Turn(::Turn turn);
};

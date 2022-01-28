#pragma once
#include "Direction.h"
struct Character
{
	Character() = delete;
	static void Start();
	static int GetX();
	static int GetY();
	static Direction GetFacing();
	static bool IsAlive();
};

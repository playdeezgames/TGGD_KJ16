#pragma once
struct School
{
	School() = delete;
	static void Start();
	static int GetMinimumX();
	static int GetMinimumY();
	static int GetMaximumX();
	static int GetMaximumY();
	static bool IsInside(int x, int y);
};

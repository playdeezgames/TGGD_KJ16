#pragma once
struct Spiders
{
	Spiders() = delete;
	static void Start();
	static bool Exists(int x, int y);
	static bool IsAlive(int x, int y);
	static void Kill(int x, int y);
};

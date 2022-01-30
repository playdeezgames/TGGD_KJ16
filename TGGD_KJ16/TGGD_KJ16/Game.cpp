#include "Game.h"
#include "Character.h"
#include "School.h"
#include "Prophecies.h"
void Game::Start()
{
	School::Start();
	Prophecies::Start();
	Character::Start();
}
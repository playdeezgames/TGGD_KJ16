#include "Game.h"
#include "Character.h"
#include "School.h"
void Game::Start()
{
	School::Start();
	Character::Start();
}
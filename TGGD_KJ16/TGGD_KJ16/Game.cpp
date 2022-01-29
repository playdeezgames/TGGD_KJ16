#include "Game.h"
#include "Character.h"
#include "School.h"
#include "Prophesies.h"
void Game::Start()
{
	School::Start();
	Prophesies::Start();
	Character::Start();
}
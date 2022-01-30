#include "Game.h"
#include "Character.h"
#include "School.h"
#include "Prophecies.h"
#include "Spiders.h"
void Game::Start()
{
	School::Start();
	Prophecies::Start();
	Spiders::Start();
	Character::Start();
}
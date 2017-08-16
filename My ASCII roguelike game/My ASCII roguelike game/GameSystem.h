#pragma once
#include"Player.h"
#include"Level.h"
#include<string>

using namespace std;

class GameSystem
{
	Player _player;
	Level _level;
	vector <Enemy> _enemies;

public:
	GameSystem(string LeveLFileName);

	void playGame();
	void playerMove();


};
#pragma once
#include<vector>
#include<string>

#include"Player.h"
#include"Enemy.h"
using namespace std;

class Level
{
	vector<string> _LevelData;
	vector<Enemy> _enemies;
	void processPlayerMove(Player &player,int targetX,int targetY);
	void battleMonster(Player &player, int targetX, int targetY);


public:  
	Level();
	 
	void Load(string fileName,Player&player);
	void print();

	void tryMovePlayer(char input,Player &player);
	void updateEnemies(Player &player);

	//타일얻고
	char getTile(int x, int y);
	//타일놓고
	void setTile(int x, int y, char tile);

};


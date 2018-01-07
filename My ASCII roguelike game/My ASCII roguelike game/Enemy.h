#pragma once
#include<string>
#include"Player.h"
using namespace std;

class Enemy
{
	int _level;
	int _attack;
	int _defense;
	int _health;
	int _experienceValue;

	string _name;
	char _tile;

	//위치
	int _x;
	int _y;

public:
	Enemy(string name,char tile,int level,int attack,int defense,int health,int xp);

	//셋함수
	void setPosition(int x, int y/*, int z*/);

	//겟함수
	void getPosition(int &x, int &y/*, int &z*/);

	int attack();
	int takeDamage(int attack);//데미지판정
	string getName() { return _name; }
	char getTile() { return _tile; }

	//AI 움직임 커맨드
	char getMove(int playerX,int playerY);


};
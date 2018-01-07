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

	//��ġ
	int _x;
	int _y;

public:
	Enemy(string name,char tile,int level,int attack,int defense,int health,int xp);

	//���Լ�
	void setPosition(int x, int y/*, int z*/);

	//���Լ�
	void getPosition(int &x, int &y/*, int &z*/);

	int attack();
	int takeDamage(int attack);//����������
	string getName() { return _name; }
	char getTile() { return _tile; }

	//AI ������ Ŀ�ǵ�
	char getMove(int playerX,int playerY);


};
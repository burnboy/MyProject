#pragma once

class Player
{
private:
	// 정보들
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;

	//위치정보
	int _x;
	int _y;
	//int _z;

public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	//셋함수
	void setPosition(int x, int y/*, int z*/);

	void addExperience(int experience);

	//겟함수
	void getPosition(int &x, int &y/*, int &z*/);
	
	int attack();
	int takeDamage(int attack);


};
#include"Enemy.h"
#include<random>
#include<ctime>

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;

}

void Enemy:: setPosition(int x, int y/*, int z*/)
{
	_x = x;
	_y = y;
}

void Enemy:: getPosition(int &x, int &y/*, int &z*/)
{
	x = _x;
	y = _y;

}

int Enemy::attack()
{
	static default_random_engine randomEngine((NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	//공격당했을때
	if (attack > 0) {
		_health -= attack;
		if (_health <= 0)
		{
			return _experienceValue;
		}

	
	}
	return 0;

}

char Enemy::getMove(int playerX, int playerY)
{
	int distance;//거리
	int dx = _x - playerX; //distance x
	int dy = _y - playerY; //distance y
	int adx = abs(dx);
	int ady = abs(dy);

	distance = adx + ady;

	if (distance <=5)
	{
		if (adx < ady)
		{
			if (dx > 0)
				return 'a';
			else
				return'd';
		}


		else {
			if (dy > 0)
				return 'w';
			else
				return 's';
		}

	}
}

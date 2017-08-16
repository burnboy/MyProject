#include"Player.h"
#include<random>
#include<ctime>
#include<iostream>
using namespace std;

Player::Player()
{
	_x = 0;
	_y = 0;
	//_z = 0;

}

void Player::init(int level, int health, int attack, int defense, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

int Player::attack()
{
	static default_random_engine randomEngine((NULL)); 
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
} 

void Player::setPosition(int x, int y/*, int z*/)
{
	_x = x;
	_y = y;
	/*_z = z;
*/
}

void Player::getPosition(int &x, int &y/*, int &z*/) 
{
	x = _x;
	y = _y;
	//z = _z;
}

int Player::takeDamage(int attack)
{
	attack -= _defense;
	//���ݴ�������
	if (attack > 0) {
		_health -= attack;

		//�÷��̾ ������
		if (_health <= 0)
		{
			return 1;
		}


	}
	return 0;

}


void Player::addExperience(int experience)
{
	_experience += experience;

	cout << "���� �ö����ϴ�/!!\n";
	while (_experience > 50)
	{
		_experience -= 50;
		_attack += 10;
		_defense += 5;
		_health += 10;
		_level += 1;

		system("PAUSE");
	}



}

#pragma once

class Player
{
private:
	// ������
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;

	//��ġ����
	int _x;
	int _y;
	//int _z;

public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	//���Լ�
	void setPosition(int x, int y/*, int z*/);

	void addExperience(int experience);

	//���Լ�
	void getPosition(int &x, int &y/*, int &z*/);
	
	int attack();
	int takeDamage(int attack);


};
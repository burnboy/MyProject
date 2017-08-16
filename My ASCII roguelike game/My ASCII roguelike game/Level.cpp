#include "Level.h"
#include<fstream>
#include<iostream>
#include<cstdio>

Level::Level()
{
}

void Level::Load(string fileName, Player&player)
{

	//���� ����
	ifstream file;

	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_LevelData.push_back(line);
	}

	file.close();
	//process the Level
	
	char tile;//Ÿ��

	for (int i = 0; i < _LevelData.size(); i++)//���� ����
	{
		for (int j = 0; j < _LevelData[i].size(); j++)//���� ����
		{
			tile = _LevelData[i][j];

			switch (tile)
			{
			case '@'://�÷��̾�
				player.setPosition(j,i);//��ġ
				break;
			case 'S'://�� 
				_enemies.push_back(Enemy("snake",tile,1,3,1,10,10));
				_enemies.back().setPosition(j, i);
				break;

			case 'G'://���
				_enemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 50));
				_enemies.back().setPosition(j, i);
				break;

			case 'O':
				_enemies.push_back(Enemy("Ogre", tile, 4, 20, 20, 200, 500));
				_enemies.back().setPosition(j, i);
				break;

			case 'D':
				_enemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000,2000, 500000));
				_enemies.back().setPosition(j, i);
				break;

			case 'B':
				_enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 150));
				_enemies.back().setPosition(j, i);
				break;
			}


		}
	}

}

void Level::print()
{
	cout << string(100, '\n');


	for (int i = 0; i < _LevelData.size(); i++)
	{
		printf("%s\n", _LevelData[i].c_str());//�̰� ������ �߸��ϸ� �ٶ����� ȭ���� �̻��ϰ� ���ü� �ִ�.
	}

	printf("\n");

}

void Level::tryMovePlayer(char input,Player &player)
{

	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);
	//char moveTile;

	switch (input){

	case 'w'://��
	case 'W':
		/*processPlayerMove(player, playerX, playerY - 1);
*/
	/*	moveTile = getTile(playerX, playerY - 1);*/

		processPlayerMove(player, playerX, playerY - 1);
		break;

	case 'a'://����
	case 'A':
		processPlayerMove(player, playerX-1, playerY);

		break;

	case's'://�Ʒ�
	case'S':
		processPlayerMove(player, playerX, playerY +1);

		break;

	case'd'://������
	case'D':
		processPlayerMove(player, playerX+1, playerY);

		break;

	default:
		cout << "invalid input" << endl;
		//system("PAUSE");
		break;
	}
}

void Level::updateEnemies(Player &player)
{
	for (int i = 0; i < _enemies.size();i++)
	{

	}
}


char Level::getTile(int x, int y)
{
	/*char tile = _LevelData[y][x];
	return tile;*/

	return _LevelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_LevelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetX, int targetY)
{
	//char moveTile;
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
	case '#':
		cout << "����� ������ �����ִ� \n";
		system("PAUSE");
		break;

	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');//�ָ��Ѱ�gettile�� �ٲ������ �ʳ�,.,
		break;

	//case'#':
	//	break;

	default:
		battleMonster(player, targetX, targetY);
		break;
	}

}
// ���� ������
void Level::battleMonster(Player &player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();

		if (targetX == enemyX&&targetY == enemyY)
		{
			//battle
			attackRoll = player.attack();
			printf("\n �÷��̾ ���� %s �� �����߽��ϴ�. %d�� ���ݷ�����\n",enemyName.c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				cout << "���Ͱ� �׾����ϴ�!\n";
				system("PAUSE");
				player.addExperience(attackResult);
	
				
				return;
			}

			//������ ��
			attackRoll = _enemies[i].attack();
			printf("����  %s �� �÷��̾ �����߽��ϴ�. %d�� ���ݷ�����\n", enemyName.c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {
				setTile(playerX, playerY,'X');
				print();
				cout << "���� �ֱ�!\n";
				system("PAUSE");
			
				exit(0);
			}
			system("PAUSE");
			return;
		}
	}
}
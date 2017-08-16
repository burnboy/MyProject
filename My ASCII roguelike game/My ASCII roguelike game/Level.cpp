#include "Level.h"
#include<fstream>
#include<iostream>
#include<cstdio>

Level::Level()
{
}

void Level::Load(string fileName, Player&player)
{

	//레벨 파일
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
	
	char tile;//타일

	for (int i = 0; i < _LevelData.size(); i++)//맵의 가로
	{
		for (int j = 0; j < _LevelData[i].size(); j++)//맵의 세로
		{
			tile = _LevelData[i][j];

			switch (tile)
			{
			case '@'://플레이어
				player.setPosition(j,i);//위치
				break;
			case 'S'://뱀 
				_enemies.push_back(Enemy("snake",tile,1,3,1,10,10));
				_enemies.back().setPosition(j, i);
				break;

			case 'G'://고블린
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
		printf("%s\n", _LevelData[i].c_str());//이거 설정을 잘못하면 줄때문에 화면이 이상하게 나올수 있다.
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

	case 'w'://위
	case 'W':
		/*processPlayerMove(player, playerX, playerY - 1);
*/
	/*	moveTile = getTile(playerX, playerY - 1);*/

		processPlayerMove(player, playerX, playerY - 1);
		break;

	case 'a'://왼쪽
	case 'A':
		processPlayerMove(player, playerX-1, playerY);

		break;

	case's'://아래
	case'S':
		processPlayerMove(player, playerX, playerY +1);

		break;

	case'd'://오른쪽
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
		cout << "당신은 벽으로 가고있다 \n";
		system("PAUSE");
		break;

	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');//애매한게gettile로 바꿔야하지 않나,.,
		break;

	//case'#':
	//	break;

	default:
		battleMonster(player, targetX, targetY);
		break;
	}

}
// 전투 구현부
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
			printf("\n 플레이어가 몬스터 %s 를 공격했습니다. %d의 공격력으로\n",enemyName.c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				cout << "몬스터가 죽었습니다!\n";
				system("PAUSE");
				player.addExperience(attackResult);
	
				
				return;
			}

			//몬스터의 턴
			attackRoll = _enemies[i].attack();
			printf("몬스터  %s 가 플레이어를 공격했습니다. %d의 공격력으로\n", enemyName.c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {
				setTile(playerX, playerY,'X');
				print();
				cout << "으앙 주금!\n";
				system("PAUSE");
			
				exit(0);
			}
			system("PAUSE");
			return;
		}
	}
}
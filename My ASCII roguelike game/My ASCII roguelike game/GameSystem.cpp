#include"GameSystem.h"
#include<iostream>
#include<conio.h>

//���� ����
GameSystem::GameSystem(string LeveLFileName)
{


	_player.init(1, 100, 10,10, 0);
	_level.Load(LeveLFileName,_player);


	system("PAUSE");
}


void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone != true) {
		_level.print();
		playerMove();

	}

}

void GameSystem::playerMove()
{
	char input;
	printf("�������� �Է��Ͻÿ�(wasd) :");
	input = _getch();

	_level.tryMovePlayer(input, _player);
}

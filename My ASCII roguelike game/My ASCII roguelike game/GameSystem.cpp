#include"GameSystem.h"
#include<iostream>
#include<conio.h>

//게임 설정
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
	printf("움직임을 입력하시오(wasd) :");
	input = _getch();

	_level.tryMovePlayer(input, _player);
}

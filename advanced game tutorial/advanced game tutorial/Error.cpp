#include "Error.h"


#include<iostream>
#include<SDL/SDL.h>

//�޽��� ���� ����
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "�ƹ�Ű�� ��������";
	int tmp;
	std::cin >> tmp;

	//	SDL_QUIT();
	exit(1);

}
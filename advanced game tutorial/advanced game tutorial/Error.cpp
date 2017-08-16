#include "Error.h"


#include<iostream>
#include<SDL/SDL.h>

//메시지 오류 보냄
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "아무키나 누르세요";
	int tmp;
	std::cin >> tmp;

	//	SDL_QUIT();
	exit(1);

}
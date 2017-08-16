//#include<Windows.h>
//#include<SDL/SDL.h>
//#include<GL/glew.h>
#include<iostream>
#include"MainGame.h"


using namespace std;

//세컨드 강의 들어야함
int main(int argc,char** argv)
{
	MainGame mainGame;
	mainGame.run();

	//cout << "나가려면 아무키나 누르세요" << endl;
	//int a;
	//cin >> a;

	return 0;

	//SDL_Init(SDL_INIT_EVERYTHING);
	//return 0;
}
//#include<Windows.h>
//#include<SDL/SDL.h>
//#include<GL/glew.h>
#include<iostream>
#include"MainGame.h"


using namespace std;

//������ ���� ������
int main(int argc,char** argv)
{
	MainGame mainGame;
	mainGame.run();

	//cout << "�������� �ƹ�Ű�� ��������" << endl;
	//int a;
	//cin >> a;

	return 0;

	//SDL_Init(SDL_INIT_EVERYTHING);
	//return 0;
}
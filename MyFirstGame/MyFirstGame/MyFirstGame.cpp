// RPGgame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include"Main.h"

int main(int argc, char *argv[])
{
	CMain *cmain=new CMain(1024,600);

	cmain->GameLoop();

	delete cmain;

	return 0;
}


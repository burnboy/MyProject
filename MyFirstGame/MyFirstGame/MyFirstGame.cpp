// RPGgame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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


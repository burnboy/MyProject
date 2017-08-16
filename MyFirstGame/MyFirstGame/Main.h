#pragma once
#include"SDL_setup.h"
#include"Sprite.h"
#include<math.h>
#include"MainCharacter.h"
#include"Environment.h"

class CMain
{
	float CameraX;
	float CameraY;

	MainCharacter *soldier;
	CEnvironment* ForestArea;


	int ScreenWidth;
	int ScreenHeight;

	bool quit;

	CSDL_setup* csdl_setup;

	//마우스로 움직이기
	int MouseX;
	int MouseY;

public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();

};


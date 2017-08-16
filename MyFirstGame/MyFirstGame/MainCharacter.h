#pragma once
#include"stdafx.h"
#include"Sprite.h"
#include"SDL_setup.h"
#include<math.h>


class MainCharacter
{
	int *MouseX;
	int *MouseY;

	float *CameraX;
	float *CameraY;

	CSprite* soldier;
	CSDL_setup *csdl_setup;
	
	int timeCheck;

	bool Follow;
	int Follow_Point_X;
	int Follow_Point_Y;

	float distance;
	bool stopAnimation;

	void UpdateAnimation();
	void UpdateControls();

public:
	MainCharacter(CSDL_setup *passed_SDL_Setup, int *passed_MouseX, int *passed_MouseY,float *passed_CameraX,float *passed_CameraY);
	~MainCharacter();

	double GetDistance(int X1, int Y1, int X2, int Y2);
	void Update();

	void Draw();


};


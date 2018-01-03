#pragma once
#include"stdafx.h"
#include"Sprite.h"
#include"SDL_setup.h"
#include"Environment.h"

#include<math.h>


class MainCharacter
{
	CEnvironment* Environment;
	void UpdateAnimation();
	void UpdateControls();

	float *CameraX;
	float *CameraY;

	int *MouseX;
	int *MouseY;

	CSDL_setup *csdl_setup;
	CSprite* soldier;

	int timeCheck;

	bool Follow;
	int Follow_Point_X;
	int Follow_Point_Y;

	float distance;
	bool stopAnimation;

public:
	MainCharacter(CSDL_setup* passed_SDL_Setup, int *passed_MouseX, int *passed_MouseY,float *CameraX,float *CameraY, CEnvironment*passed_Environment);
	~MainCharacter(void);

	double GetDistance(int X1, int Y1, int X2, int Y2);

	void Update();
	void Draw();
};


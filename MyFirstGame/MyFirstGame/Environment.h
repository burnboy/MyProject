#pragma once
#include"Sprite.h"
#include"stdafx.h"
#include"SDL_setup.h"
#include"Tree.h"
#include<vector>

class CEnvironment
{

	//SDL_Event* events;
	CSDL_setup* csdl_setup;
	float* CameraX;
	float* CameraY;

	//¿ÃπÃ¡ˆ
	CSprite* background[4][7];
	//Tree* tree;
	vector<Tree*>trees;

	bool OnePressed;
	int Mode;

public:
	CEnvironment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_setup* csdl_setup);
	~CEnvironment();

	void DrawBack();
	void DrawFront();
	void Update();

	enum ModeType
	{
		GamePlay,
	LevelCreation,


	};

};


#pragma once
#include"Sprite.h"
#include"stdafx.h"
#include"SDL_setup.h"
#include"Tree.h"
#include<vector>

class CEnvironment
{
	SDL_Event* events;
	//¿ÃπÃ¡ˆ
	CSprite* background[4][7];
	//Tree* tree;
	vector<Tree*>trees;


public:
	CEnvironment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_setup* csdl_setup);
	~CEnvironment();

	void DrawBack();
	void DrawFront();
	void Update();

};


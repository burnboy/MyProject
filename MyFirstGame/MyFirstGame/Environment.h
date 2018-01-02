#pragma once
#include"stdafx.h"
#include<vector>
#include"SDL_setup.h"
#include"Sprite.h"
#include"Tree.h"
#include<fstream>
#include<sstream>
#include<string>

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

	void SaveToFile();
	void LoadFromFile();

	enum ModeType
	{
		GamePlay,
	LevelCreation

	};

};


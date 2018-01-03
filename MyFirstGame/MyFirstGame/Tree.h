#pragma once
#include"stdafx.h"
#include"SDL_setup.h"
#include"Sprite.h"

class Tree
{
	int x, y;
	CSprite* Crown;
	CSprite* Trunk;

	float *CameraX;
	float *CameraY;

public:
	Tree(int x,int y,float *CameraX, float *CameraY, CSDL_setup* csdl_setup);
	~Tree(void);

	void DrawCrown();
	void DrawTrunk();

	int GetX();
	int GetY();

	CSprite* GetCrown(){ return Crown; }
	CSprite* GetTrunk(){ return Trunk; }

};



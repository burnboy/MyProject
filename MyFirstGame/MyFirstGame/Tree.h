#pragma once
#include"stdafx.h"
#include"SDL_setup.h"
#include"Sprite.h"

class Tree
{
	CSprite* Crown;
	CSprite* Trunk;

public:
	Tree(int x,int y,float *CameraX, float *CameraY, CSDL_setup* csdl_setup);
	~Tree();

	void DrawCrown();
	void DrawTrunk();

};



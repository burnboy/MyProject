#pragma once
#include "stdafx.h"

class CCollisionRectangle
{
	SDL_Rect CollisionRect;
	int OffsetX;
	int OffsetY;

public:
	CCollisionRectangle();
	CCollisionRectangle(int x,int y,int w,int h);
	~CCollisionRectangle(void);

	void SetRectangle(int x, int y, int w, int h);
	SDL_Rect GetRectangle() { return CollisionRect; }

	void SetX(int x) { CollisionRect.x = x + OffsetX; }
	void SetY(int y) { CollisionRect.y = y + OffsetY; }

};


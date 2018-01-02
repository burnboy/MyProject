#include "CollisionRectangle.h"


CCollisionRectangle::CCollisionRectangle()
{
	SetRectangle(0, 0, 0, 0);
}


CCollisionRectangle::CCollisionRectangle(int x, int y, int w, int h)
{
	SetRectangle( x,  y,  w,  h);
}


CCollisionRectangle::~CCollisionRectangle()
{
}

void CCollisionRectangle::SetRectangle(int x, int y, int w, int h)
{
	CollisionRect.x = x;
	CollisionRect.y = y;
	CollisionRect.w = w;
	CollisionRect.h = h;
}
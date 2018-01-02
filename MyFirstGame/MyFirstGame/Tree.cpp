#include "stdAfx.h"
#include "Tree.h"


Tree::Tree(int x_passed,int y_passed,float *CameraX, float *CameraY, CSDL_setup* csdl_setup)
{
	x = x_passed;
	y = y_passed;


	Trunk = new CSprite(csdl_setup->Getrenderer(), "data/environment/Trunk.png",x, y,64,64 ,CameraX, CameraY,CCollisionRectangle(0,0,64,64));
	Crown = new CSprite(csdl_setup->Getrenderer(), "data/environment/Crown.png", x - 75, y - 115, 64, 64, CameraX, CameraY, CCollisionRectangle(0, 0, 64, 64));

}


Tree::~Tree()
{
	delete Crown;
	delete Trunk;
}

int Tree::GetX()
{
	return x;
}

int Tree::GetY()
{
	return y;
}

void Tree::DrawCrown()
{
	Crown->Draw();
};

void Tree::DrawTrunk()
{
	Trunk->Draw();
};
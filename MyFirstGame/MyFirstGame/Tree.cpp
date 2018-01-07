#include "stdAfx.h"
#include "Tree.h"

Tree::Tree(int x_passed,int y_passed,float *passed_CameraX, float *passed_CameraY, CSDL_setup* csdl_setup)
{
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	x = x_passed;
	y = y_passed;

	Trunk = new CSprite(csdl_setup->Getrenderer(), "data/environment/Trunk.png",x, y,64,64 ,CameraX, CameraY,CCollisionRectangle(0,0,0,0));
	Crown = new CSprite(csdl_setup->Getrenderer(), "data/environment/Crown.png", x - 75, y - 115, 128, 128, CameraX, CameraY, CCollisionRectangle(0, 0, 0, 0));

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
	if (97 <= *CameraY + Trunk->GetPositionRect().y)
		Trunk->Draw();

	Crown->Draw();
}

void Tree::DrawTrunk()
{
	if(103 >= *CameraY+Trunk->GetPositionRect().y)
	Trunk->Draw();
}


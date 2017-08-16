#include "stdafx.h"
#include "Tree.h"


Tree::Tree(int x,int y,float *CameraX, float *CameraY, CSDL_setup* csdl_setup)
{
	Trunk = new CSprite(csdl_setup->Getrenderer(), "data/environment/Trunk.png",x, y,64,64 ,CameraX, CameraY);
	Crown = new CSprite(csdl_setup->Getrenderer(), "data/environment/Crown.png", x - 75, y - 115, 64, 64, CameraX, CameraY);

}


Tree::~Tree()
{
	delete Trunk;
	delete Crown;
}


void Tree::DrawCrown()
{
	Crown->Draw();
};

void Tree::DrawTrunk()
{
	Trunk->Draw();
};
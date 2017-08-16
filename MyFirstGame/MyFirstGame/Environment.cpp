#include "stdafx.h"
#include "Environment.h"


CEnvironment::CEnvironment(int ScreenWidth,int ScreenHeight,float *CameraX,float *CameraY, CSDL_setup*csdl_setup)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			background[i][j] = new CSprite(csdl_setup->Getrenderer(), "data/environment/background.png", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight, CameraX, CameraY);
		}
	}

	trees.push_back(new Tree(300, 300, CameraX, CameraY, csdl_setup));
	//trees[0];
	//trees[1];


	//tree = new Tree(300, 300, CameraX, CameraY, csdl_setup);
}


CEnvironment::~CEnvironment()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			delete background[i][j];
		}
	}
	trees.clear();

}


void CEnvironment::DrawBack()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			background[i][j]->Draw();
		}
	}
	for (vector<Tree*>::iterator i = trees.begin(); i != trees.end(); i++)
	{
		(*i)->DrawTrunk();
	}

}


void CEnvironment::DrawFront()
{
	for (vector<Tree*>::iterator i = trees.begin(); i != trees.end(); i++)
	{
		(*i)->DrawCrown();
	}
}



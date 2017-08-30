#include "stdafx.h"
#include "Environment.h"


CEnvironment::CEnvironment(int ScreenWidth,int ScreenHeight,float *passed_CameraX,float *passed_CameraY,CSDL_setup*passed_csdl_setup)
{

	csdl_setup = passed_csdl_setup;

	CameraX= passed_CameraX;
	CameraY= passed_CameraY;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			background[i][j] = new CSprite(csdl_setup->Getrenderer(), "data/environment/background.png", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight, CameraX, CameraY);
		}
	}
	//events = csdl_setup->GetMainEvent();

	//int* CameraX;
	//int* CameraY;


	OnePressed = false;

	//for(int i=0;i<100;i++)
	//trees.push_back(new Tree(300+(50*i), 300, CameraX, CameraY, csdl_setup));

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

	for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end(); ++i)
	{
		delete (*i);
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

void CEnvironment::Update()
{
	if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
	{
		if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
		{
	/*		std::cout << "ONE" << std::endl;*/
			trees.push_back(new Tree(-*CameraX+275, -*CameraY+90, CameraX, CameraY, csdl_setup));
			OnePressed = true;
		}
	}

	if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
	{
		if (OnePressed&&csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
		{
			OnePressed = false;
		};
	}



}


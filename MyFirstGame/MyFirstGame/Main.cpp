#include"Main.h"
#include"MainCharacter.h"
#include"stdafx.h"
//#include"SDL_setup.h"

using namespace std;

//26part 5:48

CMain::CMain(int passed_ScreenWidth,int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;

	quit = false;
	csdl_setup = new CSDL_setup(&quit, ScreenWidth, ScreenHeight);

	//카메라,시점부분
	CameraX = 300;
	CameraY = 250;


	ForestArea = new CEnvironment(ScreenWidth, ScreenHeight, &CameraX, &CameraY, csdl_setup);

	MouseX = 300;
	MouseY = 250;

	soldier = new MainCharacter(csdl_setup, &MouseX, &MouseY,&CameraX,&CameraY);
}

CMain::~CMain(void)
{
	delete csdl_setup;
	delete soldier;

}

void CMain::GameLoop(void)
{
	while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);
		
		ForestArea->DrawBack();
		soldier->Draw();

		soldier->Update();

		ForestArea->DrawFront();

		csdl_setup->End();
	/*	SDL_RenderPresent(csdl_setup->Getrenderer());*/
	}
}
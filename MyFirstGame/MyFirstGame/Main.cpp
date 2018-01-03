#include"stdAfx.h"
#include"Main.h"


CMain::CMain(int passed_ScreenWidth,int passed_ScreenHeight)
{
	//카메라,시점부분
	CameraX = 0;
	CameraY = 0;
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;
	csdl_setup = new CSDL_setup(&quit, ScreenWidth, ScreenHeight);

	ForestArea = new CEnvironment(ScreenWidth, ScreenHeight, &CameraX, &CameraY, csdl_setup);

	MouseX = 0;
	MouseY = 0;

	soldier = new MainCharacter(csdl_setup, &MouseX, &MouseY,&CameraX,&CameraY,ForestArea);
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
		ForestArea->Update();

		ForestArea->DrawFront();
		csdl_setup->End();
	/*	SDL_RenderPresent(csdl_setup->Getrenderer());*/
	}
}
#include "stdafx.h"
#include "SDL_setup.h"
using namespace std;

CSDL_setup::CSDL_setup(bool* quit,int ScreenWidth,int ScreenHeight)
{
	window = NULL;
	window = SDL_CreateWindow("first game", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);//ȭ��ũ��

	if (window == NULL)
	{
		cout << "������â�� ��������� �ʾ���" << endl;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent = new SDL_Event();
}


CSDL_setup::~CSDL_setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}
SDL_Renderer* CSDL_setup::Getrenderer()
{
	return renderer;

}

SDL_Event* CSDL_setup::GetMainEvent()
{
	return mainEvent;

}

void CSDL_setup::Begin()
{
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void CSDL_setup::End()
{
	SDL_RenderPresent(renderer);
}
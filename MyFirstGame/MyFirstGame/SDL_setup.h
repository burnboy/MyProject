#pragma once
#include"stdafx.h"
class CSDL_setup
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;


public:
	CSDL_setup(bool* quit, int ScreenWidth, int ScreenHeight);
	~CSDL_setup(void);

	SDL_Renderer* Getrenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();


};


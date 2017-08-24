#include "MainGame.h"
#include<iostream>
#include<string>

#include"Error.h"

//private 멤버 설정
MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{ 
	initSystems();
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	gameLoop();
}

void MainGame::initSystems()
{
	//SDL 초기내용 설정
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight,SDL_WINDOW_OPENGL);
		
	if (_window == nullptr)
	{
		fatalError("SDL윈도우가 만들어지지 않았습니다.");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		fatalError("SDL GL 컨텍스트가 만들어지지 않았습니다.");

	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("glew가 초기화 되지 않았습니다");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();
}

void MainGame::initShaders()
{
	_colorProgram.compileShaders("")

}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		ProcessInput();
		drawGame();
	}
}

void MainGame::ProcessInput()
{
	SDL_Event  evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
		std::cout << evnt.motion.x << ""<<evnt.motion.y <<std:: endl;
			break;

		}
	
	};
}

void MainGame::drawGame()
{
	glClearDepth(1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_sprite.draw();



	//opengl에서 컬러 사용
	//glEnableClientState(GL_COLOR_ARRAY);

	//삼각형 모드
	//glBegin(GL_TRIANGLES);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex2f(-1, -1);
	//glVertex2f(0, -1);
	///*glVertex2f(500, 0);*/
	//glVertex2f(0, 0);

	//glEnd();


	SDL_GL_SwapWindow(_window);

}
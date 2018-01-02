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
			background[i][j] = new CSprite(csdl_setup->Getrenderer(), "data/environment/background.png", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight, CameraX, CameraY,CCollisionRectangle());
		}
	}


	Mode = LevelCreation;

	//events = csdl_setup->GetMainEvent();
	//int* CameraX;
	//int* CameraY;

	LoadFromFile();

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
	for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end(); ++i)
	{
		(*i)->DrawCrown();
	}
}

void CEnvironment::LoadFromFile()
{

	std::ifstream LoadedFile("data/StageLayout.txt");

	std::string line;
	
	enum ObjectType
	{
		TypeNone,TypeTree

	};
	int CurrentType = TypeNone;


	if (LoadedFile.is_open())
	{
		while (LoadedFile.good())
		{
			std::getline(LoadedFile, line);
			if (line == "----======트리시작======-------")
			{
				CurrentType = TypeTree;
			}
			else if (line == "----======트리의끝======-------")
			{
				CurrentType = TypeNone;
			}
			else
			{
				if (CurrentType == TypeTree)

				{
					//std::cout << line << std::endl;		
					std::istringstream iss(line);

					int TempX = 0;
					int TempY = 0;
					std::string PreviousWord="";

					while (iss)
					{  
						std::string word;
						iss >> word;
						//std::cout << word << std::endl;
						if (PreviousWord == "X:")
						{
							TempX = atoi(word.c_str()  );
						}


						if (PreviousWord == "Y:")
						{
							TempY = atoi(word.c_str());
							trees.push_back(new Tree(TempX,TempY, CameraX, CameraY, csdl_setup));

						 /* std::cout << "X is " << TempX << std::endl;
							std::cout << "Y is " << TempY << std::endl;*/
						}


						PreviousWord = word;
					}
				}

			}
		}
	}
	else
	{
		std::cout << "파일이 열수가 없습니다.::StageLayout.txt" << std::endl;
	}

}

void CEnvironment::SaveToFile()
{
	std::ofstream LoadedFile;
	LoadedFile.open("data/stageLayout.txt");

	LoadedFile << "--------트리 시작--------" << std::endl;



	for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end();++i)
	{
		LoadedFile << "X:" <<(*i)->GetX()<<"\ty: "<<(*i)->GetY()<< std::endl;

	}
	//LoadedFile << "파일을 저장중입니다!" << std::endl;

	LoadedFile << "--------트리 끝----------" << std::endl;


	LoadedFile.close();

	std::cout << "레벨 저장됨!" << std::endl;
}

void CEnvironment::Update()
{
	if (Mode == LevelCreation)
	{
		if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11)
			{
				if (Mode == LevelCreation)
				{
					SaveToFile();
					OnePressed = true;
				}

			}

			if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
			{
				if (OnePressed&&csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F11)
				{
					OnePressed = false;
				};
			}

		///////////////////////////////////////////////////////////////////////////////
			if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
			{
				if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1)
				{
					/*		std::cout << "ONE" << std::endl;*/
					trees.push_back(new Tree(-*CameraX + 275, -*CameraY + 90, CameraX, CameraY, csdl_setup));
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

	   //////////////////////////////////////////////////////////////////

			if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
			{
				if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2)
				{
					if (trees.size() > 0)
					{
						int count = 0;


						for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end(); ++i)
						{
							if (count == trees.size())
								delete(*i);

								count++;
						}


						trees.pop_back();
						//delete trees[trees.size()];


					}
						OnePressed = true;
					

				}

			}

			if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
			{
				if (OnePressed&&csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F2)
				{
					OnePressed = false;
				};
			}


		}




		if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F12)
			{
				if (Mode == LevelCreation)
				{
					std::cout << "LevelCreation 끄기" << std::endl;
					Mode = GamePlay;
				}

				else if (Mode == GamePlay)
				{
					std::cout << "LevelCreation 킴" << std::endl;
					Mode = LevelCreation;
				}

				OnePressed = true;
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_KEYUP)
		{
			if (OnePressed&&csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F12)
			{
				OnePressed = false;
			};
		}



	}
}


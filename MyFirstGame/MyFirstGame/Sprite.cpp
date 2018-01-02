//#include"stdAfx.h"
#include "Sprite.h"
using namespace std;

CSprite::CSprite(SDL_Renderer*passed_renderer, string FilePath, int x, int y, int w, int h, float *passed_CameraX, float *passed_CameraY, CCollisionRectangle passed_CollisionRect)
{
	CollisionRect = passed_CollisionRect;
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer,FilePath.c_str());

	if (image == NULL)
	{
		cout << FilePath.c_str() << "파일을 로드할수 없습니다!" << endl;
	}

	CollisionImage = NULL;

	CollisionImage = IMG_LoadTexture(renderer,"data/Debug/CollisionBox.png");

	if (CollisionImage == NULL)
	{
		cout <<"CollisionImage"<< "파일을 로드할수 없습니다!" << endl;
	}



	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);

	crop.x = 0;
	crop.y = 0;
	crop.w = img_width;
	crop.h = img_height;

	X_pos = x;
	Y_pos = y;

	Origin_X = 0;
	Origin_Y = 0;

	CurrentFrame = 0;
	Amount_Frame_X = 0;
	Amount_Frame_Y = 0;

	CameraX = passed_CameraX;
	CameraY = passed_CameraY;


	/*soldier_image = NULL;
	soldier_image = IMG_LoadTexture(csdl_setup->Getrenderer(), "data/solpoFriends.png");

	if (soldier_image == NULL)
	{
		cout << " 솔포 프렌드 파일을 로드할수 없습니다!" << endl;
	}

	soldier_rect.x = 800;
	soldier_rect.y = 350;
	soldier_rect.w = 180;
	soldier_rect.h = 180;*/
}

void CSprite::SetUpAnimation(int passed_Amount_X, int passed_Amount_Y)
{
	Amount_Frame_X = passed_Amount_X;
	Amount_Frame_Y = passed_Amount_Y;
}

//애니메이션 출력
void CSprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed)
{

	if (animationDelay + Speed < SDL_GetTicks())
	{

		if (EndFrame <= CurrentFrame)
			CurrentFrame = BeginFrame;
		else
			CurrentFrame++;
		
		crop.x = CurrentFrame*(img_width / Amount_Frame_X);
		crop.y = Row*(img_height /Amount_Frame_Y);
		crop.w = img_width / Amount_Frame_X;
		crop.h = img_height / Amount_Frame_Y;
	
		animationDelay = SDL_GetTicks();
	}
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);
}


void CSprite::DrawSteady()
{
	SDL_RenderCopy(renderer, image, &crop, &rect);
}


void CSprite::Draw()
{
	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;

	//Camera.w = rect.w;
	//Camera.h = rect.h;

	SDL_RenderCopy(renderer,image, &crop, &Camera);

	SDL_RenderCopy(renderer, CollisionImage,NULL, &CollisionRect.GetRectangle());

}

void CSprite::SetX(float X)
{
	X_pos = X;

	rect.x = int(X_pos - Origin_X);
}

void CSprite::SetY(float Y)
{	
	Y_pos = Y;
	rect.y = int(Y_pos - Origin_Y);
}

void CSprite::SetPosition(float X, float Y)
{
	X_pos = X;
	Y_pos = Y;

	rect.x = int(X_pos - Origin_X);
	rect.y = int(Y_pos - Origin_Y);
}

float CSprite::GetX()
{
	return X_pos;
}

float CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrigin(float X, float Y)
{
	Origin_X = X;
	Origin_Y = Y;

	SetPosition(GetX(),GetY());

}

void CSprite::SetWidth(int W)
{
	rect.w = W;
}

void CSprite::SetHeight(int H)
{
	rect.h = H;
}

int CSprite::GetWidth()
{
	return rect.w;
}

int CSprite::GetHeight()
{
	return rect.h;
}



#pragma once
#include"stdafx.h"
#include"CollisionRectangle.h"
class CSprite
{
	CCollisionRectangle CollisionRect;


	//�̹���
	SDL_Rect Camera;

	SDL_Texture* image;
	SDL_Texture* CollisionImage;


	SDL_Rect rect;
	SDL_Renderer* renderer;

	float *CameraX;
	float *CameraY;

	float X_pos;
	float Y_pos;

	SDL_Rect crop;

	float Origin_X;
	float Origin_Y;

	int img_width;
	int img_height;

	int CurrentFrame;
	int animationDelay;

	int Amount_Frame_X;
	int Amount_Frame_Y;

public:

	CSprite(SDL_Renderer*passed_renderer,string FilePath, int x,int y,int w,int h,float *CameraX,float *CameraY,CCollisionRectangle passed_CollisionRect );
	~CSprite(void);

	void Draw();
	void DrawSteady();

	//��ġ ������ ������
	void SetX(float X);
	void SetY(float Y);
	void SetPosition(float X, float Y);

	float GetX();
	float GetY();

	int GetWidth();
	int GetHeight();
	void SetOrigin(float X, float Y);

	void SetWidth(int W);
	void SetHeight(int H);

	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);
	void SetUpAnimation(int passed_Amount_X, int passed_Amount_Y);
};


#pragma once
#include"stdafx.h"
#include"CollisionRectangle.h"

class CSprite
{
	CCollisionRectangle CollisionRect;

	//이미지
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

	CSprite(SDL_Renderer*passed_renderer,std::string FilePath, int x,int y,int w,int h,float *CameraX,float *CameraY,CCollisionRectangle passed_CollisionRect );
	~CSprite(void);

	void Draw();
	void DrawSteady();

	//위치 움직임 설정들
	void SetX(float X);
	void SetY(float Y);
	void SetPosition(float X, float Y);

	float GetX();
	float GetY();
	void SetWidth(int W);
	void SetHeight(int H);

	int GetWidth();
	int GetHeight();
	void SetOrigin(float X, float Y);
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);
	void SetUpAnimation(int passed_Amount_X, int passed_Amount_Y);

	bool isColliding(CCollisionRectangle theCollider);

	CCollisionRectangle GetCollisionRect() { return CollisionRect; }
	SDL_Rect GetPositionRect() { return rect; }

};


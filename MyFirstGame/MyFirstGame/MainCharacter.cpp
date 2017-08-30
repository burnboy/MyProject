//#include "stdafx.h"
#include "MainCharacter.h"


MainCharacter::MainCharacter(CSDL_setup*passed_SDL_Setup,int *passed_MouseX,int *passed_MouseY, float *passed_CameraX, float *passed_CameraY)
{
	CameraX =passed_CameraX;
	CameraY = passed_CameraY;

	csdl_setup = passed_SDL_Setup;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;

	//int TemporaryCamera = 0;

	soldier = new CSprite(csdl_setup->Getrenderer(), "data/solpoFriends.png", 300, 250, 120, 120, CameraX, CameraY);
	soldier->SetUpAnimation(4, 4);
	soldier->SetOrigin(soldier->GetWidth() / 2.0f, soldier->GetHeight());//중심 잡아주기

	timeCheck = SDL_GetTicks();

	Follow = false;
	distance = 0;
	stopAnimation = false;
}


MainCharacter::~MainCharacter()
{
	delete soldier;
}

void MainCharacter::Draw()
{
	soldier->DrawSteady();
}

void MainCharacter::UpdateAnimation()
{


	/*soldier->Draw();*/
	soldier->PlayAnimation(0, 3, 0, 200);//애니매이션 프레임 조정 

	float angle = atan2(Follow_Point_X - (double)*CameraX, Follow_Point_Y - (double)*CameraY);
	angle = (angle*(180 / 3.14)) + 180;

	if (!stopAnimation)
	{
		if (angle > 45 && angle <= 135)
		{
			//아래
			if (distance > 15)
				soldier->PlayAnimation(0, 3, 0, 200);
			else
				soldier->PlayAnimation(1, 1, 0, 200);

		}

		else if (angle > 135 && angle <= 225)
		{
			//왼쪽
			 if (distance > 15)
				soldier->PlayAnimation(0, 3, 1, 200);
			else
				soldier->PlayAnimation(1, 1, 1, 200);
		}

		else if (angle > 225 && angle <= 315)
		{
			//위
			if (distance > 15)
				soldier->PlayAnimation(0, 3, 3, 200);
			else
				soldier->PlayAnimation(1, 1, 3, 200);


		}

		else if ((angle <= 360 && angle <= 315) || (angle >= 0 && angle <= 45))
		{
			//오른쪽
			if (distance > 20)
				soldier->PlayAnimation(0, 3, 2, 200);
			else
				soldier->PlayAnimation(1, 1, 2, 200);
		}
	}



}

void MainCharacter::UpdateControls()
{
	if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			Follow_Point_X = *CameraX - *MouseX + 300; //*MouseX - *CameraX + 300;
			Follow_Point_Y = *CameraY - *MouseX + 250; //*mouseY-*cameraX+250;
			Follow = true;
		}
	}

	if (timeCheck + 10< SDL_GetTicks() && Follow)
	{

		distance = GetDistance(/*soldier->GetX()*/*CameraX, /*soldier->GetY()*/*CameraY, Follow_Point_X, Follow_Point_Y);

		if (distance == 0)

			stopAnimation = true;
		else
			stopAnimation = false;

		if (distance > 15)
		{
			if (/*soldier->GetX()*/*CameraX != Follow_Point_X)
			{
				/*soldier->SetX(soldier->GetX() - ((soldier->GetX() - Follow_Point_X) / distance)*1.5f);*/
				*CameraX = *CameraX - (((*CameraX - Follow_Point_X) / distance)*2.0f);
			}

			if (/*soldier->GetY()*/*CameraY != Follow_Point_Y)
			{
				/*soldier->SetY(soldier->GetY() - ((soldier->GetY() - Follow_Point_Y) / distance)*1.5f);*/
				*CameraY = *CameraY - (((*CameraY - Follow_Point_Y) / distance)*2.0f);
			}
		}
		else
			Follow = false;

		timeCheck = SDL_GetTicks();
	}
}

double MainCharacter::GetDistance(int X1, int Y1, int X2, int Y2)
{
	double DifferenceX = X1 - X2;
	double DifferenceY = Y1 - Y2;
	double distance = sqrt((DifferenceX*DifferenceX) + (DifferenceY*DifferenceY));

	return distance;

}

void MainCharacter::Update()
{

	UpdateAnimation();//애니메이션을 만들고
	UpdateControls();//움직임을 업뎃

}
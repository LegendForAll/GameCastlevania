#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"
#include "Goomba.h"
#define ID_TEX_MARIO 0

bool check = false;
LPANIMATION c = new CAnimation();

void CMario::LoadAnimation()
{
	//Load animation SIMON

	//Load texture of Animation SIMON


	//SM STAND STATIC

	//SM SIT

	//SM NOVE

	//SM JUMP

	//SM HURTED

	//SM THROW WEAPON

	//SM DEAD

	//SM INVISIBLE

	//SM EAT ITEM

	//SM FALL DOWN

	//SM STAND ATTACK

	//SM SIT ATTACK

	//SM STAND_UP_STAIR

	//SM STAND_DOWN_STAIR

	//SM ATTACK UP_STAIR

	//SM ATTACK DOWN_STAIR

	//SM MOVE UP_STAIR

	//SM MOVE DOWN_STAIR
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	//Render vs Collision
	CGameObject::Update(dt);

}

void CMario::Render()
{
	////do mo cua sprite
	int alpha = 255;
	//// xu ly ve lai mario mo di
	//if (untouchable) alpha = 128;
	//Using State Machine to render
	if (nx == 1)
	{
		animations[ani]->Render(x, y, alpha, true);
	}
	else
	{
		animations[ani]->Render(x, y, alpha, false);
	}



	

	//render truc tiep tu CGameObject
	//animations[0]->Render(x, y);
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		case SM_STAND_STATIC:
		{
			if (IsKeyDown(DIK_RIGHT))			//sm move right
			{
				this->state = SM_MOVE_LEFT;
				nx = 1;
				vx = SM_WALKING_SPEED;
				ani = SM_MOVE_LEFT;
				break;
			}
			else if (IsKeyDown(DIK_LEFT))		//sm move left
			{
				this->state = SM_MOVE_LEFT;
				nx = -1;
				vx = -SM_WALKING_SPEED;
				ani = SM_MOVE_LEFT;
				break;
			}
			else if (IsKeyDown(DIK_DOWN))		//sm sit
			{
				this->state = SM_SIT;
				vx = 0;
				ani = SM_SIT;
				break;
			}
			else if ((IsKeyPress(DIK_Z)) && isAttack == false)		//sm attack RIGHT/LEFT
			{
				this->isAttack = true;
				this->state = SM_STAND_ATTACK;
				vx = 0;
				ani = SM_STAND_ATTACK;
				break;
			}

			else if (IsKeyPress(DIK_SPACE)&& isGround && nx == 1 && isGround == true)
			{
				isGround = false;
				vy = -SM_JUMP_SPEED_Y;
				vx = 0;					//tam thoi = 0
				this->state = SM_JUMP;
				ani = SM_JUMP;
				break;
			}

		}

		case SM_MOVE_LEFT:
		{
			if (IsKeyRelease(DIK_RIGHT))		//sm stop move right
			{
				this->state = SM_STAND_STATIC;
				vx = 0;
				ani = SM_STAND_STATIC;
			}
			else if (IsKeyRelease(DIK_LEFT))	//sm stop move left
			{
				this->state = SM_STAND_STATIC;
				vx = 0;
				ani = SM_STAND_STATIC;
			}
			break;
		}

		case SM_SIT:
		{
			if (IsKeyRelease(DIK_DOWN))			//sm stop sit and stand
			{
				this->state = SM_STAND_STATIC;
				ani = SM_STAND_STATIC;
			}
			else if (IsKeyDown(DIK_RIGHT))		//sm sit right
			{
				nx = 1;
			}
			else if (IsKeyDown(DIK_LEFT))		//sm sit left
			{
				nx = -1;
			}
			break;
		}

		case SM_STAND_ATTACK:
		{
			if (animations[ani]->CheckDoAllFrame()) //finish attack
			{
				animations[ani]->SetDoAllFrame(false);
				this->state = SM_STAND_STATIC;
				ani = SM_STAND_STATIC;
				isAttack = false;
				break;
			}
			
		}

		case SM_JUMP:
		{
			if (animations[ani]->CheckDoAllFrame())
			{
				animations[ani]->SetDoAllFrame(false);
				isGround = true;
				break;
			}
		}
	}
	
}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y; 
	right = x + SM_BBOX_WIDTH;
	bottom = y + SM_BBOX_HEIGHT;
}

void CMario::CheckKey()
{
	////Get Status keyboard;
	//if (IsKeyDown(DIK_LEFT))
	//	state = SM_MOVE_LEFT;
}

void CMario::KeyEventHandler()
{
	this->SetState(this->state);
}



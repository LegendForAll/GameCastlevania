#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#define ID_TEX_MARIO 0

void CMario::LoadResource()
{
	
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	//Render vs Collision
}

void CMario::Render()
{
	//Using State Machine to render
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		//State machines
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
	//Get Status keyboard;
}


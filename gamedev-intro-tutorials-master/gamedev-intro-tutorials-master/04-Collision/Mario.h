#pragma once
#include "GameObject.h"

#define SM_WALKING_SPEED		0.1f 
//0.1f
#define SM_JUMP_SPEED_Y			0.5f
#define SM_JUMP_DEFLECT_SPEED	0.2f
#define SM_GRAVITY				0.002f

#define SM_NOMAL				1

#define SM_BBOX_WIDTH			15
#define SM_BBOX_HEIGHT			27



class CMario : public CGameObject
{
	int level;
	int untouchable;
	DWORD untouchable_start;

	//Current Animation
	int ani = SM_STAND_STATIC;

	//Flags
	bool isAttack = false;
	bool isGround = true;

	//LPDIRECT3DTEXTURE9 texture;		//texture SIMON
	//CSprites * sprites;				//Manager sprite SIMON
	//CAnimations * animation;		//Manager animation SIMON

public: 
	CMario() : CGameObject()
	{
		level = SM_NOMAL;
		untouchable = 0;
	}

	void LoadAnimation();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckKey();
	void KeyEventHandler();
};
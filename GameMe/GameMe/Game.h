#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Input.h"
#include "SoundManager.h"
using namespace std;

class CGame
{
	//state Enum

	static CGame * __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	//Lists sprite
	/*List<Asteroid> listAsteroid = new List<Asteroid>();*/	

public:

	void Game_Init(HWND hWnd);
	void Game_Run();
	void Game_End();

	//Load LoadContent Image, Sound
	//protected override void LoadContent(){}
	void LoadContent();

	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	static CGame * GetInstance();

	~CGame();

	//SpriteBatch spriteBatch;

	//Lists
	/*List<Asteroid> listAsteroid = new List<Asteroid>();*/

	//public Game1()
	//{
	//	constructor
	//}

	//Init()




	//Update
	//protected override void Update(GameTime gameTime){}

	//draw
	//protected override void Draw(GameTime gameTime){}
};

#pragma once
#include <d3dx9.h>
#include <string>
using namespace std;
#include "ViewPort.h"

class Sprite
{
private:

	// Sprite helper library to help us draw 2D image on the screen 
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE spriteHandle;

	D3DCOLOR color;				// color sprite
	D3DXVECTOR3 position;		// position of sprite
	float width, height;		// width, height of sprite
	bool Initialized;				// check sprite initialized 

	// Load texture
	LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, string file);
	LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, string file, int width, int height);

public:

	//Constructor
	Sprite();
	Sprite(float x, float y);
	~Sprite();

	//Initialize
	bool Initialize(LPDIRECT3DDEVICE9 device, string file);
	bool Initialize(LPDIRECT3DDEVICE9 device, string file, int width, int height);
	bool IsInitialized();

	//Render sprite, FULL
	void Render(CViewPort *viewPort);				// Object follow Viewport (Door,...)									
	void Render(D3DXVECTOR3 pos, RECT rect);		// Object full texture (User Interface, TileMap,...)
	//Render 1 Frame
	void Render(RECT rect, bool isLeft, int width, int height, CViewPort *viewPort);	//Render Animation object
	void Render(D3DXVECTOR3 position, D3DCOLOR color, CViewPort *viewPort);				//Render Ground
	void Render(D3DXVECTOR3 position);													//Render UI

	//Get, Set
	void SetColorAnimation(D3DCOLOR color)	{ this->color = color; } 
	void SetColor(D3DCOLOR color)			{ this->color = color; } // set color (Game object, tileMap,...)
	void SetPosition(float x, float y)		{ position.x = x; position.y = y; };
	void SetPosition(D3DXVECTOR3 position)	{ this->position = position; };

	float GetWidth()			{ return width; };
	float GetHeight()			{ return height; };
	D3DXVECTOR3 GetPosition()	{ return position; };

};
#pragma once
#include <d3dx9.h>

class CViewPort
{
private:

	D3DXVECTOR3 cameraPosition;		// camera position
	RECT *region;					// screen camera

public:

	CViewPort(float x, float y);
	~CViewPort();

	//Change World(position) to ViewPort(position)
	D3DXVECTOR3 SetPositionInViewPort(D3DXVECTOR3 position);

	//Set position of camera in world (move camera)
	void SetPositionCamera(float x, float y);

	//Get position of camera in World
	D3DXVECTOR3 GetPositionCamera();
};
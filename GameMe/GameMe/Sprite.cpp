#include "Sprite.h"

Sprite::Sprite()
{
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Initialized = false;
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	spriteHandle = NULL;
	texture = NULL;
}

Sprite::Sprite(float x, float y)
{
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Initialized = false;
	position.x = x;
	position.y = y;
	position.z = 0;
	spriteHandle = NULL;
	texture = NULL;
}

Sprite::~Sprite()
{
	if (spriteHandle)
	{
		spriteHandle->Release();
		spriteHandle = 0;
	}

	if (texture)
	{
		texture->Release();
		texture = 0;
	}
}

bool Sprite::Initialize(LPDIRECT3DDEVICE9 device, string file)
{

	if (LoadTexture(device, file) == NULL)
	{
		OutputDebugString(L"[ERROR] file error\n");
		return Initialized;
	}

	HRESULT result;

	//create sprite
	result = D3DXCreateSprite(device, &spriteHandle);
	if (FAILED(result))
	{
		OutputDebugString(L"[ERROR] Error creating Direct 3D sprite\n");
		return Initialized;
	}

	Initialized = true;
	return Initialized;
}

bool Sprite::Initialize(LPDIRECT3DDEVICE9 device, string file, int width, int height)
{

	if (LoadTexture(device, file, width, height) == NULL)
	{
		OutputDebugString(L"[ERROR] file error\n");
		return Initialized;
	}

	HRESULT result;

	//create sprite
	result = D3DXCreateSprite(device, &spriteHandle);
	if (FAILED(result))
	{
		OutputDebugString(L"[ERROR] Error creating Direct 3D sprite\n");
		return Initialized;
	}

	Initialized = true;
	return Initialized;
}

bool Sprite::IsInitialized()
{
	return Initialized;;
}

//load Texture
LPDIRECT3DTEXTURE9 Sprite::LoadTexture(LPDIRECT3DDEVICE9 device, string file)
{
	D3DXIMAGE_INFO info;
	HRESULT result;
	//attempt to load the wave file
	char s[255];
	sprintf_s(s, "%s", file.c_str());

#if UNICODE
	wstring str = wstring(file.begin(), file.end());

#else
	string str = to_string(var);

#endif // UNICOE
	result = D3DXGetImageInfoFromFile((LPCWSTR)str.c_str(), &info);
	if (result != D3D_OK)
	{
		return NULL;
	}

	width = info.Width;
	height = info.Height;

	//create texture
	result = D3DXCreateTextureFromFileEx(
		device,
		(LPCWSTR)str.c_str(),				//pSrcFile
		info.Width,
		info.Height,
		1,									//Mipmap levels
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),			//Transparent color
		&info,								//Image infomation
		NULL,
		&texture							//result
	);

	if (FAILED(result))
		return NULL;
	return texture;
}

LPDIRECT3DTEXTURE9 Sprite::LoadTexture(LPDIRECT3DDEVICE9 device, string file, int width, int height)
{
	HRESULT result;
	this->width = width;
	this->height = height;

	//attempt to load the wave file
	char s[255];
	sprintf_s(s, "%s", file.c_str());

#if UNICODE
	wstring str = wstring(file.begin(), file.end());

#else
	string str = to_string(var);

#endif // UNICOE
	//create texture
	result = D3DXCreateTextureFromFileEx(
		device,
		(LPCWSTR)str.c_str(),				//pSrcFile
		width,
		height,
		1,									//Mipmap levels
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),			//Transparent color
		NULL,
		NULL,
		&texture
	);

	if (FAILED(result))
		return NULL;

	return texture;
}

//Render FULL 
void Sprite::Render(CViewPort *viewPort)
{
	if (spriteHandle && texture)
	{
		spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandle->Draw(texture, NULL, NULL, &viewPort->SetPositionInViewPort(position), color);

		spriteHandle->End();
	}
}

void Sprite::Render(D3DXVECTOR3 pos, RECT rect)
{
	if (spriteHandle && texture)
	{
		spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandle->Draw(texture, &rect, NULL, &pos, color);

		spriteHandle->End();
	}
}

//Render 1 Frame
void Sprite::Render(RECT rect, bool isLeft, int width, int height, CViewPort *viewPort)
{
	if (spriteHandle && texture)
	{
		D3DXVECTOR3 pos = viewPort->SetPositionInViewPort(position);
		D3DXMATRIX oldTransform;
		spriteHandle->GetTransform(&oldTransform);

		D3DXMATRIX newTransform;
		D3DXVECTOR2 center = D3DXVECTOR2(pos.x + width / 2, pos.y + height / 2);
		D3DXVECTOR2 rotate = D3DXVECTOR2(isLeft ? 1 : -1, 1);

		D3DXMatrixTransformation2D(&newTransform, &center, 0.0f, &rotate, NULL, 0.0f, NULL);

		D3DXMATRIX finalTransform = newTransform * oldTransform;
		spriteHandle->SetTransform(&finalTransform);

		spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandle->Draw(texture, &rect, NULL, &pos, color);

		spriteHandle->End();

		spriteHandle->SetTransform(&oldTransform);
	}
}

void Sprite::Render(D3DXVECTOR3 position, D3DCOLOR color, CViewPort *viewPort)
{
	if (spriteHandle && texture)
	{
		spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);
		spriteHandle->Draw(texture, NULL, NULL, &viewPort->SetPositionInViewPort(position), color);
		spriteHandle->End();
	}

}

void Sprite::Render(D3DXVECTOR3 pos)
{
	if (spriteHandle && texture)
	{
		spriteHandle->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandle->Draw(texture, NULL, NULL, &pos, color);

		spriteHandle->End();
	}
}
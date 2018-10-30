//#include "MyDirectX.h"
//
////Direct3D variables
//LPDIRECT3D9 d3d = NULL;
//LPDIRECT3DDEVICE9 d3ddev = NULL;
//LPDIRECT3DSURFACE9 backbuffer = NULL;
//
////DirectInput variables
//LPDIRECTINPUT8 dinput = NULL;
//LPDIRECTINPUTDEVICE8 dikeyboard = NULL;
//char keys[256];
//XINPUT_GAMEPAD controllers[4];
//
//bool Direct3D_Init(HWND  window, int width, int height, bool fullscreen)
//{
//	//initialize Direct3D
//	d3d = Direct3DCreate9(D3D_SDK_VERSION);
//	if (!d3d) return false;
//	//set Direct3D presentation parameters
//	D3DPRESENT_PARAMETERS d3dpp;
//	ZeroMemory(&d3dpp, sizeof(d3dpp));
//	d3dpp.Windowed = (!fullscreen);
//	d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
//	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
//	d3dpp.BackBufferCount = 1;
//	d3dpp.BackBufferWidth = width;
//	d3dpp.BackBufferHeight = height;
//	d3dpp.hDeviceWindow = window;
//	//create Direct3D device
//	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
//		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
//	if (!d3ddev) return false;
//	//get a pointer to the back buffer surface
//	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
//	return true;//
//}
//
//// Direct3D shutdown
//void Direct3D_Shutdown()
//{
//	if (d3ddev) d3ddev->Release();
//	if (d3d) d3d->Release();
//}
//
//LPDIRECT3DSURFACE9 LoadSurface(string filename)
//{
//	LPDIRECT3DSURFACE9 image = NULL;
//	//get width and height from bitmap file
//	D3DXIMAGE_INFO info;
//	HRESULT result = D3DXGetImageInfoFromFile(filename.c_str(), &info);
//	if (result != D3D_OK) return NULL;
//	//create surface
//	result = d3ddev->CreateOffscreenPlainSurface(
//		info.Width, //width of the surface
//		info.Height, //height of the surface
//		D3DFMT_X8R8G8B8, //surface format
//		D3DPOOL_DEFAULT, //memory pool to use
//		&image, //pointer to the surface
//		NULL); //reserved (always NULL)
//	if (result != D3D_OK) return NULL;
//	//load surface from file into newly created surface
//	result = D3DXLoadSurfaceFromFile(
//		image, //destination surface
//		NULL, //destination palette
//		NULL, //destination rectangle
//		filename.c_str(), //source filename
//		NULL, //source rectangle
//		D3DX_DEFAULT, //controls how image is filtered
//		D3DCOLOR_XRGB(0, 0, 0), //for transparency (0 for none)
//		NULL); //source image info (usually NULL)
//		//make sure file was loaded okay
//	if (result != D3D_OK) return NULL;
//	return image;
//}
//
//// Draws a surface to the screen using StretchRect
//void DrawSurface(LPDIRECT3DSURFACE9 dest, float x, float y, LPDIRECT3DSURFACE9 source)
//{
//	//get width/height from source surface
//	D3DSURFACE_DESC desc;
//	source->GetDesc(&desc);
//	//create rects for drawing
//	RECT source_rect = { 0, 0,
//	(long)desc.Width, (long)desc.Height };
//	RECT dest_rect = { (long)x, (long)y,
//	(long)x + desc.Width, (long)y + desc.Height };
//	//draw the source surface onto the dest
//	d3ddev->StretchRect(source, &source_rect, dest,
//		&dest_rect, D3DTEXF_NONE);
//}
//
//bool DirectInput_Init(HWND hwnd)
//{
//	//initialize DirectInput object
//	HRESULT result = DirectInput8Create(
//		GetModuleHandle(NULL),
//		DIRECTINPUT_VERSION,
//		IID_IDirectInput8,
//		(void**)&dinput,
//		NULL);
//	//initialize the keyboard
//	dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL);
//	dikeyboard->SetDataFormat(&c_dfDIKeyboard);
//	dikeyboard->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
//	//status access keyboard
//	dikeyboard->Acquire();
//
//	d3ddev->ShowCursor(false);
//	return true;
//}
//
//void DirectInput_Update()
//{
//	//update keyboard
//	dikeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
//	//update controllers
//	for (int i = 0; i < 4; i++)
//	{
//		ZeroMemory(&controllers[i], sizeof(XINPUT_STATE));
//		//get the state of the controller
//		XINPUT_STATE state;
//		DWORD result = XInputGetState(i, &state);
//		//store state in global controllers array
//		if (result == 0) controllers[i] = state.Gamepad;
//	}
//}
//
//void DirectInput_Shutdown()
//{
//	if (dikeyboard)
//	{
//		dikeyboard->Unacquire();
//		dikeyboard->Release();
//		dikeyboard = NULL;
//	}
//
//}
//
//// Return key press state
//int Key_Down(int key)
//{
//	return (keys[key] & 0x80);
//}
//
//
//// Vibrates the controller
//void XInput_Vibrate(int contNum, int amount)
//{
//	XINPUT_VIBRATION vibration;
//	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
//	vibration.wLeftMotorSpeed = amount;
//	vibration.wRightMotorSpeed = amount;
//	XInputSetState(contNum, &vibration);
//}
//
//// Returns true if controller is plugged in
//bool XInput_Controller_Found()
//{
//	XINPUT_CAPABILITIES caps;
//	ZeroMemory(&caps, sizeof(XINPUT_CAPABILITIES));
//	XInputGetCapabilities(0, XINPUT_FLAG_GAMEPAD, &caps);
//	if (caps.Type != 0) return false;
//	return true;
//}
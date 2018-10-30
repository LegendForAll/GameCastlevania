#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#define KEYBOARD_BUFFER_SIZE 1024


//khoi tao doi tuong Direct input
int InitDirectInput();

//thiet lap va gianh quyen kiem soat KeyBoard
int InitKeyboard(HWND hwnd);

//doc du lieu ban phim
void PollKeyboard();

int IsKeyDown(int key);		// kiem tra trang thai phim dang duoc an hay khong
int IsKeyRelease(int key);	// kiem tra phim co dang o trang thai tren khong
int IsKeyPress(int key);	// kiem tra phim co vua chuyen tu up sang down khong

//giai phong doi tuong DirectInput
void KillKeyboard();
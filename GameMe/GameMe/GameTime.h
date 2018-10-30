#pragma once
#include <Windows.h>

class CGameTime
{
private:

	LONGLONG	m_start;
	float		m_frequencySeconds; // Seconds per count
	float		m_fps;				// frames per second

public:

	//Constructor
	CGameTime (void);
	~CGameTime(void);

	float m_elapsedGameTime;	//thoi gian troi qua khi goi Update
	float m_totalGameTime;		//thoi gian troi qua khi goi Init

	bool Initialize();
	void Update();
};
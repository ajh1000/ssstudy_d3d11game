#pragma once
#include "pch.h"

class GameWindow : public GameSingleton<GameWindow>
{
#define BINDTYPE std::function<void(WPARAM wParam, LPARAM lParam)>

public:
	GameWindow();
	~GameWindow();

	void init(UINT width, UINT height);

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HWND m_hWnd;
	HINSTANCE m_hInst;

	bool m_isPaused = false;

	//하나의 메세지에서 실행 되길 바라는 하나 또는 여러 개의 함수를 추가한다.
	void AddFuncToMsg(DWORD msg, BINDTYPE func);
	

private:
	LRESULT CustomMsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	std::map<DWORD, std::vector<BINDTYPE>> m_mapBind;

};


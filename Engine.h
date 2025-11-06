#pragma once

#include <Windows.h>
#include <sstream>

#include "App.h"
#include "Window.h"
#include "Input.h"

using std::stringstream;

class Engine
{
private:
	static App* app;					// aplicação a ser executada
	int Loop();							// laço principal do motor

public:
	static Window* window;				// janela da aplicação
	static Input* input;				// dispositivos de entrada da aplicação

	Engine();							// construtor
	~Engine();							// destrutor

	int Start(App* application);		// inicia a execução da aplicação

	// trata eventos do Windows
	static LRESULT CALLBACK EngineProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

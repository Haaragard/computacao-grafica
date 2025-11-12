#pragma once

#include <Windows.h>
#include <sstream>

#include "App.h"
#include "Window.h"
#include "Input.h"
#include "Timer.h"

using std::stringstream;

class Engine
{
private:
	static Timer timer;					// medidor de tempo
	static bool paused;					// estado da aplicação

	double FrameTime();					// calcula o tempo do quadro
	int Loop();							// laço principal do motor

public:
	static Window* window;				// janela da aplicação
	static Input* input;				// dispositivos de entrada da aplicação
	static App* app;					// aplicação a ser executada
	static double frameTime;			// tempo do quadro atual

	Engine();							// construtor
	~Engine();							// destrutor

	int Start(App* application);		// inicia a execução da aplicação

	static void Pause();				// pausa o motor
	static void Resume();				// reinicia o motor

	// trata eventos do Windows
	static LRESULT CALLBACK EngineProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

inline void Engine::Pause()
{
	paused = true; timer.Stop();
}

inline void Engine::Resume()
{
	paused = false; timer.Start();
}

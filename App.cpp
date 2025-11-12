#include "App.h"
#include "Engine.h"

Window*& App::window = Engine::window;					// ponteiro para a janela
Input*& App::input = Engine::input;					// ponteiro para a entrada
double& App::frameTime = Engine::frameTime;		// tempo do último quadro

App::App()
{
	if (!window)
	{
		// ATENÇÃO: assume que a instância da engine
		// é criada antes da instância da aplicação
		window = Engine::window;
		input = Engine::input;
	}
}

App::~App()
{
}

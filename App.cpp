#include "App.h"

#include "Engine.h"

Window* App::window = nullptr;			// ponteiro para a janela
Input* App::input = nullptr;			// ponteiro para a entrada

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

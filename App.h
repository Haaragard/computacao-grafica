#pragma once

#include "Window.h"
#include "Input.h"

class App
{
protected:
	static Window* window;				// janela
	static Input* input;

public:
	App();								// construtor
	virtual ~App();						// destrutor

	// Estes métodos são puramente virtuais, isto é,
	// devem ser implementados em todas as classes
	// derivadas de App.
	virtual void Init() = 0;			// inicialização
	virtual void Update() = 0;
	virtual void Finalize() = 0;

	// Estes métodos possuem uma implementação vazia por padrão e
	// apenas um deles deve ser sobrescrito na classe derivada:
	// - Draw é executado a cada ciclo do laço principal
	// - Display é chamado apenas uma vez no início da aplicação
	// e deve ser chamado manualmente em Update toda vez que a
	// tela precisar ser redesenhada.
	virtual void Draw() {};				// desenho
	virtual void Display() {};			// exibição
};


#include "DXUT.h"

using std::stringstream;

class WinApp : public App
{
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

void WinApp::Init()
{
}

void WinApp::Update()
{
	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();
}

void WinApp::Draw()
{
}

void WinApp::Finalize()
{
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
						_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(1024, 600);
	engine->window->Color(0, 122, 204);
	engine->window->Title("Aplicação Windows");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e executa a aplicação
	int exitCode = engine->Start(new WinApp());

	// finaliza execução
	delete engine;
	return exitCode;
}

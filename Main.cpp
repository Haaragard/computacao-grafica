#include "DXUT.h"

using std::stringstream;

class WinApp : public App
{
	bool drawMode = { false };
	bool clickPressed = { false };
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

	if (input->KeyDown(VK_LBUTTON))
		clickPressed = true;
	if (input->KeyUp(VK_LBUTTON))
		clickPressed = false;

	if (input->KeyPress('R'))
		window->Clear();

	if (input->KeyPress('D')) {
		drawMode = !drawMode;
		if (!drawMode) {
			window->Clear();
}
	}

void WinApp::Draw()
{
	if (drawMode) {
		if (clickPressed)
			window->DrawPixels(input->MouseX(), input->MouseY(), RGB(0, 0, 0));
	}
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

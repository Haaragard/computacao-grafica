#include "DXUT.h"

using std::stringstream;

class WinApp : public App
{
private:
	Timer frameTime;

	bool drawMode = { false };
	bool clickPressed = { false };

	int lineSize = { 0 };
	int linePosX = { 0 };
	int linePosY = { 0 };

	bool lineGoToRight = { false };
	bool lineGoToTop = { false };

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

void WinApp::Init()
{
	linePosX = window->CenterX();
	linePosY = window->CenterY();
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
		else {
			linePosX = 0;
			linePosY = 0;
		}
	}

	if (!drawMode) {
		if (lineGoToRight) {
			linePosX += int(100.f * Engine::frameTime);
		}
		else
		{
			linePosX -= int(100.f * Engine::frameTime);
		}
		if (linePosX + lineSize >= window->Width()) {
			lineGoToRight = false;
		}
		else if (linePosX <= 0)
		{
			lineGoToRight = true;
		}

		if (lineGoToTop) {
			linePosY += int(100.f * Engine::frameTime);
		}
		else
		{
			linePosY -= int(100.f * Engine::frameTime);
		}
		if (linePosY + lineSize >= window->Height()) {
			lineGoToTop = false;
		}
		else if (linePosY <= 0)
		{
			lineGoToTop = true;
		}
	}
}

void WinApp::Draw()
{
	if (drawMode) {
		if (clickPressed)
			window->DrawPixels(input->MouseX(), input->MouseY(), RGB(0, 0, 0));
	}
	else
	{
		HDC hdc = GetDC(window->Id());
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HPEN old = (HPEN)SelectObject(hdc, hPen);

		MoveToEx(hdc, linePosX, linePosY, NULL);

		int frameTimeLineSize = lineSize + int(100.f * Engine::frameTime);

		int endPosX = (lineGoToRight) ? linePosX + frameTimeLineSize : linePosX - frameTimeLineSize;
		int endPosY = (lineGoToTop) ? linePosY + frameTimeLineSize : linePosY - frameTimeLineSize;
		LineTo(hdc, endPosX, endPosY);

		SelectObject(hdc, old);
		DeleteObject(hPen);
		ReleaseDC(window->Id(), hdc);
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

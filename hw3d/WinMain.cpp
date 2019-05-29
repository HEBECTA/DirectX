#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch(msg) {

		case WM_CLOSE:
			PostQuitMessage(69);
			break;

		case WM_KEYDOWN:
			if (wParam == 'F')
				SetWindowText(hWnd, "Succeed !");
			break;

		case WM_KEYUP:
			if (wParam == 'F')
				SetWindowText(hWnd, "Lose !");
			break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int       nCmdShow )
{
	const auto pClassName = "hw3dbutts";
	// register windows class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	//wc.lpfnWndProc = DefWindowProc; // default windows procedure
	wc.lpfnWndProc = WndProc; // modified windows procedure
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	// create windows instance
	HWND hWnd = CreateWindowEx( // window handler
		0, pClassName,
		"Window name", 
		WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION, 
		200, 200,
		480, 580, 
		nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, SW_SHOW);

	// reading messages

	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1) {

		return -1;
	}

	else
		return msg.wParam;
}
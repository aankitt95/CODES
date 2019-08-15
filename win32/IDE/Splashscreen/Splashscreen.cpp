#include<windows.h>
#include"Mysplashscreen.h"



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;

	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, TEXT("MYICON"));
	wndclass.hIconSm = LoadIcon(hInstance, TEXT("CUSTICONSM"));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);


	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return((int)msg.wParam);

}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
		switch (iMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	////////////////////////////////////////////////////////

	HDC hdc , cdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[255] = TEXT("Hello World!!!");

	//loading bitmap
	HINSTANCE hInstance;
	static HBITMAP hbitSS;
	BITMAP bitSS;


	switch (iMsg)
	{

	case WM_CREATE:

		hInstance = GetModuleHandle(NULL);
		hbitSS = LoadBitmap(hInstance, MAKEINTRESOURCE(MYBITMAP));

		if (hbitSS = NULL)
		{
			MessageBox(hwnd, TEXT("No Bitmap"), TEXT("ERROR"), MB_OK | MB_ICONINFORMATION);
			DestroyWindow(hwnd);

		}
		break;





	case WM_PAINT:

		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		cdc = CreateCompatibleDC(NULL);
		SelectObject(cdc, hbitSS);
		GetObject(hbitSS, sizeof(BITMAP), &bitSS);
		StretchBlt(
			//for destination
			hdc, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top,

			//For Source
			cdc, 0, 0, bitSS.bmWidth, bitSS.bmHeight,

			//raster operation
			SRCCOPY);

		SetTextColor(hdc, RGB(0, 255, 0));
		SetBkColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		
		DeleteObject(cdc);
		
		EndPaint(hwnd, &ps);
		break;


	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));


}

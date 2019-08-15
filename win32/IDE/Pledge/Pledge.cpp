#include<windows.h>

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
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
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

	HDC hdc;
	PAINTSTRUCT ps;
	int X;

	TCHAR str1[50] = TEXT("Jana-Gana-Mana-Adhinayaka, Jaya He");
	TCHAR str2[55] = TEXT("Bharata - Bhagya - Vidhata");
	TCHAR str3[60] = TEXT("Punjab - Sindhu - Gujarata - Maratha");
	TCHAR str4[65] =TEXT("Dravida - Utkala - Banga");
	
	

	HDC hdc2;
	PAINTSTRUCT ps2;
	int Y;
	TCHAR str5[70] = TEXT("Vindhya-Himachala-Yamuna-Ganga");
	TCHAR str6[75] = TEXT("Uchchhala-Jaladhi Taranga");
	TCHAR str7[80] = TEXT("Tava Subha Name Jage");
	TCHAR str8[85] = TEXT("Tava Subha Ashisa Mage");


	
	HDC hdc3;
	PAINTSTRUCT ps3;
	int Z;
	TCHAR str9[90] = TEXT("Gahe Tava Jaya Gatha");
	TCHAR str10[95] = TEXT("Jana-Gana-Mangala Dayaka, Jaya He");
	TCHAR str11[100] = TEXT("Bharata-Bhagya-Vidhata");
	TCHAR str12[105] = TEXT("Jaya He, Jaya He, Jaya He,Jaya Jaya Jaya, Jaya He");



	switch (iMsg)
	{
	case WM_PAINT:

		
		hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(255, 125, 000));
		SetBkColor(hdc, RGB(0, 0, 0));


		
		hdc2 = BeginPaint(hwnd, &ps2);
		SetTextColor(hdc2, RGB(255, 255, 255));
		SetBkColor(hdc, RGB(0, 0, 0));
	

		
		hdc3 = BeginPaint(hwnd, &ps3);
		SetTextColor(hdc3, RGB(000, 255, 000));
		SetBkColor(hdc, RGB(0, 0, 0));

		TextOut(hdc,X , Y , str[i], strlen(str[1]));

		EndPaint(hwnd, &ps);
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));


}

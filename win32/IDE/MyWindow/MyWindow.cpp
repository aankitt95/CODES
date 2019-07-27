#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;

	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");  // for below parameter "lpszClassName = szAppName"


	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //TOPLEFT ICON
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  //taskbar icon, explorer icon- Small Icon
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // where ""Load"" there first parameter is ""NULL""
	wndclass.lpszClassName = szAppName;  //TCHAR szAppName defined above
	wndclass.lpszMenuName = NULL;  //no name for menu


	RegisterClassEx(&wndclass);


	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,  //which x co ordinate
		CW_USEDEFAULT,  // which y co ordinate
		CW_USEDEFAULT,  // width of window
		CW_USEDEFAULT,  // height of window
		NULL, //PARENT WINDWOW HANDLE
		NULL, //No LPSZMenu in above wndclass so No HANDLE thats why NULL
		hInstance, //WinMain madhla hInstance
		NULL);


	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);


	//eka applicion la ekach msg loop aste
	while (GetMessage(&msg, NULL, 0, 0)) //line no. 9 MSG msg; jatana rikama jato yetana bharun yeto &msg
		//here msg means that conversion of inturrupt--> event --> msg

        //ithe ""NULL"" -->> HWND pass karta tewa consider hote ki fakt 1 window ahe application la,but jast windows astil tar ani asa kela tar "EKA WINDOW CHE MSGS TUMHALA PAHIJE KI SARV WINDOWS CHE MSGS PAHIJE" he prblm hoil
		//NULL means mala majha window che ani child window sarvanche msgs de
		//ithe  0 , 0 -->> 350 msgs paiki kontya msg pasun te kontya msg paryant che msgs mala de (No recommended thats why 0,0 means sarvach pahijet)

	{
		TranslateMessage(&msg); //msg bharun ala,translate karnyachi garaj asel tar translate karto(values override karto) ani parat tyach msg madhe bharto 
		DispatchMessage(&msg); //dispatch hoto WndProc la,yala wnd proc mahit ahe coz of line no. 17, "you should keep ur WndProc in such a way that u and OS both can see it"
	//WndProc la call
	}


	return((int)msg.wParam); //condition false, baher nighun jail
	//true zali tar khalcha WndProc la jail
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)  //(line no.2 )tayar zalelya ball madhlya 4 gosti WndProc la pathawlya i.e handle , uint, wparam, lparam ani switch case madhe jatat // baki 2 gosti OS swata sathi handle karte
{
	//handle kela asel tar switch case madhe jate , nasel kela tar return DefWindowProc la jate, it is default by OS
	switch (iMsg) //iMsg la handle kela
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break; //break chya jagi return takla tar te msg OS kade jat nahi(DefWindowProc la jat nahi) HACKERS lok as kartat via HOOPING
		//HACKERS WndProc war watch thewtat app chya ani user ne click kela tar adhi hacker la adhi jate info
	}
	return(DefWindowProc(hwnd, iMsg , wParam, lParam)); //false asel tar OS chi default window procedure i.e DefWindowProc
// ithe iMsg means UINT je ki lime 2nd madhe ahe
}
//handle karun zalyawar or nahi zalyawar msgs OS kade jatat (Shevatche sanskar) post processing sathi i.e to check WHEATHER ALL PARAMETERS ARE WITHIN ITS LIMIT OR NOT
//Hack kela asel tar parameters limit madhe nastat


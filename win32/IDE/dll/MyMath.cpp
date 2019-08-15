#include<windows.h>
#include"MyMath.h"

BOOL WINAPI Dllmain(HINSTANCE hdll, DWORD dwreason, LPVOID lpreason)
{
	switch (dwreason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

	}

	return TRUE;
}
extern "C" __declspec (dllexport) int makesquare(int num)
{
	return(num*num);
}

extern "C" BOOL IsNumberNegative(int num)
{
	if (num < 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



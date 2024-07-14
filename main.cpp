#include <windows.h>
#include <cmath>
#include <math.h>
#include <mmsystem.h>
#include <time.h>
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE r;
		BYTE g;
		BYTE b;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;

DWORD WINAPI wave(LPVOID lpParam) {
  HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
  int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
  double angle = 0;
  while (1) {
    desk = GetDC(0);
    for (float i = 0; i < sw + sh; i += 0.99f) {
      int a = sin(angle) * 20;
      BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
      angle += M_PI / 40;
      DeleteObject(&i); DeleteObject(&a);
    }
    ReleaseDC(wnd, desk);
    DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
  }
}

DWORD WINAPI epil(LPVOID lpParam)  {
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		PatBlt(hdc, 0, 0, w, h, PATINVERT);
		DeleteObject(brush);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI cur(LPVOID lpParam) {
	while(1){
		HDC hdc = GetDC(HWND_DESKTOP);
		int icon_x = GetSystemMetrics(SM_CXICON);
		int icon_y = GetSystemMetrics(SM_CYICON) ;
		POINT cursor;
        GetCursorPos(&cursor);
        DrawIcon(hdc, cursor.x - icon_x, cursor.y - icon_y, LoadIcon(NULL, IDI_EXCLAMATION));
        ReleaseDC(0, hdc);
	}
}
DWORD WINAPI shek(LPVOID lpParam)
{
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 10, rand() % 10, w, h, hdc, rand() % 10, rand() % 10, SRCCOPY);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI prgb(LPVOID lpParam)
{
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			//INT x = i % w, y = i / w;
			rgbScreen[i].rgb -= 666;
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(100);
		ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
	}
}
DWORD WINAPI bro(LPVOID lpParam)
{
	FreeConsole();
	int a, b;
	while (0 == 0) {
		a = GetSystemMetrics(SM_CXSCREEN);
		b = GetSystemMetrics(SM_CYSCREEN);
		StretchBlt(GetDC(NULL), 50, 50, a - 100, b - 100, GetDC(NULL), 0, 0, a, b, SRCCOPY);
	}
}



int main () {
	Sleep(2000);
	if (MessageBoxW(NULL, L"This GDI safety malware is a remake of XPBadJoke.exe by Unknown. Run?", L"XPBadJoke1.5.exe - b y   T u b e r c o m i o s i s", MB_YESNO | MB_ICONASTERISK) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		Sleep(10000);
		HANDLE a = CreateThread(0, 0, wave, 0, 0, 0);
		Sleep(15000);
		TerminateThread(a, 0);
		CloseHandle(a);
	InvalidateRect(0, 0, 0);
		HANDLE b = CreateThread(0, 0, epil, 0, 0, 0);
		HANDLE c = CreateThread(0, 0, cur, 0, 0, 0);
		Sleep(15000);
		TerminateThread(b, 0);
		CloseHandle(b);
	InvalidateRect(0, 0, 0);
		HANDLE d = CreateThread(0, 0, shek, 0, 0, 0);
		Sleep(15000);
		HANDLE e = CreateThread(0, 0, prgb, 0, 0, 0);
		Sleep(15000);
		TerminateThread(e, 0);
		CloseHandle(e);
	InvalidateRect(0, 0, 0);
		HANDLE f = CreateThread(0, 0, epil, 0, 0, 0);
		Sleep(15000);
		TerminateThread(f, 0);
		CloseHandle(f);
	InvalidateRect(0, 0, 0);
		HANDLE g = CreateThread(0, 0, bro, 0, 0, 0);
		Sleep(15000);
		TerminateThread(g, 0);
		TerminateThread(c, 0);
		TerminateThread(d, 0);
		CloseHandle(g);
	InvalidateRect(0, 0, 0);
		CloseHandle(c);
	InvalidateRect(0, 0, 0);
		CloseHandle(d);
	InvalidateRect(0, 0, 0);
	}
}

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include"camera.h"
#include"Martix.h"
#include"vertex.h"
#include"device.h"
#include"color.h"

const int width = 680;
const int height = 680;
const float PI = 3.1415926;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//void DDALine(HDC hDC, int x0, int y0, int x1, int y1);
//void DDALine(HDC hDC, vertex v1, vertex v2);
//void drawTriggle(HDC hdc, vertex v1, vertex v2, vertex v3);



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"HiRender";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"HiRender",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        device idevice(hdc, width, height);

        //SetPixel(hdc, v1.pos.x, v1.pos.y, 255);
        vertex v1(-3, 0, -5);
        vertex v2(3, 0, -5);
        vertex v3(0, 3, -5);

        vertex v4(-3, 3, -5);
        vertex v5(3, 3, -5);
        vertex v6(0, 0, -5);


        //idevice.drawTriggle(hdc,v1, v2, v3, color(0.118, 0.238, 0.198));
        idevice.drawTriggle(hdc, v4, v5, v6,color(0,0.5,0));
        //drawTriggle(hdc,v1,v2,v3);
        //DDALine(hdc, 0, 0, 100, 100);
        // All painting occurs here, between BeginPaint and EndPaint.
       // FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));


        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

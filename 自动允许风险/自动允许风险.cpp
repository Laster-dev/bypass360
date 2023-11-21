#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

int __cdecl main(int argc, const char** argv, const char** envp)
{
    struct tagPOINT Point; // [esp+4h] [ebp-1Ch] BYREF
    struct tagRECT Rect; // [esp+Ch] [ebp-14h] BYREF

    while (true)
    {
        HWND hWnd = FindWindowW(L"Q360HIPSClass", 0);
        std::cout << hWnd;
        PostMessageW(hWnd, 0x201u, 0, 22282820);
        PostMessageW(hWnd, 0x202u, 0, 22282820);
        if (hWnd)
        {
            GetCursorPos(&Point);
            GetWindowRect(hWnd, &Rect);
            SetCursorPos(Rect.left + 487, Rect.top + 370);
            SetCursorPos(Rect.left + 487, Rect.top + 368);
            mouse_event(6u, 0, 0, 0, 0);
            SetCursorPos(Point.x, Point.y);

        }
    }



    return 0;
}
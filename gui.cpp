#include <windows.h>
#define IDC_MAIN_EDIT 101

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // Create the text box.
            HWND textBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                          WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
                                          10, 10, 300, 30, hwnd, (HMENU)IDC_MAIN_EDIT,
                                          GetModuleHandle(NULL), NULL);
            SendMessage(textBox, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(FALSE, 0));
            break;
        }
        case WM_DESTROY:
        {
            // Clean up the app's resources.
            PostQuitMessage(0);
            break;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS windowClass = {0};
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = "MyWindowClass";
    RegisterClass(&windowClass);

    HWND windowHandle = CreateWindowEx(0, "MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW,
                                       CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                       NULL, NULL, hInstance, NULL);
    ShowWindow(windowHandle, nCmdShow);

    MSG message;
    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}

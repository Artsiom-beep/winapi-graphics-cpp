#include <windows.h>

// Глобальные переменные
HINSTANCE hInst;
int smileRadius = 0; // Начальный радиус смайлика
const int maxRadius = 100; // Максимальный радиус смайлика

// Прототипы функций
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawSquare(HDC hdc, int x, int y, int x2, int y2);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wcex;
    HWND hWnd;
    MSG msg;

    hInst = hInstance;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"SmileWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    RegisterClassEx(&wcex);

    hWnd = CreateWindow(L"SmileWindowClass", L"Smile Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Устанавливаем таймер для анимации
    SetTimer(hWnd, 1, 50, NULL); // Таймер с интервалом 50 мс

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        DrawSquare(hdc, 200, 200, 500, 500);
        EndPaint(hWnd, &ps);
        break;
    case WM_TIMER:
        // Увеличиваем радиус смайлика
        if (smileRadius < maxRadius) {
            smileRadius += 2;
            InvalidateRect(hWnd, NULL, TRUE); // Перерисовываем окно
        }
        else {
            KillTimer(hWnd, 1); // Останавливаем таймер, когда достигнут максимальный радиус
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void DrawSmile(HDC hdc, int x, int y, int radius) {
    // Рисуем лицо
    Rectangle(hdc, x - radius, y - radius, x + radius, y + radius);

    // Рисуем глаза
    Ellipse(hdc, x - radius / 3, y - radius / 3, x - radius / 6, y - radius / 6);
    Ellipse(hdc, x + radius / 6, y - radius / 3, x + radius / 3, y - radius / 6);

    // Рисуем рот
    Arc(hdc, x - radius / 2, y - radius / 2, x + radius / 2, y + radius / 2, x - radius / 2, y, x + radius / 2, y);
}

// Oblig1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Oblig1.h"

#include <list>


#include "car.h"
#include "traffic_light.h"

constexpr auto MAX_LOADSTRING = 100;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

traffic_light* traffic_left = new traffic_light(0, 150, 250);
traffic_light* traffic_top = new traffic_light(2, 150, 650);

//List of cars from left
std::list<car> carsLeft = {
	car(-10, 400)
};

//List of cars from top
std::list<car> carsTop = {
	car(350, -10)
};


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OBLIG1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OBLIG1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return static_cast<int>(msg.wParam);
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OBLIG1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = reinterpret_cast<HBRUSH>((COLOR_WINDOW + 1));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OBLIG1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

	SetTimer(hWnd, 1, 5000, nullptr); //traffic lights

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

	case WM_CREATE:
		break;

	case WM_LBUTTONDOWN:
		{
			SetTimer(hWnd, 2, 500, nullptr);
		}

	case WM_RBUTTONDOWN:
		{
			SetTimer(hWnd, 3, 500, nullptr);
		}
    
	case WM_TIMER:
		switch (wParam)
		{
		case 1: //traffic lights
			{
				traffic_left->set_state();
				traffic_top->set_state();
				InvalidateRect(hWnd, nullptr, FALSE);
			}
			break;
		case 2: //cars from left
			{
				for (auto &car : carsLeft)
				{
					car.set_x_pos();
				}
				InvalidateRect(hWnd, nullptr, TRUE);
			}
			break;
		case 3: //cars from top
			{
				for (auto &car : carsTop)
				{
					car.set_y_pos();
				}
				InvalidateRect(hWnd, nullptr, TRUE);
			}
			break;
		default:
			break;
		}
    	
    case WM_COMMAND:
        {
	        const int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC__* hdc = BeginPaint(hWnd, &ps);

            void* stockbrush = GetStockObject(DC_BRUSH);
    		SelectObject(hdc, stockbrush);
    		
    		SetDCBrushColor(hdc, RGB(133,133,133));
    		Rectangle(hdc, 0, 450, 2000, 300);
    		Rectangle(hdc, 300, 2000, 450, 0);

    		SetDCBrushColor(hdc, RGB(255,255,255));
			Rectangle(hdc, 300, 300, 450, 295);
    		Rectangle(hdc, 295, 450, 301,300);

    		/*
				Choose auto x when you want to work with copies.
				Choose auto &x when you want to work with original items and may modify them.
				Choose auto const &x when you want to work with original items and will not modify them.
    		*/
    		
            traffic_left->draw(hdc);
    		traffic_top->draw(hdc);
    		
    		for (auto const &car : carsLeft)
    		{
    			car.draw(hdc);
    		}
    		for (auto const &car : carsTop)
    		{
    			car.draw(hdc);
    		}
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		carsLeft.clear();
    	carsTop.clear();
		delete traffic_left;
    	delete traffic_top;
    	KillTimer(hWnd, 1);
    	KillTimer(hWnd, 2);
    	KillTimer(hWnd, 3);
    
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return static_cast<INT_PTR>(TRUE);

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return static_cast<INT_PTR>(TRUE);
        }
        break;
    default: ;
    }
    return static_cast<INT_PTR>(FALSE);
}
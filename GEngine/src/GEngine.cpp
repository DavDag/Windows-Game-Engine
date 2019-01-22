#include "GEngine.hpp"

// Constructor
GEngine::GEngine()
{
	// Engine Default values Title
	m_AppName = "Default";
	m_bGameRunning = true;
	m_dFps = 60;
	m_bShowFps = true;
	
	// Blend Function (Currently unused)
	m_blendfunction.BlendOp = AC_SRC_OVER;
	m_blendfunction.BlendFlags = 0;
	m_blendfunction.SourceConstantAlpha = 255;
	m_blendfunction.AlphaFormat = AC_SRC_ALPHA;
}

// Init function that must be called before anything
bool GEngine::init(int width, int height)
{
	// Get time resolution (min / max)
	if (timeGetDevCaps(&m_tc, sizeof(TIMECAPS)) != TIMERR_NOERROR) 
	{
        MessageBox(NULL, "Timer setting Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return false;
	}
	
	// Calculate Timer resolution
	m_timerRes = std::min(std::max((int) m_tc.wPeriodMin, TARGET_RESOLUTION), (int) m_tc.wPeriodMax);
	
	// Set Timer resolution
	timeBeginPeriod(m_timerRes);
	
	// Set up screen dimensions
	m_iScreenWidth = width;
	m_iScreenHeight = height;
    
    // Set up WindowClassEx
    m_wc.style         = 0;										// The class Style or Styles
    m_wc.lpszClassName = "myWClass";							// Window class name
    m_wc.cbSize        = sizeof(WNDCLASSEX);					// The size in byte of this structure
    m_wc.lpfnWndProc   = WndProc;								// A pointer to the window procedure
    m_wc.cbClsExtra    = 0;										// Extra bytes to allocate following window-structure
    m_wc.cbWndExtra    = 0;										// Extra bytes to allocate following window-instance
    m_wc.hInstance     = NULL;									// An handle to the instance that contains the window procedure
    m_wc.hIcon         = NULL;									// An handle to the class Icon
    m_wc.hCursor       = NULL;									// An handle to the class Cursor
    m_wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// An handle to the class Background Brush
    m_wc.lpszMenuName  = NULL;									// Resource name of the class Menu
    m_wc.hIconSm       = NULL;									// An handle to the small Icon

	// Register it
	if(!RegisterClassEx(&m_wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }
    
    // Create the window and get the handle
    m_hwnd = CreateWindowEx(	WS_EX_CLIENTEDGE, "myWClass", "myWTitle", WS_CLIPCHILDREN | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
								CW_USEDEFAULT, CW_USEDEFAULT, m_iScreenWidth, m_iScreenHeight, NULL, NULL, NULL, NULL);
	
	// Check if it's created correctly
	if(m_hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }
    
    // Show window
    ShowWindow(m_hwnd, SW_SHOWNORMAL);
    
    return true;
}

// Main function that must be called by user after init
void GEngine::run()
{
	// Start a thread for the message handling
    std::thread myT (&GEngine::runGame, this);
    
    // Launch handling messages function
    handleMessages();
    
    // Wait for thread to stop
    myT.join();
}

// This function is where all the messages that are sent to you window are processed
LRESULT CALLBACK GEngine::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    	// If "Alt+F4" OR "X" button are pressed
        case WM_CLOSE:
    	{
    		// Send us a WM_DESTROY message
            DestroyWindow(hwnd);
        	break;
		}
		
		// Leak erasebkgnd
		case WM_ERASEBKGND:
		{
			break;
		}
		
		// Leak Paint
		case WM_PAINT:
		{
        	// Draw buffer into Screen
        	if(m_bCanDraw)
			{
				/* TODO (#1#): Add alpha blend */						
					
				// Lock for mutual exclusion
				m_buffermutex.lock();
				
				// Draw buffer
				BitBlt(m_hdcW, 0, 0, m_iScreenWidth, m_iScreenHeight, m_hdcB, 0, 0, SRCCOPY);
				//GdiAlphaBlend(m_hdcW, 0, 0, m_iScreenWidth, m_iScreenHeight, m_hdcB, 0, 0, m_iScreenWidth, m_iScreenHeight, m_blendfunction);
				m_bCanDraw = false;
				
				// Unlock to release resource
				m_buffermutex.unlock();
			}
			break;
		}
        
		// Destroy message
        case WM_DESTROY:
        {
        	// Send us a WM_QUIT that exit the window
            PostQuitMessage(EXIT_SUCCESS);
			break;
		}
		
		// Default message procedure
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
		
// This function is launched by a thread and handle messages		
void GEngine::handleMessages()
{
	MSG msg;
	
	// Until the window is open get a message from buffer
	while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
    	// Translate the message and dispatch it to the right window
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    // Stop game from Running
    m_bGameRunning = false;
}

// Main Function
void GEngine::runGame()
{
	/* DONE (#1#): Attach thread to receive input
	               call [ AttachThreadInput() ]
	               with [ GetCurrentThreadId() ]
	               and  [ GetWindowThreadProcessId(m_hwnd) ] */
	// Attach thread to receive input
	AttachThreadInput(GetCurrentThreadId(), GetWindowThreadProcessId(m_hwnd, NULL), true);
	
    // Get HDC for Window
    m_hdcW = GetDC(m_hwnd);
    
    // Create HDC for Buffer
    m_hdcB = CreateCompatibleDC(m_hdcW);
    
    // Create Bitmap
    m_hBitmap = CreateBitmap(m_iScreenWidth, m_iScreenHeight, 1, 32, NULL);
    
    // Assign bitmap to hdc
    SelectObject(m_hdcB, m_hBitmap);
    
    // Create Pen for buffer
    m_hPen = CreatePen(PS_NULL, 0, 0x00000000);
    
    // Assign pen to hdc
    SelectObject(m_hdcB, m_hPen);
    
	// Create two time variables that help us elaborate dt
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::system_clock::now();
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsedTime;
	double dt, delta;
	
	// Main Loop
	while(m_bGameRunning)
	{	
		// Launch user's onStart
		m_bGameRunning = onStart();
	    
		// Game Loop
		while(m_bGameRunning)
	    {
			// Get current time
			t2 = std::chrono::high_resolution_clock::now();
	        elapsedTime = t2 - t1;
	        dt = elapsedTime.count();
	        t1 = t2;
        	
        	// Keyboard and Mouse check ( must be done by main thread or attached ones )
        	// Load data into Keyboard class
			GetKeyboardState(Keys::m_buffer);
			
			// Update it
    		Keys::update();
			
			// Load data into Mouse class
			POINT p;
			GetCursorPos(&p);
			
			// Adjust them to relative window
			ScreenToClient(m_hwnd, &p);
				
			// Insert new mouse position
			Mouse::setMousePos(Vector2d(p.x, p.y));
			
	        // Lock for mutual exclusion
	        m_buffermutex.lock();
        	
	        // User Update
	        m_bGameRunning = onUpdate(dt);
	        
	        // Now can draw
			m_bCanDraw = true;
	        
	        // Unlock to release resource
	        m_buffermutex.unlock();
	        
	        // Get current time and subtract to get elapsed time then calculate delta
	        t2 = std::chrono::high_resolution_clock::now();
	        elapsedTime = t2 - t1;
			delta = (1.0f / m_dFps - elapsedTime.count());
	        
			// check for positive delta
			if(delta > 0)
			{
				// wait until next frame
				std::this_thread::sleep_for(std::chrono::duration<double>(delta));
			}
	    	
	    	// Set window title
			char s[128];
			if(m_bShowFps){
				sprintf(s, "%s - FPS %5.2f", m_AppName.data(), 1.0f / dt);
			}
			else
			{
				sprintf(s, "%s", m_AppName.data());
			}
			SetWindowText(m_hwnd, s);
		}
		
    	// Launch onDestroy Function to let user deallocate resources and decide for game ending
    	m_bGameRunning = onDestroy();
	}
}
		  
// Set Brush
void GEngine::setBrush(Color color)
{
	// Create Brush
	m_hBrush = CreateSolidBrush(color.GetPreABGR());
	
	// Set Brush
	SelectObject(m_hdcB, m_hBrush);
}

/**
  *  DRAWING FUNCTIONS
  **/

// Clear Background
void GEngine::clear(Color color /*= Color::Black*/)
{
	drawRect(m_iScreenWidth >> 1, m_iScreenHeight >> 1, m_iScreenWidth, m_iScreenHeight, color);
}

// Rectangle
void GEngine::drawRect(int x, int y, float width, float height, Color color /*= Color::White*/)
{
	// Set brush
	setBrush(color);

	// Draw Rectangle
	Rectangle(m_hdcB, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	
	// Release Brush
	DeleteObject(m_hBrush);
}

// Cirlce
void GEngine::drawCircle(int x, int y, float radius, Color color /*= Color::White*/)
{
	// Set brush
	setBrush(color);

	// Draw Ellipse
	Ellipse(m_hdcB, x - radius / 2, y - radius / 2, x + radius / 2, y + radius / 2);
	
	// Release Brush
	DeleteObject(m_hBrush);
}

// Polygon
void GEngine::drawPolygon(int x[], int y[], int n, Color color /*= Color::White*/)
{
	// Set Brush
	setBrush(color);
	
	// Draw Polygon
	POINT points[n];
	for(int i = 0; i < n; ++i) points[i] = {x[i], y[i]};
	Polygon(m_hdcB, points, n);
	
	// Release Brush
	DeleteObject(m_hBrush);
}

// Ellipse
void GEngine::drawEllipse(int x, int y, float width, float height, Color color /*= Color::White*/)
{
	// Set brush
	setBrush(color);

	// Draw Ellipse
	Ellipse(m_hdcB, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	
	// Release Brush
	DeleteObject(m_hBrush);
}

// Surface
void GEngine::drawSurf(Vector2d srcPos, Surface& s, Vector2d destPos)
{
	// Draw the surface
	BitBlt(m_hdcB, destPos.x, destPos.y, s.getSize().x, s.getSize().y, s.m_hdc, srcPos.x, srcPos.y, SRCCOPY);
}

// Set Fps
void GEngine::setFps(double new_fps)
{
	m_dFps = new_fps;
}

// Set fps showing
void GEngine::showFps(bool show)
{
	m_bShowFps = show;
}

// Set App Title
void GEngine::setTitle(const std::string &title)
{
	m_AppName = title;
}

// Destructor
GEngine::~GEngine()
{
	// Deallocate Resources
	DeleteObject(m_hBitmap);
	DeleteObject(m_hPen);
	DeleteDC(m_hdcW);
	DeleteDC(m_hdcB);
	
	// Reset period
	timeEndPeriod(m_timerRes);
}

// Defining static variables
HWND GEngine::m_hwnd = NULL;
HDC GEngine::m_hdcW = NULL;
HDC GEngine::m_hdcB = NULL;
HBITMAP GEngine::m_hBitmap = NULL;
short GEngine::m_iScreenWidth = 0;
short GEngine::m_iScreenHeight = 0;
std::atomic<bool> GEngine::m_bCanDraw(false);
std::mutex GEngine::m_buffermutex;
BLENDFUNCTION GEngine::m_blendfunction;

#pragma once

#include <windows.h>
#include <mutex>
#include <thread>
#include <stdio.h>
#include <atomic>
#include <chrono>

#ifndef GENGINE_HPP
#define GENGINE_HPP

#define WIN32_LEAN_AND_MEAN
#define TARGET_RESOLUTION 1			// 1-millisecond target resolution

#include "Colors.hpp"
#include "KeyBoard.hpp"
#include "Mouse.hpp"

/**
  *  First of all add
  *		< -lgdi32 -lwinmm -lws2_32 >
  *  to compiler linker
  *
  *  To start your own game inherit this class and define virtual functions.
  *  Example Code:
  *	  	
  *		#include <GEngine.hpp>
  *		class Engine: public GEngine
  *		{
  *				bool onStart() { return true;}
  *				bool onUpdate(float dt) { return true;}		
  *		};
  *		int main()
  *		{
  *			Engine demo;
  *			if(demo.init(800, 600))
  *				demo.run();
  *		}
  **/

// Main Class
class GEngine: protected Keys
{
	public:
		// Constructor
		GEngine();
		
		// Destructor
		~GEngine();
		
		// Init function that must be called before anything
		bool init(int width, int height);
		
		// Main function that must be called by user after init
		void run();
	
	private:
		// This function is where all the messages that are sent to you window are processed
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		
		// This function is launched by a thread and handle messages		
		void handleMessages();
		
		// Main Function
		void runGame();
		  
		// Set Brush
		void setBrush(Color color);
		
	protected:
		/**
		  * THOSE FUNCTION MUST BEING OVERWRITTEN
		  * onStart is launched once before the game loop
		  * onUpdate is launched every frame and got a parameter (dt or time delta)
		  * onDestroy is launched once before the game end
		  **/
		virtual bool onStart() = 0;
		virtual bool onUpdate(float dt) = 0;
		virtual bool onDestroy() {return true;}
		
		/**
		  *  DRAWING FUNCTIONS
		  **/
		
		// Clear Background
		void clear(Color color = Color::Black);
		
		// Rectangle
		void drawRect(int x, int y, float width, float height, Color color = Color::White);
		
		// Cirlce
		void drawCircle(int x, int y, float radius, Color color = Color::White);
		
		// Polygon
		void drawPolygon(int x[], int y[], int n, Color color = Color::White);
		
		// Ellipse
		void drawEllipse(int x, int y, float width, float height, Color color = Color::White);
		
		// Set Fps
		void setFps(double new_fps);
		
		// Set fps showing
		void showFps(bool show);
		
		// Set App Title
		void setTitle(const std::string &title);
		
	private:
		// Contains information about timer resolution
		TIMECAPS m_tc;
		
		// Timer resolution (milliseconds)
		UINT m_timerRes;
		
		// Contain Window Class information
		WNDCLASSEX m_wc;
		
		// Window handler
		static HWND m_hwnd;
		
		// Handle to Device Content (Window and Buffer)
		static HDC m_hdcW, m_hdcB;
		
		// Handle to Bitmap
		static HBITMAP m_hBitmap;
		
		// Handle to Brush
		HBRUSH m_hBrush;
		
		// Handle to Pen
		HPEN m_hPen;
		
		// Atomic bool for drawing
		static std::atomic<bool> m_bCanDraw;
		
		// Blend function
		static BLENDFUNCTION m_blendfunction;
		
		// Mutex for screen buffer
		static std::mutex m_buffermutex;
		
		// Screen Dimensions
		static short m_iScreenWidth, m_iScreenHeight;
		
		// Game Running boolean
		std::atomic<bool> m_bGameRunning;
		
		// Application Name
		std::string m_AppName;
		
		// Fps
		double m_dFps;
		
		// Show Fps
		bool m_bShowFps;
};

#endif //GENGINE_HPP

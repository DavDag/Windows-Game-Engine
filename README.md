# My-Windows-Game-Engine
My own graphic engine.
(Currently works for every version of Window)

## What can you do ?
* Draw circles, ellipses, rectangle, polygons.
* Read input from keyboard and mouse (pressed, held, released, toggled).
* Colors ! (Now RGB only but i'm working to add Alpha).
* Lock FPS ( from 1 to 1000! ).
* Set Window Title.
* Run in multithreading so FASTER on multicore machines.
* I will add Surfaces, vector2d, vector3d, some helpful math's equations and others !.

## How to install it
### DevCpp

1. Create New Project (Empty Project / Console Application)
2. Go to Project->Project Options->Parameters->Add Library or object. Browse into C:\somthing\GEngine\bin\libGEngine.a and Select it.
3. Paste "-lgdi32 -lwinmm -lws2_32" inside Linker box (_You need to complete second before !)
4. Go to Project->Project Options->Directories->Include Directories. Browse into C:\somthing\GEngine\src, Select it and click on "ADD".
5. Then you can #include <GEngine.hpp> and use my library !

## How to use it

### Basics
```c++
#include <GEngine.hpp>

/** Create a class and inherit from GEngine
  * You must define onStart() and onUpdate(float dt)
  * otherwise it will be abstract.
  **/
class Engine: public GEngine
{

  public:
    // This function will be called when the game start or restart.
    bool onStart()
    {
      // Return true if all worked correctly
      return true;
    }
    
    // Every frame the engine will call this function
    bool onUpdate(float dt)
    {
      clear(Color::Black);                          // Clear background with black
      drawRect(400, 300, 100, 100, Color::Blue);    // Draw a simple 100px width 100px height blue rectangle
      
      if(KeyBoard::GetKeyState(KeyBoard::K_W).held) // Check if W is held
       drawRect(500, 300, 100, 100, Color::Red)     // Draw a 100px width 100px height red rectangle
      
      // Its important to return true if you dont want to close the application
      return true;
    }
    
    // optional
    bool onDestroy()
    {
      // This function is called when Game Loop is over.
      // You can return true if you want to close or false if you want to restart the game.
      return true;
    }
};

int main()
{
  // Create an instance.
  Engine demo;
  
  // Initialize the window (width, height) in pixels.
  if(demo.init(800, 600))
  
      // If all is gone correctly you can run your game !
      demo.run();
  
  return 0;
}
```

## Version
0.1 Let's start !

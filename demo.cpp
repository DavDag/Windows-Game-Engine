#include <GEngine.hpp>
#include <math.h>

class Engine: public GEngine
{
	public:
		bool onStart()
		{
			speed = 720.0f;
			player = Vector2d(400, 300);
			size = Vector2d(40, 30);
			dir = Vector2d((rand() % 2) ? 1 : -1, (rand() % 2) ? 1 : -1);
			return true;
		}
		bool onUpdate(float dt)
		{
			player = player + dir * (dt * speed);
			Color color = Color(player.x / 800.0f * 255.0f, player.y / 600.0f * 255.0f, 0);
			
			if(player.x < size.x / 2 || player.x > 700 - size.x / 2) dir.x = -dir.x;
			if(player.y < size.y / 2 || player.y > 500 - size.y / 2) dir.y = -dir.y;

			drawRect(player.x, player.y, size.x, size.y, color);
			return true;
		}
		bool onDestroy()
		{
			return true;
		}
	private:
		float speed;
		Vector2d player, dir, size;
};

int main()
{
	srand(time(NULL));
	Engine demo;
	if(demo.init(700, 500))
		demo.run();
	return 0;
}

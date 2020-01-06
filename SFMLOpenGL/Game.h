#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>


using namespace std;
//using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;

	Vector3 v3{ 1,1,1 };
	Vector3 points[8]{	{-1.0f, -1.0f, -5.0f}, 
						{1.0f, -1.0f, -5.0f},
						{1.0f, 1.0f, -5.0f},
						{-1.0f, 1.0f, -5.0f},

						{-1.0f, -1.0f, -15.0f},
						{1.0f, -1.0f, -15.0f},
						{1.0f, 1.0f, -15.0f},
						{-1.0f, 1.0f, -15.0f}
					};
};
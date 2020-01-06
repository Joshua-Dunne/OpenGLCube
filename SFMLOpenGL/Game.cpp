#include <Game.h>

bool updatable = false;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());

		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(points[6].getX(), points[6].getY(), points[6].getZ());
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());
		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());

		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());
		glVertex3f(points[5].getX(), points[5].getY(), points[4].getZ());
		glVertex3f(points[6].getX(), points[6].getY(), points[4].getZ());

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}


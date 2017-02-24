#include <App.h>
#include <iostream>
#include <string.h>
#include <GL/gl.h>

using msgl::graphics::Window;
using msgl::graphics::Sprite;
using msgl::core::Vec2;

//PRIVATE HELPER METHODS
int findMaxSize(std::vector<Sprite*>);

//PUBLIC METHODS
App::App ()
{
}

App::~App ()
{
	destroy();
}

void App::init(int argc, char* argv[])
{
	animation.frameRate = 8;
	parseParameters(argc, argv);
	window.initGLFW();
	window = Window(500, 500, "Sprite Preview");
	glfwMakeContextCurrent(window.id);
	sprites = msgl::core::loadFromFile(fileName);
	int maxSize = findMaxSize(sprites);
	int box[4];
	for(Sprite* sprite : sprites)
	{
		sprite->getTextureBoundingBox(box);
		sprite->size = Vec2(2 * box[2] / (float)maxSize, 2 * box[3] / (float)maxSize);
		sprite->position = Vec2(-1, -1);
		sprite->setOrigin(sprite->origin);
		animation.addFrame(sprite);
	}

	setBackgroundColor(0.7, 0.7, 0.9, 1);
}
void App::update(double deltaTime)
{
	animation.update(deltaTime);
	window.clear();
	animation.currentFrame->draw();
	window.swapBuffer();
	window.pollEvents();
}
void App::destroy()
{
	for(Sprite* sprite : sprites)
	{
		delete(sprite);
	}
	sprites.clear();
}

void App::parseParameters(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Need filename argument" << std::endl;
		exit(1);
	}

	fileName = argv[argc - 1];

	for(int i = 1; i < argc - 1; i++)
	{
		if(strcmp(argv[i], "-V") == 0)
		{
			vAlign = true;
		}
		else if(strcmp(argv[i], "-H") == 0)
		{
			vAlign = false;
		}
		else if(strcmp(argv[i], "-f") == 0)
		{
			animation.frameRate = atoi(argv[i + 1]);
			i++;
		}
		else
		{
			std::cout << "Unknown parameter " << argv[i] << "\n" << std::endl;
			exit(1);
		}
	}
}

void App::setBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}


//HELPER METHODS
int findMaxSize(std::vector<Sprite*> sprites)
{
	int boundingBox[4];
	int max = 0;
	int current;
	for(Sprite* sprite : sprites)
	{
		sprite->getTextureBoundingBox(boundingBox);
		current = boundingBox[2];
		if(current > max)
			max = current;

		current = boundingBox[3];
		if(current > max)
			max = current;
	}
	return max;
}


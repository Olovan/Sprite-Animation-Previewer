#include <MSGL/msglCore.h>
#include <MSGL/msglGraphics.h>
#include <vector>
#include <string>

#define Window msgl::graphics::Window
#define Sprite msgl::graphics::Sprite
#define SpriteAnimation msgl::graphics::SpriteAnimation
	
class App
{
public:
	App ();
	virtual ~App ();

	void init(int, char**);
	void update(double deltaTime);
	void destroy();
	void parseParameters(int, char**);
	void setBackgroundColor(float r, float g, float b, float a);

	bool vAlign = true;
	std::string fileName;
	Window window;
	std::vector<Sprite*> sprites;
	SpriteAnimation animation;

private:
	/* data */
};

#undef SpriteAnimation
#undef Window
#undef Sprite

#ifndef INPUTHANDLER_H_LYSLRYPJ
#define INPUTHANDLER_H_LYSLRYPJ

#include <MSGL/msglCore.h>

#define ButtonListener    msgl::core::ButtonListener
#define KeyListener       msgl::core::KeyListener

class App;

class InputHandler : public KeyListener, public ButtonListener
{
public:
	InputHandler ();
	~InputHandler ();

	enum STATE {DEFAULT, COPY, MOVE, CREATE};
	STATE state;

	//Methods
	void update();
	//KeyListener
	void keyPressed(int key, int mods);
	void keyReleased(int key, int mods);
	void keyHeld(int key, int mods);
	//ButtonListener
	void buttonPressed(int button, int mods);
	void buttonReleased(int button, int mods);
	void buttonHeld(int button, int mods);
	//Getters and Setters
	void setApp(App* app);
	App* getApp();
private:
	App* app;
	/* data */
};

#undef ButtonListener
#undef KeyListener

#endif /* end of include guard: INPUTHANDLER_H_LYSLRYPJ */

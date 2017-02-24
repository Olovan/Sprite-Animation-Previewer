#include <iostream>
#include <chrono>
#include <App.h>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::duration<double, std::milli> Double_Duration;

int main(int argc, char *argv[])
{
	App app;
	app.init(argc, argv);
	double deltaTime = 0;
	//Timer (Chrono has the worst API imaginable)
	Clock::time_point start, end;
	Double_Duration duration;
	start = std::chrono::high_resolution_clock::now();
	end = std::chrono::high_resolution_clock::now();
	
	while(!app.window.shouldClose())
	{
		app.update(deltaTime);
		//Timer Stuff
		end = Clock::now();
		duration = end - start;
		deltaTime = duration.count() / 1000;
		start = end;
	}
	app.destroy();
	return 0;
}

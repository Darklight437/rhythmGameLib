#include "SoundProgramming.h"

int main() {
	
	auto app = new SoundProgramming();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}
#include "MOB_Engine.h"
#include <SDL.h>

int main(int argc, char** argv) {

	MOB_Application* app = new MOB_Application();

	std::string goName = "my first sprite";

	app->createGameObject(goName);

	app->addGraphicsToGameObject(goName, *(new std::string("Assets/Sprites/BlacksmithMainPose.png")), 14, 19);

	app->run();

	delete app;

	return 0;
}
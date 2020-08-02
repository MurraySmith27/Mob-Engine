#include "MOB_Engine.h"
#include <SDL.h>

int main(int argc, char** argv) {

	MOB_Application* app = new MOB_Application("MOB Engine Test", 800, 800);
	std::string goName = "test";
	app->CreateGameObject(goName);
	app->AddRenderingComponent(goName, "BlacksmithMainPose.png");

	app->Run();
	delete app;

	return 0;
}
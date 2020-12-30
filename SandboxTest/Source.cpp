#include "MOB_Engine.h"
#include "BasicScript.h"
#include <SDL.h>

int main(int argc, char** argv) {

	std::string spriteDir = "Assets/Sprites/";

	MOB_Application* app = new MOB_Application("MOB Engine Test", 800, 600);

	std::string goName = "test";
	app->CreateGameObject(goName);
	app->AddRenderingComponent(goName, spriteDir + "BlacksmithMainPose.png");
	app->AddTransformComponent(goName);
	app->AddSquareCollisionComponent(goName);

	std::string goName2 = "test2";
	app->CreateGameObject(goName2);
	app->AddRenderingComponent(goName2, spriteDir + "BlacksmithMainPose.png");
	app->AddTransformComponent(goName2);
	app->AddSquareCollisionComponent(goName2);
	
	BasicScript* my_script = new BasicScript(goName);

	app->AddScriptToGameObject(goName, my_script);

	app->Run();
	delete app;
	delete my_script;
	return 0;
}
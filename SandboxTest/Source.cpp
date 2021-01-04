#include "MOB_Engine.h"
#include "PlayerMovement.h"
#include "QuadTestScript.cpp"
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
	//app->AddSquareCollisionComponent(goName2);
	std::vector<MOB_Vector> vertices{ MOB_Vector(100,100), MOB_Vector(300,300), MOB_Vector(400,100), MOB_Vector(200,0) };
	app->AddQuadCollisionComponent(goName2, vertices);


	QuadTestScript* quadTestScript = new QuadTestScript(goName2);

	app->AddScriptToGameObject(goName2, quadTestScript);

	PlayerMovement* my_script = new PlayerMovement(goName);

	app->AddScriptToGameObject(goName, my_script);



	app->Run();
	delete app;
	delete my_script;
	return 0;
}
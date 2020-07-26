#include "MOB_Application.h"
#include <SDL.h>


MOB_Application::MOB_Application() {}

MOB_Application::~MOB_Application() {

}

void MOB_Application::run() {
	start();
	SDL_Event e;

	bool running = true;
	//TODO: Make this iterate once per frame instead of while(true)
	while (running) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		frameUpdate();

		graphics->graphicsUpdate();
	}
}

void MOB_Application::createGameObject(std::string name) {
	MOB_GameObject* gameObject = new MOB_GameObject(name);

	gameObjects.emplace(name, gameObject);
}


void MOB_Application::addGraphicsToGameObject(std::string gameObjectName, std::string filePath, int w, int h) {

	gameObjects.at(gameObjectName)->addGraphics(filePath, w, h);

	graphics->renderObject(gameObjects.at(gameObjectName));
}
	

void MOB_Application::start() {

	for (int i = 0; i < scriptableObjects->size(); i++) {
		MOB_Script* script = scripts.at(scriptableObjects->at(i).getName());
		if (script != NULL) {
			//TODO: Replace this with whatever python stuff works with the script
			script->start();
		}
	}
}

void MOB_Application::frameUpdate() {
	for (int i = 0; i < scriptableObjects->size(); i++) {
		MOB_Script* script = scripts.at(scriptableObjects->at(i).getName());
		if (script != NULL) {
			//TODO: Replace this with whatever python stuff works with the script
			script->frameUpdate();
		}
	}
}
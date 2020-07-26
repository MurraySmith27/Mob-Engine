#include "MOB_Application.h"
#include <SDL.h>


MOB_Application::MOB_Application() {
	scriptableObjects = new std::vector<IScriptable>();
}

MOB_Application::~MOB_Application() {

}

void MOB_Application::run() {
	start();
	SDL_Event e;

	bool running = true;
	while (running) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}



	}
}

void MOB_Application::addGameObject(MOB_GameObject gameobject);

void MOB_Application::start() {

	for (int i = 0; i < scriptableObjects->size(); i++) {
		MOB_Script* script = scriptableObjects->at(i).getScript();
		if (script != NULL) {
			scriptableObjects->at(i).getScript()->start();
		}
	}
}

void MOB_Application::frameUpdate() {
	for (int i = 0; i < scriptableObjects->size(); i++) {
		MOB_Script* script = scriptableObjects->at(i).getScript();
		if (script != NULL) {
			script->frameUpdate();
		}
	}
}
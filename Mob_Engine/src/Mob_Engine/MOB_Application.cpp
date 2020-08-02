#include "MOB_Application.h"
#include <SDL.h>


MOB_Application::MOB_Application(std::string windowTitle, int windowWidth, int windowHeight) {

	m_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	m_systems.push_back(new MOB_RenderingSystem(m_renderer));
	m_componentFactory = new MOB_ComponentFactory();
}

MOB_Application::~MOB_Application() {
	delete m_componentFactory;
	for (int i = 0; i < m_systems.size(); i++) {
		delete m_systems[i];
	}
}

void MOB_Application::AddRenderingComponent(std::string gameObjectName, std::string filePath){
	m_componentFactory->AddRenderingComponent(m_renderer, gameObjectName, filePath);
}

void MOB_Application::CreateGameObject(std::string name) {
	EntityManager::getEntityManager()->CreateGameObject(name);
}

void MOB_Application::Run() {
	
	SDL_Event e;

	bool running = true;
	//TODO: Make this iterate once per frame instead of while(true)
	while (running) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		for (int i = 0; i < m_systems.size(); i++) {
			m_systems[i]->FrameUpdate();
		}
		
	}
}

#include "MOB_Application.h"
#include <SDL.h>


MOB_Application::MOB_Application(std::string windowTitle, int windowWidth, int windowHeight) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	m_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	m_componentFactory = new MOB_ComponentFactory();
}

MOB_Application::~MOB_Application() {
	delete m_componentFactory;
	for (int i = 0; i < m_systems.size(); i++) {
		delete m_systems[i];
	}

	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void MOB_Application::AddRenderingComponent(std::string gameObjectName, std::string filePath){
	//TODO:Components are changing when these functions return, causing their members to be all wack. look into this.
	m_componentFactory->AddRenderingComponent(m_renderer, gameObjectName, filePath);
}

void MOB_Application::AddTransformComponent(std::string gameObjectName) {
	m_componentFactory->AddTransformComponent(gameObjectName);
}

void MOB_Application::CreateGameObject(std::string name) {
	MOB_EntityManager::getEntityManager()->CreateGameObject(name);
}

void MOB_Application::Run() {
	//Initialize the systems after all components have been added.
	m_systems.push_back(new MOB_RenderingSystem(m_renderer));

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

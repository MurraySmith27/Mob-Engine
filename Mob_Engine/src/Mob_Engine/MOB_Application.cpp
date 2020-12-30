#include "MOB_Application.h"
#include <SDL.h>
#include <iostream>
#include "MOB_InputManager.h""

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

void MOB_Application::AddRenderingComponent(std::string& gameObjectName, std::string& filePath){
	m_componentFactory->AddRenderingComponent(m_renderer, gameObjectName, filePath);
}

void MOB_Application::AddTransformComponent(std::string& gameObjectName) {
	m_componentFactory->AddTransformComponent(gameObjectName);
}

void MOB_Application::AddSquareCollisionComponent(std::string& gameObjectName) {
	m_componentFactory->AddSquareCollisionComponent(gameObjectName);
}

void MOB_Application::CreateGameObject(std::string& name) {
	MOB_EntityManager::getEntityManager()->CreateGameObject(name);
}


void MOB_Application::Run() {

	int FrameRate = 60;

	int MaxFrameTime = 1000 / FrameRate;

	//Initialize the systems after all components have been added. Be careful about changin this order
	m_systems.push_back(new MOB_RenderingSystem(m_renderer));
	m_systems.push_back(new MOB_TransformSystem());
	m_systems.push_back(new MOB_CollisionSystem());

	RunAllScriptStarts();

	SDL_Event e;

	bool running = true;

	int LastFrameTime = SDL_GetTicks();
	int ElapsedFrameTime = 0;
	
	MOB_InputManager* InputManager = MOB_InputManager::GetInputManager();

	while (running) {
		
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
			else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
				InputManager->ProcessKeyEvent(e);
			}
		}

		ElapsedFrameTime = SDL_GetTicks() - LastFrameTime;
		if (ElapsedFrameTime > MaxFrameTime) {

			RunAllScriptFrameUpdates();

			for (int i = 0; i < m_systems.size(); i++) {
				m_systems[i]->FrameUpdate();
			}
			InputManager->ResetInputState();
			LastFrameTime = SDL_GetTicks();
		}
		
		
	}
}

void MOB_Application::RunAllScriptFrameUpdates() {
	std::vector<IEntity*> entities = MOB_EntityManager::getEntityManager()->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		std::vector<IScript*> scripts = entities[i]->getScripts();
		for (int j = 0; j < scripts.size(); j++) {
			scripts[j]->FrameUpdate();
		}
	}
}

void MOB_Application::RunAllScriptStarts() {
	std::vector<IEntity*> entities = MOB_EntityManager::getEntityManager()->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		std::vector<IScript*> scripts = entities[i]->getScripts();
		for (int j = 0; j < scripts.size(); j++) {
			scripts[j]->Start();
		}
	}
}



void MOB_Application::AddScriptToGameObject(std::string& gameObjectName, IScript* script) {
	MOB_EntityManager::getEntityManager()->FindEntity(gameObjectName)->AddScript(script);
}

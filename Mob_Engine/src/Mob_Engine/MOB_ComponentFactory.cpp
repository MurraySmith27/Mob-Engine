#include "MOB_ComponentFactory.h"


MOB_ComponentFactory::MOB_ComponentFactory(){
}

MOB_ComponentFactory::~MOB_ComponentFactory() {

}

void MOB_ComponentFactory::AddRenderingComponent(SDL_Renderer* renderer, std::string& name, std::string& filePath) {

	//TODO: This is pretty non-extensible, look at implementing a drawablefactory?
	IDrawable* drawable = new MOB_Sprite(LoadTexture(renderer, filePath));
	MOB_RenderingComponent* component = new MOB_RenderingComponent(*drawable);
	MOB_EntityManager::getEntityManager()->FindEntity(name)->AddComponent(component);
}

void MOB_ComponentFactory::AddTransformComponent(std::string& name) {
	MOB_RenderingComponent* rendering = MOB_EntityManager::getEntityManager()->FindEntity(name)->GetComponent<MOB_RenderingComponent>();
	int x = rendering->getX();
	int y = rendering->getY();
	int w = rendering->getW();
	int h = rendering->getH();
	MOB_TransformComponent* component = new MOB_TransformComponent(x, y, w, h);
	MOB_EntityManager::getEntityManager()->FindEntity(name)->AddComponent(component);
}

void MOB_ComponentFactory::AddSquareCollisionComponent(std::string& name) {
	MOB_RenderingComponent* rendering = MOB_EntityManager::getEntityManager()->FindEntity(name)->GetComponent<MOB_RenderingComponent>();
	int x = rendering->getX();
	int y = rendering->getY();
	int w = rendering->getW();
	int h = rendering->getH();
	MOB_SquareCollisionComponent* component = new MOB_SquareCollisionComponent(x, y, w, h);
	MOB_EntityManager::getEntityManager()->FindEntity(name)->AddComponent(component);
}

SDL_Texture* MOB_ComponentFactory::LoadTexture(SDL_Renderer* renderer, std::string& filePath) {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	if (m_loadedTextures.count(filePath) == 0) {
		surface = IMG_Load(filePath.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (surface == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
		if (texture == NULL) {
			printf("Could not assign texture from surface \n");
			return NULL;
		}
		m_loadedTextures.emplace(filePath, texture);
	}
	else {
		texture = m_loadedTextures.at(filePath);
		if (texture == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
	}
	SDL_FreeSurface(surface);
	
	return texture;
}
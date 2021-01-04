#include "MOB_ComponentFactory.h"
#include <iostream>

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
	int x, y, w, h;
	if (rendering == NULL) {
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}
	else {
		x = rendering->getX();
		y = rendering->getY();
		w = rendering->getW();
		h = rendering->getH();
	}
	MOB_TransformComponent* component = new MOB_TransformComponent(x, y, w, h);
	MOB_EntityManager::getEntityManager()->FindEntity(name)->AddComponent(component);
}

void MOB_ComponentFactory::AddSquareCollisionComponent(std::string& name) {
	MOB_TransformComponent* transform = MOB_EntityManager::getEntityManager()->FindEntity(name)->GetComponent<MOB_TransformComponent>();
	if (transform == NULL) {
		std::cout << "Could not create square collision component as this entity has no transform component." << std::endl;
	}
	//Here it will crash if transform is NULL. intended behaviour. TODO: Create a custom exception for this.
	int x = transform->getX();
	int y = transform->getY();
	int w = transform->getW();
	int h = transform->getH();
	MOB_SquareCollisionComponent* component = new MOB_SquareCollisionComponent(x, y, w, h);
	MOB_EntityManager::getEntityManager()->FindEntity(name)->AddComponent(component);
}

void MOB_ComponentFactory::AddQuadCollisionComponent(std::string& name, std::vector<MOB_Vector> vertices) {
	MOB_QuadCollisionComponent* component = new MOB_QuadCollisionComponent(vertices);
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
#include "MOB_RenderingSystem.h"


MOB_RenderingSystem::MOB_RenderingSystem(SDL_Window* window) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	ComponentTuple renderingComponents;
	EntityManager* entityManager = EntityManager::getEntityManager();

	std::vector<IEntity> entities = entityManager->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		ComponentTuple components;
		components.transform = entities[i].GetComponent<MOB_TransformComponent>();
		components.rendering = entities[i].GetComponent<MOB_RenderingComponent>();
		if (components.transform != NULL && components.rendering != NULL){
			m_componentTuples.push_back(components);
		}
	}
}

MOB_RenderingSystem::~MOB_RenderingSystem() {
	SDL_DestroyRenderer(m_renderer);
}


void MOB_RenderingSystem::Start() {

}

SDL_Texture* MOB_RenderingSystem::loadTexture(std::string filePath) {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	if (m_loadedTextures.count(filePath) == 0) {
		surface = IMG_Load(filePath.c_str());
		texture = SDL_CreateTextureFromSurface(m_renderer, surface);
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


void MOB_RenderingSystem::clear() {
	SDL_RenderClear(m_renderer);
}

void MOB_RenderingSystem::flip() {
	SDL_RenderPresent(m_renderer);
}


void MOB_RenderingSystem::FrameUpdate() {
	clear();
	//TODO: Fix this tomorow this doesn't know that gameobjects are now accessible directly from systems.
	for (int i = 0; i < m_componentTuples.size(); i++) {
		RenderGameObject(m_componentTuples[i].rendering, m_componentTuples[i].transform);
	}
	flip();
}

void MOB_RenderingSystem::RenderGameObject(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	UpdatePositionFromTransform(renderingComp, transformComp);
	SDL_RenderCopy(m_renderer, renderingComp->drawable->getTexture(), &renderingComp->drawable->getSrcRect(), &renderingComp->drawable->getDestRect());
}

void MOB_RenderingSystem::UpdatePositionFromTransform(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	renderingComp->drawable->setDestinationRect(transformComp->getX(), transformComp->getY(), transformComp->getW(), transformComp->getH());
}


void MOB_RenderingSystem::changeRenderBackgroundColor(int r, int g, int b) {
	SDL_SetRenderDrawColor(m_renderer, r, g, b, 0xff);
}
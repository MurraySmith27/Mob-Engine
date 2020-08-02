#include "MOB_RenderingSystem.h"


MOB_RenderingSystem::MOB_RenderingSystem(SDL_Renderer* renderer) : m_renderer(renderer) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	ComponentTuple renderingComponents;
	EntityManager* entityManager = EntityManager::getEntityManager();

	std::vector<IEntity*> entities = entityManager->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		ComponentTuple components;
		components.transform = entities[i]->GetComponent<MOB_TransformComponent>();
		components.rendering = entities[i]->GetComponent<MOB_RenderingComponent>();
		if (components.transform != NULL && components.rendering != NULL){
			m_componentTuples.push_back(components);
		}
	}
}

MOB_RenderingSystem::~MOB_RenderingSystem() {

}




void MOB_RenderingSystem::Start() {

}


void MOB_RenderingSystem::FrameUpdate() {
	SDL_RenderClear(m_renderer);
	//TODO: Fix this tomorow this doesn't know that gameobjects are now accessible directly from systems.
	for (int i = 0; i < m_componentTuples.size(); i++) {
		RenderGameObject(m_componentTuples[i].rendering, m_componentTuples[i].transform);
	}
	SDL_RenderPresent(m_renderer);
}

void MOB_RenderingSystem::RenderGameObject(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	UpdatePositionFromTransform(renderingComp, transformComp);
	SDL_RenderCopy(m_renderer, renderingComp->drawable->getTexture(), &renderingComp->drawable->getSrcRect(), &renderingComp->drawable->getDestRect());
}

void MOB_RenderingSystem::UpdatePositionFromTransform(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	renderingComp->drawable->setDestinationRect(transformComp->getX(), transformComp->getY(), transformComp->getW(), transformComp->getH());
}


void MOB_RenderingSystem::ChangeRenderBackgroundColor(SDL_Renderer* renderer, int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xff);
}
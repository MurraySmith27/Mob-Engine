#include "MOB_RenderingSystem.h"

//TODO: Delete this and create a logging system.
#include <iostream>


MOB_RenderingSystem::MOB_RenderingSystem(SDL_Renderer* renderer) : m_renderer(renderer) {

	std::vector<IEntity*> entities = MOB_EntityManager::getEntityManager()->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		std::shared_ptr<ComponentTuple> components = std::make_shared<ComponentTuple>();
		components->transform = entities[i]->GetComponent<MOB_TransformComponent>();
		if (components->transform == NULL) {
			std::cout << "Could not load in transform component for gameobject named: " << entities[i]->getName() << "\n";
		}
		components->rendering = entities[i]->GetComponent<MOB_RenderingComponent>();
		if (components->rendering == NULL) {
			std::cout << "Could not load in rendering component for gameobject named: " << entities[i]->getName() << "\n";
		}
		if (components->transform != NULL && components->rendering != NULL) {
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
		RenderGameObject(m_componentTuples[i]->rendering, m_componentTuples[i]->transform);
	}
	SDL_RenderPresent(m_renderer);
}

void MOB_RenderingSystem::RenderGameObject(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	UpdatePositionFromTransform(renderingComp, transformComp);
	SDL_RenderCopyEx(m_renderer, renderingComp->drawable.getTexture(), &renderingComp->drawable.getSrcRect(), &renderingComp->drawable.getDestRect(), transformComp->getAngle(), NULL, transformComp->getFlip());
}

void MOB_RenderingSystem::UpdatePositionFromTransform(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp) {
	//TODO: this needs fixing. It's assigning random ints. Probably because of an unitialized pointer. renderingComp?
	renderingComp->drawable.setDestinationRect(&transformComp->getPositionRect());
}


void MOB_RenderingSystem::ChangeRenderBackgroundColor(SDL_Renderer* renderer, int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xff);
}
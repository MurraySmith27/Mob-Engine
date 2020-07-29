#include "MOB_RenderingComponent.h"


MOB_RenderingComponent::MOB_RenderingComponent(MOB_GameObject* attachedGameObject, IDrawable* attachedDrawable) {
	gameObject = attachedGameObject;
	drawable = attachedDrawable;
}

//Do not deallocate gameObject here
MOB_RenderingComponent::~MOB_RenderingComponent() {
	delete drawable;
}

void MOB_RenderingComponent::renderGameObject(SDL_Renderer* renderer, MOB_TransformComponent* transform) {
	updatePositionFromTransform(transform);
	SDL_RenderCopy(renderer, drawable->getTexture(), &drawable->getSrcRect(), &drawable->getDestRect());
}

void MOB_RenderingComponent::updatePositionFromTransform(MOB_TransformComponent* transform) {
	drawable->setDestinationRect(transform->getX(), transform->getY(), transform->getW(), transform->getH());
}

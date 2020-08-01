#include "MOB_RenderingComponent.h"


MOB_RenderingComponent::MOB_RenderingComponent(IDrawable* attachedDrawable) {
	drawable = attachedDrawable;
	componentType = "rendering";
}

//Do not deallocate gameObject here
MOB_RenderingComponent::~MOB_RenderingComponent() {
	delete drawable;
}

void MOB_RenderingComponent::RenderGameObject(SDL_Renderer* renderer, MOB_TransformComponent* transform) {
	UpdatePositionFromTransform(transform);
	SDL_RenderCopy(renderer, drawable->getTexture(), &drawable->getSrcRect(), &drawable->getDestRect());
}

void MOB_RenderingComponent::UpdatePositionFromTransform(MOB_TransformComponent* transform) {
	drawable->setDestinationRect(transform->getX(), transform->getY(), transform->getW(), transform->getH());
}


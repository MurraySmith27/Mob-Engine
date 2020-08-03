#include "MOB_RenderingComponent.h"


MOB_RenderingComponent::MOB_RenderingComponent(IDrawable* attachedDrawable) {
	drawable = attachedDrawable;
}

MOB_RenderingComponent::~MOB_RenderingComponent() {
	delete drawable;
}

std::string MOB_RenderingComponent::componentType;
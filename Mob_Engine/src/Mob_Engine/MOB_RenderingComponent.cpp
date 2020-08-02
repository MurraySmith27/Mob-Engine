#include "MOB_RenderingComponent.h"


MOB_RenderingComponent::MOB_RenderingComponent(IDrawable* attachedDrawable) {
	drawable = attachedDrawable;
	componentType = "rendering";
}

MOB_RenderingComponent::~MOB_RenderingComponent() {
	delete drawable;
}
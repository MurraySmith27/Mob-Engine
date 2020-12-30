#include "MOB_RenderingComponent.h"


MOB_RenderingComponent::MOB_RenderingComponent(IDrawable& attachedDrawable) {
	drawable = attachedDrawable;
	componentType = "rendering";
}

MOB_RenderingComponent::~MOB_RenderingComponent() {

}

int MOB_RenderingComponent::getX() {
	return drawable.getDestRect().x;
}

int MOB_RenderingComponent::getY() {
	return drawable.getDestRect().y;
}

int MOB_RenderingComponent::getW() {
	return drawable.getDestRect().w;
}

int MOB_RenderingComponent::getH() {
	return drawable.getDestRect().h;
}

std::string MOB_RenderingComponent::componentType;
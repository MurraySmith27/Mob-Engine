#include "MOB_GameObject.h"


MOB_GameObject::MOB_GameObject() {

}

MOB_GameObject::~MOB_GameObject() {

}

void MOB_GameObject::addGraphics(std::string& filePath, int w, int h) {
	graphicalComponent = new MOB_Sprite(filePath, w, h);
}
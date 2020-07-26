#include "MOB_GameObject.h"


MOB_GameObject::MOB_GameObject(std::string initName) : name(initName){
}

MOB_GameObject::~MOB_GameObject() {

}

void MOB_GameObject::addGraphics(std::string& filePath, int w, int h) {
	graphicFilePath = filePath;
	graphicW = w;
	graphicH = h;
}
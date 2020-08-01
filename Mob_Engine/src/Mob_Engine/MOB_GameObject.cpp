#include "MOB_GameObject.h"

MOB_GameObject::MOB_GameObject(std::string name, int initID) : IEntity(initID), m_name(name) {}

MOB_GameObject::~MOB_GameObject() {

}

std::string MOB_GameObject::getName(){
	return m_name;
}

void MOB_GameObject::OnBirth() {
	//TODO: figure out a better solution for this and OnDeath();
}

void MOB_GameObject::OnDeath() {

}


#include "MOB_GameObject.h"

MOB_GameObject::MOB_GameObject(int initID, std::string name) : m_ID(initID), m_name(name) {}

MOB_GameObject::~MOB_GameObject() {

}

void MOB_GameObject::OnBirth() {
	//TODO: figure out a better solution for this and OnDeath();
}

void MOB_GameObject::OnDeath() {

}


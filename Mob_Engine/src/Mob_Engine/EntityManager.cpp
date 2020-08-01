#include "EntityManager.h"


std::vector<IEntity>& EntityManager::getEntities() {
	return this->m_entities;
}

void EntityManager::createGameObject(std::string name) {
	MOB_GameObject* gameObject = new MOB_GameObject(name, m_IDGenerator);

	m_entities.push_back(*gameObject);
}


EntityManager* EntityManager::getEntityManager() {

	if (!instance) {
		instance = new EntityManager();
	}
	return instance;
}
#include "EntityManager.h"

std::vector<IEntity*>& EntityManager::getEntities() {
	return m_entities;
}

void EntityManager::CreateGameObject(std::string name) {
	MOB_GameObject* gameObject = new MOB_GameObject(m_IDGenerator, name);

	m_entities.push_back(gameObject);
}


EntityManager* EntityManager::getEntityManager() {

	if (!m_Initialized) {
		instance = new EntityManager;
		m_Initialized = true;
	}
	return instance;
}

IEntity* EntityManager::findEntity(std::string name) {
	for (int i = 0; i < m_entities.size(); i++) {
		if (m_entities[i]->getName().compare(name) == 0) {
			return m_entities[i];
		}
	}
}

EntityManager* EntityManager::instance;

bool EntityManager::m_Initialized;
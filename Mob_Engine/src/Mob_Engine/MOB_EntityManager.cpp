#include "MOB_EntityManager.h"

std::vector<IEntity*>& MOB_EntityManager::getEntities() {
	return m_entities;
}

void MOB_EntityManager::CreateGameObject(std::string name) {
	MOB_GameObject* gameObject = new MOB_GameObject(m_IDGenerator, name);

	m_entities.push_back(gameObject);
}


MOB_EntityManager* MOB_EntityManager::getEntityManager() {

	if (!m_Initialized) {
		instance = new MOB_EntityManager;
		m_Initialized = true;
	}
	return instance;
}

IEntity* MOB_EntityManager::findEntity(std::string name) {
	for (int i = 0; i < m_entities.size(); i++) {
		if (m_entities[i]->getName() == name) {
			return m_entities[i];
		}
	}
}

MOB_EntityManager* MOB_EntityManager::instance;

bool MOB_EntityManager::m_Initialized;
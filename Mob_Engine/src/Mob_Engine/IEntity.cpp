#include "IEntity.h"


IEntity::IEntity(int ID) : m_ID(ID) {}

IEntity::~IEntity() {
	for (std::map<std::string, IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); it++) {
		delete it->second;
	}
}

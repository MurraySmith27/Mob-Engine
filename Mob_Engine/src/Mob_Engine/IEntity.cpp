#include "IEntity.h"


IEntity::~IEntity() {
	for (std::map<std::string, IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); it++) {
		delete it->second;
	}
}

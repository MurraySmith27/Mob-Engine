#include "IEntity.h"


IEntity::IEntity(int initID, std::string& initName) : m_ID(initID), m_name(initName){}

IEntity::~IEntity() {
	
}

void IEntity::OnBirth() {

}

void IEntity::OnDeath() {

}

#include "BasicScript.h"
#include "MOB_Engine.h"

BasicScript::BasicScript(std::string& entityName) : IScript(entityName){

}

void BasicScript::FrameUpdate() {
	transform = MOB_EntityManager::getEntityManager()->FindEntity(m_entityName)->GetComponent<MOB_TransformComponent>();
	transform->Translate(1, 1);
}

void BasicScript::Start() {
	transform = MOB_EntityManager::getEntityManager()->FindEntity(m_entityName)->GetComponent<MOB_TransformComponent>();
	transform->Translate(0, 10);
}
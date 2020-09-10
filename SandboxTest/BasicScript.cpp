#include "BasicScript.h"
#include "MOB_Engine.h"

#include <iostream>

BasicScript::BasicScript(std::string& entityName) : IScript(entityName){

}

void BasicScript::FrameUpdate() {
	transform = MOB_EntityManager::getEntityManager()->FindEntity(m_entityName)->GetComponent<MOB_TransformComponent>();
	transform->Translate(-1, -1);
	transform->RotateBy(10);
}

void BasicScript::Start() {
	transform = MOB_EntityManager::getEntityManager()->FindEntity(m_entityName)->GetComponent<MOB_TransformComponent>();
	transform->Translate(400, 400);
}

void BasicScript::OnCollision(std::string& entity1name, std::string& entity2name) {
	std::cout << "Collision in script stuff!" << std::endl;
}
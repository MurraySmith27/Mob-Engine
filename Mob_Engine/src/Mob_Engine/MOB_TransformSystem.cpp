#include "MOB_TransformSystem.h"

//TODO: Delete this and create a logging system.
#include <iostream>

MOB_TransformSystem::MOB_TransformSystem() {
	
}

//Don't delete components here, that's done from entity destructor
MOB_TransformSystem::~MOB_TransformSystem() {

}

void MOB_TransformSystem::ChangePosition(std::string& gameObjectName, int x, int y) {
	FetchTransform(gameObjectName)->ChangePosition(x, y);
}

void MOB_TransformSystem::Translate(std::string& gameObjectName, int moveX, int moveY) {
	FetchTransform(gameObjectName)->Translate(moveX, moveY);
}

void MOB_TransformSystem::Stretch(std::string& gameObjectName, int w, int h) {
	FetchTransform(gameObjectName)->Stretch(w, h);
}

void MOB_TransformSystem::RotateBy(std::string& gameObjectName, double angle) {
	FetchTransform(gameObjectName)->RotateBy(angle);
}

void MOB_TransformSystem::SetRotation(std::string& gameObjectName, double angle) {
	FetchTransform(gameObjectName)->SetRotation(angle);
}

void MOB_TransformSystem::Flip(std::string& gameObjectName, bool flipHorizontal, bool flipVertical) {
	FetchTransform(gameObjectName)->Flip(flipHorizontal, flipVertical);
}

MOB_TransformComponent* MOB_TransformSystem::FetchTransform(std::string& gameObjectName) {
	MOB_EntityManager* entityManager = MOB_EntityManager::getEntityManager();
	IEntity* entity = entityManager->FindEntity(gameObjectName);
	if (entity == NULL) {
		std::cout << "Error in MOB_TransformSystem. No entity exists with name " << gameObjectName << "\n";
	}
	MOB_TransformComponent* transform = entity->GetComponent<MOB_TransformComponent>();
	if (transform == NULL) {
		std::cout << "Error in MOB_TransformSystem. The entity with name " << gameObjectName <<
			" has no transform component." << "\n";
	}
	return transform;
}

void MOB_TransformSystem::Start() {

}

void MOB_TransformSystem::FrameUpdate() {

}

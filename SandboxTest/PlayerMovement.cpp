#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(std::string& entityName) : IScript(entityName) {
	transform = MOB_EntityManager::getEntityManager()->FindEntity(entityName)->GetComponent<MOB_TransformComponent>();
	inputManager = MOB_InputManager::GetInputManager();
}

PlayerMovement::~PlayerMovement() {

}

void PlayerMovement::Start() {
	transform->Translate(400, 300);
	transform->Stretch(106, 112);
}


void PlayerMovement::FrameUpdate() {

	velocity = MOB_Vector(0, 0);

	if (inputManager->IsKeyHeld("W")) {
		velocity = velocity + up_;
	}
	else if (inputManager->IsKeyHeld("S")) {
		velocity = velocity - up_;
	}
	else if (inputManager->IsKeyHeld("A")) {
		velocity = velocity - right_;
	}
	else if (inputManager->IsKeyHeld("D")) {
		velocity = velocity + right_;
	}
	else {
		velocity = MOB_Vector(0, 0);
	}

	transform->Translate(velocity.getX(), velocity.getY());
}


void PlayerMovement::OnCollision(std::string& entity1Name, std::string& entity2Name) {

}
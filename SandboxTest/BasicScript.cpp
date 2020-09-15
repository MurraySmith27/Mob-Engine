#include "BasicScript.h"
#include "MOB_Engine.h"

#include <iostream>

BasicScript::BasicScript(std::string& entityName) : IScript(entityName){
	transform = MOB_EntityManager::getEntityManager()->FindEntity(m_entityName)->GetComponent<MOB_TransformComponent>();
	InputManager = MOB_InputManager::GetInputManager();
	velx = 0;
	vely = 0;
}

void BasicScript::FrameUpdate() {
	
	transform->Translate(velx, vely);
	std::cout << "(" << transform->getX() << ", " << transform->getY() << ")" << std::endl;

	if (InputManager->WasKeyPressed("W")) {
		vely--;
	}
	if (InputManager->WasKeyPressed("A")) {
		velx--;
	}
	if (InputManager->WasKeyPressed("S")) {
		vely++;
	}
	if (InputManager->WasKeyPressed("D")) {
		velx++;
	}
	if (InputManager->WasMousePressed()) {
		std::cout << "Mouse Pressed!" << std::endl;
	}
	if (InputManager->WasMouseReleased()) {
		std::cout << "Mouse Released!" << std::endl;
	}
}

void BasicScript::Start() {
	transform->Translate(400, 400);
	transform->RotateBy(45);
}

void BasicScript::OnCollision(std::string& entity1name, std::string& entity2name) {
	std::cout << "Collision in script stuff!" << std::endl;
}
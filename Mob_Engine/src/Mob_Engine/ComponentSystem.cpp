#include "ComponentSystem.h"

void ComponentSystem::frameUpdate() {
	for (int i = 0; i < componentHandlers.size(); i++) {
		componentHandlers[i].frameUpdate();
	}
}

void ComponentSystem::start() {
	for (int i = 0; i < componentHandlers.size(); i++) {
		componentHandlers[i].start();
	}
}

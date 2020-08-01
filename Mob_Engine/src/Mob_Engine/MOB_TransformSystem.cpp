#include "MOB_TransformSystem.h"


MOB_TransformComponent MOB_TransformSystem::fetchTransform(std::string gameObjectName) {
	return *(transformComponents.at(gameObjectName));
}
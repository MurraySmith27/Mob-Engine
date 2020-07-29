#include "MOB_TransformComponentHandler.h"


MOB_TransformComponent MOB_TransformComponentHandler::fetchTransform(std::string gameObjectName) {
	return *(transformComponents.at(gameObjectName));
}
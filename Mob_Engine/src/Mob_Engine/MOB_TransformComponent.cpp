#include "MOB_TransformComponent.h"


MOB_TransformComponent::MOB_TransformComponent() {
}

//Make sure not to delete the Game Object from here, as it will cause deallocation errors.
MOB_TransformComponent::~MOB_TransformComponent() {

}


void MOB_TransformComponent::changePosition(int x, int y) {
	if (x != -1) {
		_x = x;
	} else if (y != -1) {
		_y = y;
	}
}

void MOB_TransformComponent::stretch(int w, int h) {
	if (w != -1) {
		_w = w;
	}
	else if (h != -1) {
		_h = h;
	}
}

std::string MOB_TransformComponent::componentType;

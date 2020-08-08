#include "MOB_TransformComponent.h"


MOB_TransformComponent::MOB_TransformComponent(){
	componentType = "transform";
}

//Make sure not to delete the Game Object from here, as it will cause deallocation errors.
MOB_TransformComponent::~MOB_TransformComponent() {

}

void MOB_TransformComponent::RotateBy(double deltaAngle) {
	angle += deltaAngle;
}

void MOB_TransformComponent::SetRotation(double newAngle) {
	angle = newAngle;
}

void MOB_TransformComponent::Translate(int moveX, int moveY) {
	if (moveX != 0) {
		m_positionRect.x += moveX;
	}
	if (moveY != 0) {
		m_positionRect.y += moveY;
	}
}


void MOB_TransformComponent::ChangePosition(int x, int y) {
	if (x != -1) {
		m_positionRect.x = x;
	}
	if (y != -1) {
		m_positionRect.y = y;
	}
}

void MOB_TransformComponent::Stretch(int w, int h) {
	if (w != -1) {
		m_positionRect.w = w;
	}
	else if (h != -1) {
		m_positionRect.h = h;
	}
}

void MOB_TransformComponent::Flip(bool flipHorizontal, bool flipVertical) {
	if (flipHorizontal && flipVertical) {
		flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	}
	else if (flipHorizontal) {
		flip = (SDL_RendererFlip)SDL_FLIP_HORIZONTAL;
	}
	else if (flipVertical) {
		flip = (SDL_RendererFlip)SDL_FLIP_VERTICAL;
	}
	else {
		flip = (SDL_RendererFlip)SDL_FLIP_NONE;
	}
}

std::string MOB_TransformComponent::componentType;

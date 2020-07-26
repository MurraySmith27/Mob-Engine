#include "MOB_Sprite.h"

MOB_Sprite::MOB_Sprite(std::string inputName, SDL_Texture* texture, int w, int h) {
	_texture = texture;
	setDestinationRect(0, 0, w, h);
	setSourceRect(0, 0, w, h);
	name = inputName;
};
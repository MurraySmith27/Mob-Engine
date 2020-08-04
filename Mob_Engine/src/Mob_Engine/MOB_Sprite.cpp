#include "MOB_Sprite.h"

//TODO: remove this
#include <iostream>

MOB_Sprite::MOB_Sprite(SDL_Texture* texture) {
	int w_p; 
	int h_p;
	SDL_QueryTexture(texture, NULL, NULL, &w_p, &h_p);
	std::cout << w_p << "\n";
	_texture = texture;
	//setDestinationRect(0, 0, *w_p, *h_p);
	_destinationRectangle.w = w_p;
	_destinationRectangle.h = h_p;
	setSourceRect(0, 0, w_p, h_p);
}

void MOB_Sprite::setDestinationRect(int newX, int newY, int newW, int newH) {
	if (newX != -1) {
		_destinationRectangle.x = newX;
	}
	if (newY != -1) {
		_destinationRectangle.y = newY;
	}
	if (newW != -1) {
		_destinationRectangle.w = newW;
	}
	if (newH != -1) {
		_destinationRectangle.h = newH;
	}
}
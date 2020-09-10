#include "MOB_Sprite.h"

//TODO: remove this
#include <iostream>

MOB_Sprite::MOB_Sprite(SDL_Texture* texture) {
	int w_p; 
	int h_p;
	SDL_QueryTexture(texture, NULL, NULL, &w_p, &h_p);
	_texture = texture;
	//setDestinationRect(0, 0, *w_p, *h_p);
	_destinationRectangle.w = w_p;
	_destinationRectangle.h = h_p;
	setSourceRect(0, 0, w_p, h_p);
}


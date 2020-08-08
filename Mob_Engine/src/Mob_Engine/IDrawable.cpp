#include "IDrawable.h"

//TODO: Delete this
#include <iostream>


IDrawable::~IDrawable() {
	SDL_DestroyTexture(_texture);
	delete _texture;
}

void IDrawable::setDestinationRect(SDL_Rect* destinationRect) {
	_destinationRectangle.x = destinationRect->x;
	_destinationRectangle.y = destinationRect->y;
	if (destinationRect->w != 0) {
		_destinationRectangle.w = destinationRect->w;
	}
	if (destinationRect->h != 0) {
		_destinationRectangle.h = destinationRect->h;
	}
}

void IDrawable::setSourceRect(int newX, int newY, int newW, int newH) {
	_sourceRectangle.x = newX;
	_sourceRectangle.y = newY;
	_sourceRectangle.w = newW;
	_sourceRectangle.h = newH;
}


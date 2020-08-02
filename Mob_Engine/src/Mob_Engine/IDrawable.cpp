#include "IDrawable.h"


IDrawable::~IDrawable() {
	SDL_DestroyTexture(_texture);
	delete _texture;
}

void IDrawable::setDestinationRect(int newX, int newY, int newW, int newH) {
	_destinationRectangle.x = newX;
	_destinationRectangle.y = newY;
	if (newW != NULL)
		_destinationRectangle.w = newW;
	if (newH != NULL)
		_destinationRectangle.h = newH;
}

void IDrawable::setSourceRect(int newX, int newY, int newW, int newH) {
	_sourceRectangle.x = newX;
	_sourceRectangle.y = newY;
	_sourceRectangle.w = newW;
	_sourceRectangle.h = newH;
}
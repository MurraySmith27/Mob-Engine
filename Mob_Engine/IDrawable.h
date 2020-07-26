#ifndef DRAWABLE_HEADER
#define DRAWABLE_HEADER
#include <SDL.h>
#include <string>
#include <map>
#include <SDL_image.h>
/* An interface describing an object that can be drawn to the screen in the Graphics class.
*/
class IDrawable {
public:


	/*Change the destination rectangle of the drawable. The object will then be rendered at
		(<x>,<y>) with width <w> and height <h>.
	*/
	virtual void setDestinationRect(int newX, int newY, int newW, int newH) {
		_destinationRectangle.x = newX;
		_destinationRectangle.y = newY;
		_destinationRectangle.w = newW;
		_destinationRectangle.h = newH;
	}

	/*Change the source rectangle of the drawable. The object will be grabbed from the rectangle specified here in the
	drawable's source png.
	*/
	virtual void setSourceRect(int newX, int newY, int newW, int newH) {
		_sourceRectangle.x = newX;
		_sourceRectangle.y = newY;
		_sourceRectangle.w = newW;
		_sourceRectangle.h = newH;
	}

	/*Return rectangle describing the location on the screen at which the drawable will be drawn.
	*/
	virtual SDL_Rect getDestRect() const {
		return _destinationRectangle;
	}

	/*Return the name of the drawable.
	*/
	std::string getName() {
		return name;
	}

	/* Return the rectangle describing which location on the spritesheet contains the sprite.
	*/
	virtual SDL_Rect getSrcRect() const {
		return _sourceRectangle;
	}

	/* Return the SDL_Surface* object that contains the spriteSheet.
	*/
	virtual SDL_Texture* getTexture() const {
		return _texture;
	}

protected:
	//TODO: make some solution to access this from every instance of IDrawable or subclasses.
	std::string name;
	SDL_Texture* _texture = nullptr;
	SDL_Rect _sourceRectangle = { 0,0,0,0 };
	SDL_Rect _destinationRectangle = { 0,0,0,0 };
};
#endif
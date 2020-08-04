#ifndef SPRITE_HEADER
#define SPRITE_HEADER
#include "IDrawable.h"
#include <SDL.h>
#include "Core.h"
class MOB_API MOB_Sprite : public IDrawable
{
public:
	MOB_Sprite(SDL_Texture* texture);

	void setDestinationRect(int newX = -1, int newY = -1, int newW = -1, int newH = -1) override;
};
#endif


#ifndef SPRITE_HEADER
#define SPRITE_HEADER
#include "IDrawable.h"
#include <SDL.h>
#include "Core.h"
class MOB_API MOB_Sprite : public IDrawable
{
public:
	MOB_Sprite(SDL_Texture* texture, int w, int h);
};
#endif


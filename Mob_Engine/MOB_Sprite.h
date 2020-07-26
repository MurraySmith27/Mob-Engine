#ifndef SPRITE_HEADER
#define SPRITE_HEADER
#include "IDrawable.h"
#include <SDL.h>
class MOB_Sprite : public IDrawable
{
public:
	MOB_Sprite(std::string name, SDL_Texture* texture, int w, int h);
	~MOB_Sprite();
};
#endif


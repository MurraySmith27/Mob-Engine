#ifndef RENDERINGCOMPONENT_HEADER
#define RENDERINGCOMPONENT_HEADER

#include <SDL.h>
#include "MOB_GameObject.h"
#include "MOB_TransformComponent.h"
#include "IDrawable.h"

class MOB_API MOB_RenderingComponent : public IComponent
{
public:

	/* Initializes a new Rendering Component attached to the specified Game Object.
	*/
	MOB_RenderingComponent(IDrawable& drawable);

	~MOB_RenderingComponent();

	int getX();

	int getY();

	int getW();
	
	int getH();

	/*Change the source rectangle of the drawable. The object will be grabbed from the rectangle specified here in the
	drawable's source png.
	*/
	void setSourceRect(int newX, int newY, int newW, int newH);

	SDL_Rect getSourceRect();


	/* The drawable associated with the component.
	*/
	IDrawable drawable;

	static std::string componentType;

};
#endif


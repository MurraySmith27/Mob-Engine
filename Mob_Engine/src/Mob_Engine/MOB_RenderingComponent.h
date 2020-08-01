#include <SDL.h>
#include "MOB_GameObject.h"
#include "IDrawable.h"

class MOB_API MOB_RenderingComponent : public IComponent
{
public:

	/* Initializes a new Rendering Component attached to the specified Game Object.
	*/
	MOB_RenderingComponent(IDrawable* drawable);

	~MOB_RenderingComponent();

	/* The drawable associated with the component.
	*/
	IDrawable* drawable;

};


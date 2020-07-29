#include <SDL.h>
#include "MOB_GameObject.h"
#include "IDrawable.h"
#include "MOB_TransformComponent.h"
class MOB_API MOB_RenderingComponent
{
public:

	/* Pointer to the Game Object that this component is attached to.
	*/
	MOB_GameObject* gameObject;

	/* Initializes a new Rendering Component attached to the specified Game Object.
	*/
	MOB_RenderingComponent(MOB_GameObject* gameObject, IDrawable* drawable);

	~MOB_RenderingComponent();

	/* Copies the attached drawable to the renderer.
	*/
	void renderGameObject(SDL_Renderer* renderer, MOB_TransformComponent* transform);

private:

	void updatePositionFromTransform(MOB_TransformComponent* transform);

	IDrawable* drawable;

};


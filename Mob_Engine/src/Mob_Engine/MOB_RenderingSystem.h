#ifndef RENDERINGSYSTEM_HEADER
#define RENDERINGSYSTEM_HEADER

#include "MOB_RenderingComponent.h"
#include "MOB_EntityManager.h"
#include <vector>
#include "ISystem.h"
#include <SDL.h>
#include "MOB_Sprite.h"
/* Handles all Rendering in the program. All methods entities operated on here have a transform component and a rendering component.
*/
class MOB_API MOB_RenderingSystem : public ISystem
{
public:
	

	/* Initializes a new RenderingSystem using window to initialize the renderer.
	*/
	MOB_RenderingSystem(SDL_Renderer* renderer);

	~MOB_RenderingSystem();



	/* Called on startup.
	*/
	void Start();

	/* Called once per frame.
	*/
	void FrameUpdate();

	/* Changes the background color of the screen.
	*/
	void ChangeRenderBackgroundColor(SDL_Renderer* renderer, int r, int g, int b);


private:

	/* Copies the texture from renderingComp to the renderer using position information from transformComp
	*/
	void RenderGameObject(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp);

	/* Updates the position of the entity to be rendered at the right place.
	*/
	void UpdatePositionFromTransform(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp);

	/* Struct containing the components required for the entity to interact with this system.
	*/
	struct ComponentTuple {
		MOB_RenderingComponent* rendering;
		MOB_TransformComponent* transform;
	};
	
	/* Storage of all component Tuples. This keeps the component data grouped.
	*/
	std::vector<ComponentTuple*> m_componentTuples;

	SDL_Renderer* m_renderer;

};
#endif


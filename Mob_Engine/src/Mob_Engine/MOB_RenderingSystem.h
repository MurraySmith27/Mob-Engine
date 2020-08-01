#include "MOB_TransformSystem.h"
#include "MOB_RenderingComponent.h"
#include "EntityManager.h"
#include <vector>
#include "ISystem.h"
#include <SDL.h>
/* Handles all RenderingComponents.
*/
class MOB_RenderingSystem : public ISystem
{
public:
	

	/* Initializes a new RenderingSystem using window to initialize the renderer.
	*/
	MOB_RenderingSystem(SDL_Window* window);

	~MOB_RenderingSystem();

	/* Called on program startup.
	*/
	void Start();

	/* Called once per frame.
	*/
	void FrameUpdate();

	/* Changes the background color of the screen.
	*/
	void changeRenderBackgroundColor(int r, int g, int b);

	/* Copies the texture from renderingComp to the renderer using position information from transformComp
	*/
	void RenderGameObject(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp);

	/* Updates the position of the entity to be rendered at the right place.
	*/
	void UpdatePositionFromTransform(MOB_RenderingComponent* renderingComp, MOB_TransformComponent* transformComp);


private:

	/* Clear the renderer of all current images.
	*/
	void clear();

	/* Update the renderer and display the buffered images to the screen.
	*/
	void flip();

	/* Loads and returns a texture at file path specified.
	*/
	SDL_Texture* loadTexture(std::string filePath);

	/* Struct containing the components required for the entity to interact with this system.
	*/
	struct ComponentTuple {
		MOB_RenderingComponent* rendering;
		MOB_TransformComponent* transform;
	};
	
	/* Storage of all component Tuples. This keeps the component data grouped.
	*/
	std::vector<ComponentTuple> m_componentTuples;

	/* List of spritesheets that have already been loaded.
	*/
	std::map<std::string, SDL_Texture*> m_loadedTextures;

	SDL_Renderer* m_renderer;
};


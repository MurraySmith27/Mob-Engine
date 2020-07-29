#include "MOB_TransformComponentHandler.h"
#include "MOB_RenderingComponent.h"
#include <vector>
#include "IComponentHandler.h"
#include <SDL.h>
/* Handles all RenderingComponents.
*/
class MOB_RenderingComponentHandler : public IComponentHandler
{
public:

	/* Vector storing all rendering components.
	*/
	std::vector<MOB_RenderingComponent> renderingComponentList;

	/* Initializes a new RenderingComponentHandler using window to initialize the renderer.
	*/
	MOB_RenderingComponentHandler(SDL_Window* window);

	~MOB_RenderingComponentHandler();

	/* Called on program startup.
	*/
	void start();

	/* Called once per frame.
	*/
	void frameUpdate();

	/* Changes the background color of the screen.
	*/
	void changeRenderBackgroundColor(int r, int g, int b);


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

	/* List of spritesheets that have already been loaded.
	*/
	std::map<std::string, SDL_Texture*> loadedTextures;

	SDL_Renderer* _renderer;
};


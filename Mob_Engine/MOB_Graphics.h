

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "IDrawable.h"
#include "MOB_Sprite.h"
/* A class that stores the window and renderer objects required to display images to the screen. 
	Also responsible for blitting and rendering surface objects themselves.
*/
class MOB_Graphics
{
public:
	MOB_Graphics();
	~MOB_Graphics();

	/* Called once per frame, handles the rendering of all drawable objects.
	*/
	void graphicsUpdate();

	/*Sets the default render background color.
	*/
	void setDefaultRenderColor(int r, int g, int b);

	/* Create and add a drawable object to the list of those to be renderered.
	*/
	void renderObject(std::string& name, std::string& type, std::string& filePath, int w, int h);

private:
	/* Must be called from any inheriting class during construction. Checks to see if the file at filePath has already been loaded
		to avoid duplicate loading.
	*/
	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string& filePath);

	/* Draws all objects in <surfaces> to the rendering buffer.
	*/
	void blitSurfaces();

	/* Clear the renderer of all current images.
	*/
	void clear();

	/* Update the renderer and display the buffered images to the screen.
	*/
	void flip();

	std::map<std::string, SDL_Texture*> loadedTextures;
	std::map<std::string, IDrawable> drawables;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};



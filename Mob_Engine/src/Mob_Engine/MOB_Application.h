#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER
#include <vector>
#include "ISystem.h"
#include "MOB_RenderingSystem.h"
#include "MOB_ComponentFactory.h"
#include "Core.h"
/* The main application class. To be initialized in any project using the Mob engine.
*/
class MOB_API MOB_Application
{
public:
	MOB_Application(std::string windowTitle, int windowWidth, int windowHeight);
	~MOB_Application();

	/* Runs the game loop.
	*/
	void Run();

	/*Create a new Game Object with specified name and no components attached
	*/
	void CreateGameObject(std::string name);

	/* Adds a graphical component to the Entity with the specified name. The associated sprite will be loaded in from filePath
	*/
	void AddRenderingComponent(std::string gameObjectName, std::string filePath);

	
private:
	std::vector<ISystem*> m_systems;

	MOB_ComponentFactory* m_componentFactory;

	SDL_Window* m_window;
	
	SDL_Renderer* m_renderer;
};
#endif


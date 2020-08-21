#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER
#include <vector>
#include "ISystem.h"
#include "MOB_RenderingSystem.h"
#include "MOB_ComponentFactory.h"
#include "Core.h"
#include "IScript.h"
#include "MOB_TransformSystem.h"
#include "MOB_CollisionSystem.h"
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
	void CreateGameObject(std::string& name);

	/* Adds a graphical component to the Entity with the specified name. The associated sprite will be loaded in from filePath
	*/
	void AddRenderingComponent(std::string& gameObjectName, std::string& filePath);

	/* Adds a transform component to the game object, initializing the position of the game object to be (x,y)
	*/
	void AddTransformComponent(std::string& gameObjectName);

	//TODO: Add a collider factory that allows for easier creation of specific colliders.
	/* Adds a square collider component to the game object.
	*/
	void AddSquareCollisionComponent(std::string& gameObjectName, double x, double y, double w, double h);

	/* Adds script to the gameobject with specified name.
	*/
	void AddScriptToGameObject(std::string& gameObjectName, IScript* script);

	/* Runs all scripts FrameUpdate() methods.
	*/
	void RunAllScriptFrameUpdates();
	
	/* Runs all scripts Start() methods.
	*/
	void RunAllScriptStarts();
	
private:
	std::vector<ISystem*> m_systems;

	MOB_ComponentFactory* m_componentFactory;

	SDL_Window* m_window;
	
	SDL_Renderer* m_renderer;
};
#endif


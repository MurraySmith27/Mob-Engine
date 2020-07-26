#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER
#include <vector>
#include "IScriptable.h"
#include "MOB_Graphics.h"
#include "MOB_GameObject.h"
#include "MOB_Script.h"
#include "Core.h"
/* The main application class. To be initialized in any project using the Mob engine.
*/
class MOB_API MOB_Application
{
public:
	MOB_Application();
	~MOB_Application();

	void createGameObject(std::string name);

	void addGraphicsToGameObject(std::string gameObjectName, std::string filePath, int w, int h);

	void run();

	void start();

	void frameUpdate();

private:
	MOB_Graphics* graphics = new MOB_Graphics();

	/* keys: gameobject names, values: scripts associated with these gameobjects.
	*/
	std::map<std::string, MOB_Script*> scripts;

	std::map<std::string, MOB_GameObject*> gameObjects;
};
#endif


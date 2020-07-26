#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER
#include <vector>
#include "IScriptable.h"
#include "MOB_Graphics.h"
#include "MOB_GameObject.h"
/* The main application class. To be initialized in any project using the Mob engine.
*/
class MOB_Application
{
public:
	MOB_Application();
	~MOB_Application();

	void addGameObject(MOB_GameObject gameObject);

	void run();

	void start();

	void frameUpdate();
private:
	std::vector<IScriptable>* scriptableObjects;
	MOB_Graphics* graphics = new MOB_Graphics();
};
#endif


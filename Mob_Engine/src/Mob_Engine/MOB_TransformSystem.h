#ifndef TRANSFORMSYSTEM_HEADER
#define TRANSFORMSYSTEM_HEADER
#include "ISystem.h"
#include <vector>
#include "MOB_TransformComponent.h"
#include "MOB_EntityManager.h"
/* Handles transform operations from script/application layer
*/
class MOB_TransformSystem : public ISystem
{
public:

	MOB_TransformSystem();

	~MOB_TransformSystem();

	/* Changes the position of the game object with specified name to (x,y)
	*/
	void ChangePosition(std::string& gameObjectName, int x = -1, int y = -1);

	/* Translates the gameobject with specified name by moveX units horizontally and moveY units vertically.
	*/
	void Translate(std::string& gameObjectName, int moveX, int moveY);

	/* Changes the size of the game object to be rendered.
	*/
	void Stretch(std::string& gameObjectName, int w = -1, int h = -1);

	void Start() override;

	void FrameUpdate() override;
private:

	/* Fetches the transform component associated with gameObjectName
	*/
	MOB_TransformComponent* FetchTransform(std::string& gameObjectName);
};
#endif


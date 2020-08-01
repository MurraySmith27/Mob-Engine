//#ifndef TRANSFORM_COMPONENT_HEADER
//#define TRANSFORM_COMPONENT_HEADER
#include "MOB_GameObject.h"
/* A component describing transform data for an attached Game Object.
*/
class MOB_API MOB_TransformComponent : public IComponent
{
public:

	/* Pointer to the Game Object that this component is attached to.
	*/
	MOB_GameObject* gameObject;

	/* Initializes a new Transform Component attached to the specified Game Object.
	*/
	MOB_TransformComponent(MOB_GameObject* attachedGameObject);

	~MOB_TransformComponent();

	/* Changes the position of the Game Object to (x, y).
	*/
	void changePosition(int x = -1, int y = -1);

	/* Stretches the object to now have width w and height h.
	*/
	void stretch(int w = -1, int h = -1);

	int getX() const {
		return _x;
	}
	
	int getY() const {
		return _y;
	}

	int getW() const {
		return _w;
	}

	int getH() const {
		return _h;
	}

private:

	int _x = 0;
	int _y = 0;
	int _w = 0;
	int _h = 0;
};
//#endif


#ifndef TRANSFORMCOMPONENT_HEADER
#define TRANSFORMCOMPONENT_HEADER
#include "MOB_GameObject.h"
#include "IComponent.h"
/* A component describing transform data for an attached Game Object.
*/
class MOB_API MOB_TransformComponent : public IComponent
{
public:

	MOB_TransformComponent();

	~MOB_TransformComponent();

	/* Changes the position of the Game Object to (x, y).
	*/
	void ChangePosition(int x = -1, int y = -1);

	/* Stretches the object to now have width w and height h.
	*/
	void Stretch(int w = -1, int h = -1);

	/* Translate the sprite moveX units horizontally and moveY units vertically.
	*/
	void Translate(int moveX, int moveY);

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

	static std::string componentType;
private:

	int _x;
	int _y;
	int _w;
	int _h;

};
#endif


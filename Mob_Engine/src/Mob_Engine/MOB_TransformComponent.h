#ifndef TRANSFORMCOMPONENT_HEADER
#define TRANSFORMCOMPONENT_HEADER
#include "MOB_GameObject.h"
#include "IComponent.h"
#include <SDL.h>
/* A component describing transform data for an attached Game Object.
*/
class MOB_API MOB_TransformComponent : public IComponent
{
public:

	MOB_TransformComponent(int x, int y, int w, int h);

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

	/* Rotates the entity's position by angle degrees.
	*/
	void RotateBy(double angle);

	/* Sets the rotatio of the entity to angle degrees clockwise.
	*/
	void SetRotation(double angle);

	/* Flips the gameobject by one or both of the boolean specified for horizontal and vertical flips
	*/
	void Flip(bool flipHorizontal, bool flipVertical);

	int getX() const {
		return m_positionRect.x;
	}
	
	int getY() const {
		return m_positionRect.y;
	}

	int getW() const {
		return m_positionRect.w;
	}

	int getH() const {
		return m_positionRect.h;
	}

	SDL_Rect getPositionRect() {
		return m_positionRect;
	}

	double getAngle() {
		return angle;
	}

	SDL_RendererFlip getFlip() {
		return flip;
	}

	static std::string componentType;
private:

	SDL_Rect m_positionRect{ 0, 0, 0, 0 };

	double angle = 0;

	SDL_RendererFlip flip = (SDL_RendererFlip)SDL_FLIP_NONE;

};
#endif


#ifndef QUADCOLLISIONCOMPONENT_HEADER
#define QUADCOLLISIONCOMPONENT_HEADER
#include "Core.h"
#include "MOB_CollisionComponent.h"
#include <vector>
#include "MOB_Vector.h"
/* Defines a Quad Colliison component, which is a collider that is a four-sided object defined by four points given on construction
*/
class MOB_API MOB_QuadCollisionComponent : public MOB_CollisionComponent
{
public: 

	MOB_QuadCollisionComponent(std::vector<MOB_Vector> vertices);

	~MOB_QuadCollisionComponent();

	void ChangeColliderPosition(MOB_TransformComponent* transform) override;

	std::vector<MOB_Vector> GetVertices(double angle = 0.0) override;

	std::vector<MOB_Vector> getDirectionVectorsToProject(double angleOfRotation) override;

	/* Returns the center point of the quad
	*/
	MOB_Vector FindCenter();

private:

	double centerX;

	double centerY;

};
#endif


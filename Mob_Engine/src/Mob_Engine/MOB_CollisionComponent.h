#ifndef COLLISIONCOMPONENT_HEADER
#define COLLISIONCOMPONENT_HEADER
#include "IComponent.h"
#include <SDL.h>
#include <vector>
#include <tuple>
#include "MOB_Vector.h"
#include "MOB_TransformComponent.h"
class MOB_API MOB_CollisionComponent : public IComponent
{
public:
	//Ensure all subclasses of MOB_CollisionComponent call its constructor or assign componentType.
	MOB_CollisionComponent();

	virtual ~MOB_CollisionComponent();
	
	/* Return a list of tuples representing direction vectors to project from when calculating the SAT collision.
	*/
	virtual std::vector<MOB_Vector> getDirectionVectorsToProject(double angleOfRotation) = 0;

	/* Return all vertexes of the collider
	*/
	virtual std::vector<MOB_Vector> GetVertices(double angle = 0.0) = 0;

	/* Updates the collider position to match the transform (rotation applied at collision time and draw time)
	*/
	virtual void ChangeColliderPosition(MOB_TransformComponent* transform) = 0;

	static std::string componentType;

protected:

	std::vector<MOB_Vector> m_colliderVertexes;
	
};
#endif


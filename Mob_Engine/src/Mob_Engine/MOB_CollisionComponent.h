#ifndef COLLISIONCOMPONENT_HEADER
#define COLLISIONCOMPONENT_HEADER
#include "IComponent.h"
#include <SDL.h>
#include <vector>
#include <tuple>
class MOB_API MOB_CollisionComponent : public IComponent
{
public:
	//Ensure all subclasses of MOB_CollisionComponent call its constructor or assign componentType.
	MOB_CollisionComponent();

	virtual ~MOB_CollisionComponent();
	
	/* Return a list of tuples representing direction vectors to project from when calculating the SAT collision.
	*/
	virtual std::vector<std::tuple<double, double>> getDirectionVectorsToProject(double angleOfRotation) = 0;

	/* Return all vertexes of the collider
	*/
	virtual std::vector<std::tuple<double, double>> getVertices() = 0;

	/* Moves all collider vertexes to position (x, y)
	*/
	virtual void ChangeColliderPosition(double x, double y) = 0;

	static std::string componentType;

protected:

	std::vector<std::tuple<double, double>> m_colliderVertexes;
	
};
#endif


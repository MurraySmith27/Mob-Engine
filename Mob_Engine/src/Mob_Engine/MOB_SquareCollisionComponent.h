#ifndef SQUARECOLLISIONCOMPONENT_HEADER
#define SQUARECOLLISIONCOMPONENT_HEADER
#include "MOB_CollisionComponent.h"
#include <vector>
#include <tuple>
class MOB_API MOB_SquareCollisionComponent : public MOB_CollisionComponent
{
public: 

	MOB_SquareCollisionComponent(double x, double y, double w, double h);

	~MOB_SquareCollisionComponent();

	void ChangeColliderPosition(double x, double y) override;

	std::vector<MOB_Vector> GetVertices(double angle = 0.0) override;

	std::vector<MOB_Vector> getDirectionVectorsToProject(double angleOfRotation) override;

};
#endif

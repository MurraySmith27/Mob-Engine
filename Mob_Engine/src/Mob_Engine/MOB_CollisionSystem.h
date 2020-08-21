#ifndef COLLISIONSYSTEM_HEADER
#define COLLISIONSYSTEM_HEADER
#include "ISystem.h"
#include "IEntity.h"
#include "MOB_CollisionComponent.h"
#include "MOB_TransformComponent.h"
#include "MOB_EntityManager.h"
#include <vector>
#include <memory>
/* System for handling all collisions. required components to collide: MOB_CollisionComponent (of some kind) and MOB_TransformComponent.
*/
class MOB_CollisionSystem : public ISystem
{
public:

	MOB_CollisionSystem();

	~MOB_CollisionSystem();

	void Start() override;

	void FrameUpdate() override;

private:

	struct ComponentTuple {
		MOB_CollisionComponent* collision;
		MOB_TransformComponent* transform;
	};

	std::vector<std::shared_ptr<ComponentTuple>> m_componentTuples;

	/* Performs broad phase collision detection and returns ComponentTuples corresponding to all colliders which should be considered for n
		narrow phase detection.
	*/
	std::vector<std::tuple<std::shared_ptr<ComponentTuple>, std::shared_ptr<ComponentTuple>>> GetNarrowPhaseCollisionEntities();

	bool IsColliding(std::shared_ptr<ComponentTuple> entity1, std::shared_ptr<ComponentTuple> entity2);

	void HandleCollisions(std::shared_ptr<ComponentTuple> entity1, std::shared_ptr<ComponentTuple> entity2);

	/* Updates collider positions based on transform component data.
	*/
	void UpdateColliderPositions();

	std::tuple<double, double> VectorComponent(std::tuple<double, double> projectOnto, 
		std::tuple<double, double> vectorToProject);

	/* Return the signed magnitude of vector
	*/
	double VectorMagnitude(std::tuple<double, double> vector);
};
#endif


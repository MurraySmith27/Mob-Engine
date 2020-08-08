#ifndef COLLISIONSYSTEM_HEADER
#define COLLISIONSYSTEM_HEADER
#include "ISystem.h"
#include "IEntity.h"
#include "MOB_CollisionComponent.h"
#include "MOB_TransformComponent.h"
#include <vector>
#include <memory>
class MOB_CollisionSystem : public ISystem
{
public:

	void Start() override;

	void FrameUpdate() override;

private:

	struct ComponentTuple {
		MOB_CollisionComponent* collision;
		MOB_TransformComponent* transform;
	};

	std::vector<std::shared_ptr<ComponentTuple>> GetBroadPhaseCollisionEntities();

	bool IsColliding(ComponentTuple* entity1, ComponentTuple* entity2);

	void HandleCollisions(ComponentTuple* entity1, ComponentTuple* entity2);
};
#endif


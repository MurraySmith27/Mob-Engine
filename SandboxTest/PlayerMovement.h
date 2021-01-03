#include "MOB_Engine/IScript.h"
#include "MOB_Engine/MOB_InputManager.h"
#include "Mob_Engine/MOB_TransformComponent.h"
#include "Mob_Engine/MOB_EntityManager.h"
#include "Mob_Engine/MOB_Vector.h"

class PlayerMovement : public IScript {

public:

	PlayerMovement(std::string& entityName);

	~PlayerMovement();

	void Start() override;

	void FrameUpdate() override;

	void OnCollision(std::string& entity1Name, std::string& entity2Name) override;

private:
	MOB_Vector velocity = MOB_Vector(0,0);
	MOB_Vector up_ = MOB_Vector(2, -1);
	MOB_Vector right_ = MOB_Vector(2, 1);
	MOB_TransformComponent* transform;

	MOB_InputManager* inputManager;

};
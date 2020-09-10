#include "Mob_Engine/IScript.h"
#include <string>
#include "Mob_Engine/MOB_TransformComponent.h"
#include "Mob_Engine/MOB_InputManager.h"
class BasicScript : public IScript
{
public:

	BasicScript(std::string& entityName);

	void FrameUpdate() override;

	void Start() override;

	void OnCollision(std::string& entity1name, std::string& entity2name) override;

private:

	MOB_TransformComponent* transform;

	MOB_InputManager* InputManager;

	int velx;
	int vely;
};


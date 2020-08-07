#include "Mob_Engine/IScript.h"
#include <string>
#include "Mob_Engine/MOB_TransformComponent.h"
class BasicScript : public IScript
{
public:

	BasicScript(std::string& entityName);

	void FrameUpdate() override;

	void Start() override;
private:

	MOB_TransformComponent* transform;
};


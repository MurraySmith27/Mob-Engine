#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER
#include "IEntity.h"
#include <string>
#include "Core.h"
/* A basic game object. The simplest entity in the engine.
*/
class MOB_API MOB_GameObject : public IEntity {
public:

	MOB_GameObject(int initID, std::string initName);

	~MOB_GameObject();


	void OnBirth() override;

	void OnDeath() override;
	
private:

	int m_ID;

	std::string m_name;
};
#endif


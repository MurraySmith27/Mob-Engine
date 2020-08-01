#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER
#include "IEntity.h"
#include <string>
#include "Core.h"
/* A basic game object. The simplest entity in the engine.
*/
class MOB_API MOB_GameObject : public IEntity {
public:

	MOB_GameObject(std::string initName, int initID);

	~MOB_GameObject();

	/* Return the name of this gameobject.
	*/
	std::string getName();

	void OnBirth() override;

	void OnDeath() override;
	
private:
	std::string m_name;
};
#endif


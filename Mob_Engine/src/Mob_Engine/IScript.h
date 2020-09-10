#ifndef ISCRIPT_HEADER
#define ISCRIPT_HEADER
#include "Core.h"
#include <string>
/* An interface describing abstract functionality of a script which is attached to an entity.
*/
class MOB_API IScript {

public:

	IScript(std::string& entityName);

	virtual ~IScript();

	/* Called once per frame.
	*/
	virtual void FrameUpdate() = 0;

	/* Called when the program starts up.
	*/
	virtual void Start() = 0;

	/* Called on collision between entity1 and entity2 only when one of the two is the entity that has this script attached.
	*/
	virtual void OnCollision(std::string& entity1name, std::string& entity2name) = 0;

protected:

	std::string m_entityName;

};
#endif


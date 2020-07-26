#ifndef SCRIPTABLE_HEADER
#define SCRIPTABLE_HEADER
#include "MOB_Script.h"
/*An interface describing script-related behaviour for all scriptable objects such as GameObjects.
*/
class IScriptable {

public:

	/* Return attached script.
	*/
	MOB_Script* getScript() {
		return this->script;
	}

	/* Attach a script to this object.
	*/
	void attachScript(MOB_Script* script) {
		this->script = script;
	}

private:

	MOB_Script* script;
};

#endif

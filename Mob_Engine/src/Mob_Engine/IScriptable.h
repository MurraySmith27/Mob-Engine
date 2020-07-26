#ifndef SCRIPTABLE_HEADER
#define SCRIPTABLE_HEADER
#include <string>
#include "Core.h"
/*An interface describing script-related behaviour for all scriptable objects such as GameObjects.
*/
class MOB_API IScriptable {

public:

	/* Return attached script's filepath.
	*/
	std::string getScriptFilePath() {
		return scriptFilePath;
	}

	/* Attach a script to this object.
	*/
	void attachScript(std::string& filePath) {
		scriptFilePath = filePath;
	}

	std::string getName() const {
		return name;
	}

private:

	std::string name;

	std::string scriptFilePath;
};

#endif

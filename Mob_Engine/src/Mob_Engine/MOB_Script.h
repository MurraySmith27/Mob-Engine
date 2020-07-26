#ifndef SCRIPT_HEADER
#define SCRIPT_HEADER
#include "Core.h"

class MOB_API MOB_Script {
public:

	virtual void start() = 0;

	virtual void frameUpdate() = 0;
};
#endif
#ifndef ISYSTEM_HEADER
#define ISYSTEM_HEADER
#include "Core.h"
class MOB_API ISystem {
public:
	virtual void Start() = 0;

	virtual void FrameUpdate() = 0;
};
#endif
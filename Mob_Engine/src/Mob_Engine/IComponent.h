#ifndef ICOMPONENT_HEADER
#define ICOMPONENT_HEADER

#include "Core.h"
#include <string>
/* An interface describing the functionality shared among all components.
*/
class MOB_API IComponent {
public:

	virtual ~IComponent();

	/* A string identifier for the component type.
	*/
	static std::string componentType;

};
#endif

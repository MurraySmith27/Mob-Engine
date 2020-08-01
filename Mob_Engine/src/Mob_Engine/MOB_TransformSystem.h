#include "MOB_TransformComponent.h"
#include <string>
#include <map>
class MOB_TransformSystem
{
public:
	//TODO: Implement this class.
	static MOB_TransformComponent fetchTransform(std::string gameObjectName);

private:
	
	static std::map<std::string, MOB_TransformComponent*> transformComponents;
};


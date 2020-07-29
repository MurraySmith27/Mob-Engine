#include "IComponentHandler.h"
#include <vector>
class ComponentSystem
{
public:
	std::vector<IComponentHandler> componentHandlers;

	void start();

	void frameUpdate();

	//TODO: Implement something like this.
	void addComponent();
};


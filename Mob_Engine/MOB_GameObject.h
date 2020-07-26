#ifndef GRAPHICS_HEADER
#define GRAPHICS_HEADER
#include "IScriptable.h"
#include <string>
class MOB_GameObject : public IScriptable {
public:
	MOB_GameObject();

	~MOB_GameObject();

	void addGraphics(std::string& filePath, int w, int h);

	void updateLocation(int x, int y);

private:
	std::string spriteName;
};
#endif


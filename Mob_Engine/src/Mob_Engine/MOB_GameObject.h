//#ifndef GRAPHICS_HEADER
//#define GRAPHICS_HEADER
#include "IScriptable.h"
#include <string>
#include "Core.h"
class MOB_API MOB_GameObject : public IScriptable {
public:
	MOB_GameObject(std::string name);

	~MOB_GameObject();

	/* Adds a graphical component to this gameobject from file path filePath. The image has width w and height h.
	*/
	void addGraphics(std::string& filePath, int w, int h);

	/* Updates the location of the graphical component to be rendered at x, y
	*/
	void updateGraphicLocation(int x, int y);


	/* Return the file path to the graphical component associated with this Game Object.
	*/
	std::string getGraphicFilePath() const {
		return graphicFilePath;
	}

	int getGraphicW() const {
		return graphicW;
	}

	int getGraphicH() const {
		return graphicH;
	}

private:
	std::string name;

	std::string graphicFilePath;

	int graphicW;
	
	int graphicH;

	std::string scriptFilePath;


};
//#endif


#ifndef COMPONENTFACTORY_HEADER
#define COMPONENTFACTORY_HEADER
#include <SDL.h>
#include <string>
#include <map>
#include "IDrawable.h"
#include "MOB_Sprite.h"
#include "MOB_EntityManager.h"
#include "MOB_RenderingComponent.h"
#include "MOB_SquareCollisionComponent.h"
#include "MOB_QuadCollisionComponent.h"
/* Holds methods for creating and adding new components.
*/
class MOB_API MOB_ComponentFactory
{
public:

	MOB_ComponentFactory();

	~MOB_ComponentFactory();


	/* Adds a new RenderingComponent to the Entity with the specified name, and a texture loaded from filePath.
	*/
	void AddRenderingComponent(SDL_Renderer* renderer, std::string& name, std::string& filePath);

	/* Adds a new TransformComponent to the Entity with the specified name
	*/
	void AddTransformComponent(std::string& name);

	/* Adds a new SquareColliderComponent to the entity with the specified name
	*/
	void AddSquareCollisionComponent(std::string& name);

	/* Adds a new QuadCollisionComponent to the entity with the specified name. The vertices of this component are passed in.
	*/
	void AddQuadCollisionComponent(std::string& name, std::vector<MOB_Vector> vertices);


	/* Loads and returns a texture at file path specified.
	*/
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string& filePath);

private:
	/* List of spritesheets that have already been loaded.
	*/
	std::map<std::string, SDL_Texture*> m_loadedTextures;
};
#endif

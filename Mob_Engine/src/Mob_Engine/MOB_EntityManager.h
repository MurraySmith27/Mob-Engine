#ifndef ENTITYMANAGER_HEADER
#define ENTITYMANAGER_HEADER

#include <vector>
#include <string>
#include "MOB_GameObject.h"
#include "IEntity.h"
/* A singleton class responsible for managing entities.
*/
class MOB_API MOB_EntityManager
{
public:

	/* Return std::vector containing all entity objects.
	*/
	std::vector<IEntity*>& getEntities();
	
	/* Create a new Game Object with specified name
	*/
	void CreateGameObject(std::string& name);

	/* Returns singleon instance of EntityManager
	*/
	static MOB_EntityManager* getEntityManager();

	/* Return a pointer to the entity with the specified name
	*/
	IEntity* FindEntity(std::string& name);


private:

	static MOB_EntityManager* instance;
	
	static bool m_Initialized;

	int m_IDGenerator = 0;

	std::vector<IEntity*> m_entities;
};
#endif


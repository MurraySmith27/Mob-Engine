#ifndef ENTITYMANAGER_HEADER
#define ENTITYMANAGER_HEADER

#include "IEntity.h"
#include <vector>
#include <string>
#include "MOB_GameObject.h"
/* A singleton class 
*/
class MOB_API EntityManager
{
public:

	/* Return std::vector containing all entity objects.
	*/
	std::vector<IEntity*>& getEntities();
	
	/* Create a new Game Object with specified name
	*/
	void CreateGameObject(std::string name);

	/* Returns singleon instance of EntityManager
	*/
	static EntityManager* getEntityManager();

	/* Return a pointer to the entity with the specified name
	*/
	IEntity* findEntity(std::string name);


private:

	static EntityManager* instance;

	static int m_IDGenerator;

	std::vector<IEntity*> m_entities;
};
#endif


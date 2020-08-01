#ifndef ENTITYMANAGER_HEADER
#define ENTITYMANAGER_HEADER

#include "IEntity.h"
#include <vector>
#include <string>
#include "MOB_GameObject.h"
/* A singleton class 
*/
class EntityManager
{
public:

	/* Return std::vector containing all entity objects.
	*/
	std::vector<IEntity>& getEntities(){
		return this->m_entities;
	}
	
	/* Create a new Game Object with specified name
	*/
	void createGameObject(std::string name);

	/* Returns singleon instance of EntityManager
	*/
	static EntityManager* getEntityManager();


private:

	static EntityManager* instance;

	EntityManager();

	static int m_IDGenerator;

	std::vector<IEntity> m_entities;
};
#endif


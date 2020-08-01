#ifndef ENTITY_HEADER
#define ENTITY_HEADER
#include <map>
#include <string>
#include "IComponent.h"

/* An interface describing an entity in the program, which can have components attached to it.
*/
class IEntity {

public:

	IEntity(int ID);
	virtual ~IEntity();


	/* Return the attached component of type T if it exists, else return null.
	*/
	template<class T>
	T* GetComponent() {
		return m_Components.at(T.componentType);
	}

	/* Adds a component to the entity.
	*/
	template<class T>
	void AddComponent(T* component) {
		m_Components.emplace(T.componentType, component);
	}

	/* Removes a component from the entity.
	*/
	template<class T>
	void RemoveComponent() {
		m_Components.erase(T.componentType);
	}

	/* Called when the entity is created in the game context.
	*/
	virtual void OnBirth() = 0;

	/* Called when the entity is removed in the game context.
	*/
	virtual void OnDeath() = 0;

	/* Return the unique ID of the entity
	*/
	int getID() {
		return m_ID;
	}

private:

	int m_ID;

	std::map<std::string, IComponent*> m_Components;

};
#endif
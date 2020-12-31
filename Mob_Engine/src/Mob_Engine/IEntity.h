#ifndef ENTITY_HEADER
#define ENTITY_HEADER
#include "Core.h"
#include <map>
#include <string>
#include "IComponent.h"
#include <vector>
#include "IScript.h"

/* An interface describing an entity in the program, which can have components attached to it.
*/
class MOB_API IEntity {

public:

	IEntity(int initID, std::string& initName);

	virtual ~IEntity();


	/* Return the attached component of type T if it exists, else return null.
	*/
	template<class T>
	T* GetComponent() {
		if (m_Components.count(T::componentType) > 0) {
			dynamic_cast<T*>(m_Components.at(T::componentType));
		}
		else {
			return NULL;
		}
		
	}

	/* Adds a component to the entity.
	*/
	template<class T>
	void AddComponent(T* component) {
		m_Components.emplace(T::componentType, component);
	}

	/* Removes a component from the entity.
	*/
	template<class T>
	void RemoveComponent() {
		m_Components.erase(T::componentType);
	}

	/* Adds a script
	*/
	void AddScript(IScript* script) {
		m_Scripts.push_back(script);
	}

	/* Called when the entity is created in the game context.
	*/
	virtual void OnBirth();

	/* Called when the entity is removed in the game context.
	*/
	virtual void OnDeath();

	/* Return the unique ID of the entity
	*/
	virtual int getID() {
		return m_ID;
	}

	/* Return the name of this gameobject.
	*/
	virtual std::string getName() {
		return m_name;
	}

	virtual std::vector<IScript*>& getScripts() {
		return m_Scripts;
	}

protected:

	std::string m_name;

	int m_ID;

	std::map<std::string, IComponent*> m_Components;

	std::vector<IScript*> m_Scripts;

};
#endif
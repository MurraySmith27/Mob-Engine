#include "MOB_CollisionSystem.h"

//TODO: Delete this and create a logging system
#include <iostream>
#include <cmath>
#include <math.h>

MOB_CollisionSystem::MOB_CollisionSystem() {
	std::vector<IEntity*> entities = MOB_EntityManager::getEntityManager()->getEntities();

	for (int i = 0; i < entities.size(); i++) {
		std::shared_ptr<ComponentTuple> components = std::make_shared<ComponentTuple>();
		components->EntityName = entities[i]->getName();
		components->Transform = entities[i]->GetComponent<MOB_TransformComponent>();
		if (components->Transform == NULL) {
			std::cout << "Could not load in transform component for gameobject named: " << entities[i]->getName() << "\n";
		}
		components->Collision = entities[i]->GetComponent<MOB_CollisionComponent>();
		if (components->Collision == NULL) {
			std::cout << "Could not load in collision component for gameobject named: " << entities[i]->getName() << "\n";
		}
		if (components->Transform != NULL && components->Collision != NULL) {
			m_componentTuples.push_back(components);
		}
	}
}

MOB_CollisionSystem::~MOB_CollisionSystem() {

}

void MOB_CollisionSystem::Start() {

}


void MOB_CollisionSystem::FrameUpdate() {
	UpdateColliderPositions();

	//TODO: Handle Collision stuff here (all of it)

	std::vector<std::tuple<std::shared_ptr<MOB_CollisionSystem::ComponentTuple>,
		std::shared_ptr<MOB_CollisionSystem::ComponentTuple>>> narrowPhaseCollisions = GetNarrowPhaseCollisionEntities();

	for (int i = 0; i < narrowPhaseCollisions.size(); i++) {
		if (IsColliding(std::get<0>(narrowPhaseCollisions.at(i)), std::get<1>(narrowPhaseCollisions.at(i)))) {
			HandleCollisions(std::get<0>(narrowPhaseCollisions.at(i))->EntityName, std::get<1>(narrowPhaseCollisions.at(i))->EntityName);
		}
	}
}

void MOB_CollisionSystem::UpdateColliderPositions() {
	for (int i = 0; i < m_componentTuples.size(); i++) {
		//TODO: implement the observer pattern here to wait for a change in position before doing this calculation.
		std::shared_ptr<MOB_CollisionSystem::ComponentTuple> componentTuple = m_componentTuples.at(i);
		componentTuple->Collision->ChangeColliderPosition(componentTuple->Transform);
	}
}

//This method is currently rocking an O(n^2) time complexity. I'd like to get it down for average case but for now its fine.
std::vector<std::tuple<std::shared_ptr<MOB_CollisionSystem::ComponentTuple>, 
	std::shared_ptr<MOB_CollisionSystem::ComponentTuple>>> MOB_CollisionSystem::GetNarrowPhaseCollisionEntities() {
	//Below is an implementation of the sort-and-sweep broad phase collision detection.
	std::vector<std::tuple<std::shared_ptr<MOB_CollisionSystem::ComponentTuple>,
		std::shared_ptr<MOB_CollisionSystem::ComponentTuple>>> narrowPhaseCollisionTuples;

	std::vector<MOB_Vector> vertices;
	// XExtremes stores a list of all collision components, and their corresponding leftmost and rightmost coordinates when the vertices
	// are projected onto the x-axis, in that order. 
	std::vector<std::tuple<std::shared_ptr<MOB_CollisionSystem::ComponentTuple>, double, double>> XExtremes;

	for (int i = 0; i < m_componentTuples.size(); i++) {
		vertices = m_componentTuples.at(i)->Collision->GetVertices(m_componentTuples.at(i)->Transform->getAngle());
		//std::get<0> because the first coordinate of the tuple is the x coordinate.
		double rightmostXVertex = vertices.at(0).getX();
		double leftmostXVertex = vertices.at(0).getX();
		//Assuming that a collider has more than one vertex (a fair assumption)
		for (int j = 1; j < vertices.size(); j++) {
			if (vertices.at(j).getX() < leftmostXVertex) {
				leftmostXVertex = vertices.at(j).getX();
			}
			else if (vertices.at(j).getX() > rightmostXVertex) {
				rightmostXVertex = vertices.at(j).getX();
			}
		}
		XExtremes.push_back(std::make_tuple(m_componentTuples.at(i), leftmostXVertex, rightmostXVertex));
	}

	for (int i = 0; i < XExtremes.size(); i++) {
		std::tuple< std::shared_ptr<MOB_CollisionSystem::ComponentTuple>, double, double>
			currentCollisionComponent = XExtremes.at(XExtremes.size() - 1);

		for (int j = 0; j < XExtremes.size() - 1; j++) {
			if ((std::get<1>(XExtremes.at(j)) <= std::get<1>(currentCollisionComponent) && 
				std::get<1>(currentCollisionComponent) <= std::get<2>(XExtremes.at(j))) || 
				(std::get<1>(XExtremes.at(j)) <= std::get<2>(currentCollisionComponent) &&
				std::get<2>(currentCollisionComponent) <= std::get<2>(XExtremes.at(j)))) {

				narrowPhaseCollisionTuples.push_back(std::make_tuple(std::get<0>(currentCollisionComponent), 
					std::get<0>(XExtremes.at(j))));
			}
		}

		XExtremes.pop_back();
	}

	return narrowPhaseCollisionTuples;
}


bool MOB_CollisionSystem::IsColliding(std::shared_ptr<MOB_CollisionSystem::ComponentTuple> entity1,
 	std::shared_ptr<MOB_CollisionSystem::ComponentTuple> entity2) {

	//Performing narrow phase collision detection using Seperating-axis theorem. TODO: Check your math here.

	std::vector<MOB_Vector> dirVectors = entity1->Collision->getDirectionVectorsToProject(entity1->Transform->getAngle());

	std::vector<MOB_Vector> moreDirVectors = entity2->Collision->getDirectionVectorsToProject(entity2->Transform->getAngle());
	
	for (int i = 0; i < moreDirVectors.size(); i++) {
		dirVectors.push_back(moreDirVectors.at(i));
	}

	std::vector<MOB_Vector> entity1Vertices = entity1->Collision->GetVertices(entity1->Transform->getAngle());
	std::vector<MOB_Vector> entity2Vertices = entity2->Collision->GetVertices(entity2->Transform->getAngle());

	MOB_Vector normal;
	for (int i = 0; i < dirVectors.size(); i++) {
		
		normal = MOB_Vector::UnitNormal(dirVectors.at(i));
		
		MOB_Vector entity1MostNegativeProjectionOntoNormal = MOB_Vector::ProjectOnto(normal, entity1Vertices.at(0));
		MOB_Vector entity1MostPositiveProjectionOntoNormal = MOB_Vector::ProjectOnto(normal, entity1Vertices.at(0));

		//Once again assuming all entities have at least two vertices.
		for (int j = 1; j < entity1Vertices.size(); j++) {
			MOB_Vector vertexNormalProjection = MOB_Vector::ProjectOnto(normal, entity1Vertices.at(j));
			if (vertexNormalProjection.getSignedMagnitude() < entity1MostNegativeProjectionOntoNormal.getSignedMagnitude()) {
				entity1MostNegativeProjectionOntoNormal = vertexNormalProjection;
			}
			else if (vertexNormalProjection.getSignedMagnitude() > entity1MostPositiveProjectionOntoNormal.getSignedMagnitude()) {
				entity1MostPositiveProjectionOntoNormal = vertexNormalProjection;
			}
		}

		MOB_Vector entity2MostNegativeProjectionOntoNormal = MOB_Vector::ProjectOnto(normal, entity2Vertices.at(0));
		MOB_Vector entity2MostPositiveProjectionOntoNormal = MOB_Vector::ProjectOnto(normal, entity2Vertices.at(0));


		for (int j = 1; j < entity2Vertices.size(); j++) {
			MOB_Vector vertexNormalProjection = MOB_Vector::ProjectOnto(normal, entity2Vertices.at(j));
			if (vertexNormalProjection.getSignedMagnitude() < entity2MostNegativeProjectionOntoNormal.getSignedMagnitude()) {
				entity2MostNegativeProjectionOntoNormal = vertexNormalProjection;
			}
			else if (vertexNormalProjection.getSignedMagnitude() > entity2MostPositiveProjectionOntoNormal.getSignedMagnitude()) {
				entity2MostPositiveProjectionOntoNormal = vertexNormalProjection;
			}
		}

		if (entity1MostNegativeProjectionOntoNormal.getSignedMagnitude() > entity2MostPositiveProjectionOntoNormal.getSignedMagnitude()) {
			return false;
		}
		else if (entity1MostPositiveProjectionOntoNormal.getSignedMagnitude() < entity2MostNegativeProjectionOntoNormal.getSignedMagnitude()) {
			return false;
		}

	}

	//Iterated through all "shadow casts" and determined that they overlap in all of them (there is no separating axis), 
	// thus a collision has occured
	return true;
}

void MOB_CollisionSystem::HandleCollisions(std::string& entity1name, std::string& entity2name) {
	

	IEntity* Entity1 = MOB_EntityManager::getEntityManager()->FindEntity(entity1name);
	IEntity* Entity2 = MOB_EntityManager::getEntityManager()->FindEntity(entity2name);

	std::vector<IScript*> E1Scripts = Entity1->getScripts();
	for (int i = 0; i < E1Scripts.size(); i++) {
		E1Scripts[i]->OnCollision(entity1name, entity2name);
	}

	std::vector<IScript*> E2Scripts = Entity2->getScripts();
	for (int i = 0; i < E2Scripts.size(); i++) {
		E2Scripts[i]->OnCollision(entity1name, entity2name);
	}
}

//double MOB_CollisionSystem::VectorMagnitude(std::tuple<double, double> vector) {
//	//mag is a positive value.
//	double mag = std::sqrt(std::pow(std::get<0>(vector), 2) + std::pow(std::get<1>(vector), 2));
//	if (std::get<1>(vector) == 0) {
//		//the vector is vertical
//		if (std::get<0>(vector) >= 0) {
//			return mag;
//		}
//		else {
//			return -mag;
//		}
//	}
//	else if (std::get<0>(vector) < 0) {
//		return -mag;
//	}
//	else {
//		return mag;
//	}
//	
//}


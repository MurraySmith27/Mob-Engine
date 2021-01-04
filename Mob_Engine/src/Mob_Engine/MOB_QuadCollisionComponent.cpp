#include "MOB_QuadCollisionComponent.h"
#include <iostream>

MOB_QuadCollisionComponent::MOB_QuadCollisionComponent(std::vector<MOB_Vector> vertices) : MOB_CollisionComponent(){
	m_colliderVertexes = vertices;
	MOB_Vector center = FindCenter();
	centerX = center.getX();
	centerY = center.getY();
}

MOB_QuadCollisionComponent::~MOB_QuadCollisionComponent() {

}

void MOB_QuadCollisionComponent::ChangeColliderPosition(MOB_TransformComponent* transform) {

	// First we find the center of the quad, because it must be convex the quad has center at the point where the lines between the vertices intersect.
	
	double XDiff = transform->getX() - centerX;
	double YDiff = transform->getY() - centerY;

	for (int i = 0; i < m_colliderVertexes.size(); i++) {
		m_colliderVertexes.at(i) = MOB_Vector(m_colliderVertexes.at(i).getX() + XDiff, m_colliderVertexes.at(i).getY() + YDiff);
	}
	
	centerX = transform->getX();
	centerY = transform->getY();
}

MOB_Vector MOB_QuadCollisionComponent::FindCenter() {

	// A prerequisite of this method is that all vertices in m_colliderVertexes must be in order around the outside.

	double quotient1, quotient2;

	if (!(m_colliderVertexes.at(3).getX() == m_colliderVertexes.at(1).getX())) {
		quotient1 = (m_colliderVertexes.at(2).getY() - m_colliderVertexes.at(0).getY()) / (m_colliderVertexes.at(2).getX() - m_colliderVertexes.at(0).getX());
	}
	else {
		quotient1 = 0;
	}

	if (!(m_colliderVertexes.at(3).getX() == m_colliderVertexes.at(1).getX())) {
		quotient2 = (m_colliderVertexes.at(3).getY() - m_colliderVertexes.at(1).getY()) / (m_colliderVertexes.at(3).getX() - m_colliderVertexes.at(1).getX());
	}
	else {
		quotient2 = 0;
	}

	double x;

	if (!(quotient1 == quotient2)) {
		x = ((quotient1 * m_colliderVertexes.at(0).getX()) - (quotient2 * m_colliderVertexes.at(1).getX()) + m_colliderVertexes.at(1).getY() - 
			m_colliderVertexes.at(0).getY()) / (quotient1 - quotient2);
	}
	else {
		std::cout << "Warning, one of the quad colliders is either a line or breaks the precondition that each consecutive point must be in circular order." << std::endl;
		return MOB_Vector(0,0);
	}

	double y = quotient1 * (x - m_colliderVertexes.at(0).getX()) + m_colliderVertexes.at(0).getY();

	return MOB_Vector(x, y);

}

std::vector<MOB_Vector> MOB_QuadCollisionComponent::GetVertices(double angle) {
	//Currently the angle does nothing for quads
	return m_colliderVertexes;
}


std::vector<MOB_Vector> MOB_QuadCollisionComponent::getDirectionVectorsToProject(double angleOfRotation) {
	
	//the angle does nothing right now

	std::vector<MOB_Vector> dirVectors;

	dirVectors.push_back(m_colliderVertexes.at(1) - m_colliderVertexes.at(0));

	dirVectors.push_back(m_colliderVertexes.at(2) - m_colliderVertexes.at(1));

	dirVectors.push_back(m_colliderVertexes.at(3) - m_colliderVertexes.at(2));

	dirVectors.push_back(m_colliderVertexes.at(0) - m_colliderVertexes.at(3));

	return dirVectors;
}
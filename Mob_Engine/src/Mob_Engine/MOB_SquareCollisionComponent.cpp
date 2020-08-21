#include "MOB_SquareCollisionComponent.h"

#include <math.h>

MOB_SquareCollisionComponent::MOB_SquareCollisionComponent(double x, double y , double w, double h) : MOB_CollisionComponent() {
	m_colliderVertexes.push_back(std::tuple<int, int>{ x, y });
	m_colliderVertexes.push_back(std::tuple<int, int>{ x + w, y });
	m_colliderVertexes.push_back(std::tuple<int, int>{ x, y + h});
	m_colliderVertexes.push_back(std::tuple<int, int>{ x + w, y + h });
}

MOB_SquareCollisionComponent::~MOB_SquareCollisionComponent() {

}

std::vector<std::tuple<double, double>> MOB_SquareCollisionComponent::getVertices() {
	return m_colliderVertexes;
}

void MOB_SquareCollisionComponent::ChangeColliderPosition(double x, double y) {
	//This works because the angle of rotation is applied at calculation time, and not associated with the square collision component
	double w = std::get<0>(m_colliderVertexes.at(1)) - std::get<0>(m_colliderVertexes.at(0));
	double h = std::get<1>(m_colliderVertexes.at(2)) - std::get<1>(m_colliderVertexes.at(0));
	m_colliderVertexes.at(0) = std::make_tuple(x, y);
	m_colliderVertexes.at(1) = std::make_tuple(x + w, y);
	m_colliderVertexes.at(2) = std::make_tuple(x, y + h);
	m_colliderVertexes.at(3) = std::make_tuple(x + w, y + h);
}

std::vector<std::tuple<double, double>> MOB_SquareCollisionComponent::getDirectionVectorsToProject(double angleOfRotation) {
	std::vector<std::tuple<double, double>> directionVectorsToProject;

	std::tuple<double, double> firstDirectionVector;
	if ((int)angleOfRotation % 90 == 0) {
		directionVectorsToProject.push_back(std::make_tuple(1.0, 0.0));
		directionVectorsToProject.push_back(std::make_tuple(0.0, 1.0));
		directionVectorsToProject.push_back(std::make_tuple(-1.0, 0.0));
		directionVectorsToProject.push_back(std::make_tuple(0.0, -1.0));
		return directionVectorsToProject;
	}

	while (angleOfRotation >= 90) {
		angleOfRotation = angleOfRotation - 90;
	}
	
	double firstDirectionVectorX = cos((2 * M_PI / 180) * (angleOfRotation));
	double firstDirectionVectorY = - sin((2 * M_PI / 180) * (angleOfRotation));

	//TODO: finish this and check your math
	directionVectorsToProject.push_back(std::make_tuple(firstDirectionVectorX, firstDirectionVectorY));
	directionVectorsToProject.push_back(std::make_tuple(-firstDirectionVectorY, firstDirectionVectorX));
	directionVectorsToProject.push_back(std::make_tuple(-firstDirectionVectorX, -firstDirectionVectorY));
	directionVectorsToProject.push_back(std::make_tuple(firstDirectionVectorY, -firstDirectionVectorX));

	return directionVectorsToProject;
	

}
#include "MOB_SquareCollisionComponent.h"

#include <math.h>

MOB_SquareCollisionComponent::MOB_SquareCollisionComponent(double x, double y , double w, double h) : MOB_CollisionComponent() {
	m_colliderVertexes.push_back(MOB_Vector(x, y));
	m_colliderVertexes.push_back(MOB_Vector(x + w, y));
	m_colliderVertexes.push_back(MOB_Vector(x, y + h));
	m_colliderVertexes.push_back(MOB_Vector(x + w, y + h));
}

MOB_SquareCollisionComponent::~MOB_SquareCollisionComponent() {

}

std::vector<MOB_Vector> MOB_SquareCollisionComponent::GetVertices(double angle) {
	if (angle == 0.0 || angle == M_PI / 2 || angle == M_PI || angle == 3 * M_PI / 2) {
		return m_colliderVertexes;
	}
	else {
		while (angle > M_PI / 2) {
			angle -= M_PI / 2;
		}
		//first, we translate the square so the center is at the origin, then compute the rotation, then translate back.

		//PROBLEM: TREATING THIS LIKE A SQUARE

		double Width = m_colliderVertexes.at(1).getX() - m_colliderVertexes.at(0).getX();
		double Height = m_colliderVertexes.at(2).getY() - m_colliderVertexes.at(0).getY();

		float WidthHalved = Width / 2.0f;
		float HeightHalved = Height / 2.0f;

		double CenterXValue = m_colliderVertexes.at(0).getX() + WidthHalved;
		double CenterYValue = m_colliderVertexes.at(0).getY() + HeightHalved;

		double CornerToCenterDistance = sqrt(pow(WidthHalved, 2) + pow(HeightHalved, 2));

		double AngleFromHorizontalToCorner = atan(HeightHalved / WidthHalved);

		double AngleToCalcWith =  M_PI - AngleFromHorizontalToCorner - angle;

		std::vector<MOB_Vector> Vertices;
		
		double theta = AngleFromHorizontalToCorner + angle;
		Vertices.push_back(MOB_Vector(-CornerToCenterDistance * cos(theta) + CenterXValue, -CornerToCenterDistance * sin(theta) + CenterYValue));

		theta += M_PI - (2 * AngleFromHorizontalToCorner);
		Vertices.push_back(MOB_Vector(-CornerToCenterDistance * cos(theta) + CenterXValue, -CornerToCenterDistance * sin(theta) + CenterYValue));

		theta += (2 * AngleFromHorizontalToCorner);
		Vertices.push_back(MOB_Vector(-CornerToCenterDistance * cos(theta) + CenterXValue, -CornerToCenterDistance * sin(theta) + CenterYValue));

		theta += M_PI - (2 * AngleFromHorizontalToCorner);
		Vertices.push_back(MOB_Vector(-CornerToCenterDistance * cos(theta) + CenterXValue, -CornerToCenterDistance * sin(theta) + CenterYValue));

		return Vertices;
	}
}

void MOB_SquareCollisionComponent::ChangeColliderPosition(double x, double y) {
	//This works because the angle of rotation is applied at calculation time, and not associated with the square collision component
	double w = m_colliderVertexes.at(1).getX() - m_colliderVertexes.at(0).getX();
	double h = m_colliderVertexes.at(2).getY() - m_colliderVertexes.at(0).getY();
	m_colliderVertexes.at(0) = MOB_Vector(x, y);
	m_colliderVertexes.at(1) = MOB_Vector(x + w, y);
	m_colliderVertexes.at(2) = MOB_Vector(x, y + h);
	m_colliderVertexes.at(3) = MOB_Vector(x + w, y + h);
}

std::vector<MOB_Vector> MOB_SquareCollisionComponent::getDirectionVectorsToProject(double angleOfRotation) {
	std::vector<MOB_Vector> directionVectorsToProject;

	if (angleOfRotation == 0.0 || angleOfRotation == M_PI / 2 || angleOfRotation == M_PI || angleOfRotation == 3 * M_PI / 2) {
		directionVectorsToProject.push_back(MOB_Vector(1.0, 0.0));
		directionVectorsToProject.push_back(MOB_Vector(0.0, 1.0));
		directionVectorsToProject.push_back(MOB_Vector(-1.0, 0.0));
		directionVectorsToProject.push_back(MOB_Vector(0.0, -1.0));
		return directionVectorsToProject;
	}

	while (angleOfRotation >= M_PI / 2) {
		angleOfRotation = angleOfRotation - M_PI / 2;
	}
	
	double firstDirectionVectorX = cos(angleOfRotation);
	double firstDirectionVectorY = -sin(angleOfRotation);

	//TODO: finish this and check your math
	directionVectorsToProject.push_back(MOB_Vector(firstDirectionVectorX, firstDirectionVectorY));
	directionVectorsToProject.push_back(MOB_Vector(-firstDirectionVectorY, firstDirectionVectorX));
	directionVectorsToProject.push_back(MOB_Vector(-firstDirectionVectorX, -firstDirectionVectorY));
	directionVectorsToProject.push_back(MOB_Vector(firstDirectionVectorY, -firstDirectionVectorX));

	return directionVectorsToProject;
	

}
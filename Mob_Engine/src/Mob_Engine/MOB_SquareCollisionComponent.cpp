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

std::vector<std::tuple<double, double>> MOB_SquareCollisionComponent::GetVertices(double angle) {
	if (angle == 0.0f || angle == 90.0f || angle == 180.0f || angle == 270.0f) {
		return m_colliderVertexes;
	}
	else {
		while (angle > 90.0f) {
			angle -= 90.0f;
		}
		//first, we translate the square so the center is at the origin, then compute the rotation, then translate back.

		//PROBLEM: TREATING THIS LIKE A SQUARE

		int Width = (std::get<0>(m_colliderVertexes.at(1)) - std::get<0>(m_colliderVertexes.at(0)));
		int Height = (std::get<1>(m_colliderVertexes.at(2)) - std::get<1>(m_colliderVertexes.at(0)));
		double CenterXValue = std::get<0>(m_colliderVertexes.at(0)) + (Width / 2.0f);
		double CenterYValue = std::get<1>(m_colliderVertexes.at(0)) + (Height / 2.0f);

		float WidthHalved = Width / 2.0f;
		float HeightHalved = Height / 2.0f;


		double CornerToCenterDistance = sqrt(pow(WidthHalved, 2) + pow(HeightHalved, 2));

		double AngleFromHorizontalToCorner = atan(HeightHalved / WidthHalved) * 180 / M_PI;

		double AngleToCalcWith =  180 - AngleFromHorizontalToCorner - angle;

		std::vector<std::tuple<double, double>> Vertices;
		//if (AngleToCalcWith > 90.0f) {
		//	//If the angle is greater than 90, we reduce the angle by 90 and then flip the sin and cos accordingly.
		//	AngleToCalcWith -= 90.0f;
		//	Vertices.push_back(std::make_tuple(-CornerToCenterDistance * sin(M_PI / 180.0f * AngleToCalcWith) + CenterXValue, -CornerToCenterDistance * cos(M_PI / 180.0f * AngleToCalcWith) + CenterYValue));
		//	Vertices.push_back(std::make_tuple(CornerToCenterDistance * sin(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner)) + CenterXValue),
		//		-CornerToCenterDistance * cos(M_PI / 180.0f * (AngleToCalcWith - 180.0f - 2.0f * AngleFromHorizontalToCorner)) + CenterYValue));
		//	Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner))) + CenterXValue,
		//		CornerToCenterDistance * sin(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner)) + CenterYValue)));
		//	Vertices.push_back(std::make_tuple(CornerToCenterDistance * cos(M_PI / 180.0f * AngleToCalcWith) + CenterXValue, CornerToCenterDistance * sin(M_PI / 180.0f * AngleToCalcWith) + CenterYValue));
		//}
		//else {
		//	Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180.0f * AngleToCalcWith) + CenterXValue, -CornerToCenterDistance * sin(M_PI / 180.0f * AngleToCalcWith) + CenterYValue));
		//	Vertices.push_back(std::make_tuple(CornerToCenterDistance * cos(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner)) + CenterXValue), 
		//		-CornerToCenterDistance * sin(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner)) ) + CenterYValue));
		//	Vertices.push_back(std::make_tuple(-CornerToCenterDistance * sin(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner))) + CenterXValue,
		//		CornerToCenterDistance * cos(M_PI / 180.0f * (AngleToCalcWith - (180.0f - 2.0f * AngleFromHorizontalToCorner)) + CenterYValue)));
		//	Vertices.push_back(std::make_tuple(CornerToCenterDistance * sin(M_PI / 180.0f * AngleToCalcWith) + CenterXValue, CornerToCenterDistance * cos(M_PI / 180.0f * AngleToCalcWith) + CenterYValue));

		//}
		double theta = AngleFromHorizontalToCorner + angle;
		Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180 * theta) + CenterXValue, -CornerToCenterDistance * sin(M_PI / 180 * theta) + CenterYValue));

		theta += 180 - 2 * AngleFromHorizontalToCorner;
		Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180 * theta) + CenterXValue, -CornerToCenterDistance * sin(M_PI / 180 * theta) + CenterYValue));

		theta += 2 * AngleFromHorizontalToCorner;
		Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180 * theta) + CenterXValue, -CornerToCenterDistance * sin(M_PI / 180 * theta) + CenterYValue));

		theta += 180 - 2 * AngleFromHorizontalToCorner;
		Vertices.push_back(std::make_tuple(-CornerToCenterDistance * cos(M_PI / 180 * theta) + CenterXValue, -CornerToCenterDistance * sin(M_PI / 180 * theta) + CenterYValue));

		return Vertices;
	}
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
	
	double firstDirectionVectorX = cos((M_PI / 180) * (angleOfRotation));
	double firstDirectionVectorY = - sin((M_PI / 180) * (angleOfRotation));

	//TODO: finish this and check your math
	directionVectorsToProject.push_back(std::make_tuple(firstDirectionVectorX, firstDirectionVectorY));
	directionVectorsToProject.push_back(std::make_tuple(-firstDirectionVectorY, firstDirectionVectorX));
	directionVectorsToProject.push_back(std::make_tuple(-firstDirectionVectorX, -firstDirectionVectorY));
	directionVectorsToProject.push_back(std::make_tuple(firstDirectionVectorY, -firstDirectionVectorX));

	return directionVectorsToProject;
	

}
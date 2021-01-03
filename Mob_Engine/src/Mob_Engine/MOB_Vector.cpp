#include "MOB_Vector.h"
#include <Math.h>


MOB_Vector::MOB_Vector() : x(0), y(0), magnitude(0) {

}

MOB_Vector::MOB_Vector(double _x, double _y) : x(_x), y(_y) {
	this->magnitude = sqrt(x * x + y * y);
}


MOB_Vector::~MOB_Vector() {

}

MOB_Vector MOB_Vector::operator + (MOB_Vector vector) {
	MOB_Vector new_vector = MOB_Vector(x + vector.x, y + vector.y);
	return new_vector;
}

MOB_Vector MOB_Vector::operator - (MOB_Vector vector) {
	MOB_Vector new_vector = MOB_Vector(x - vector.x, y - vector.y);
	return new_vector;
}

MOB_Vector MOB_Vector::operator * (double constant) {
	MOB_Vector new_vector = MOB_Vector(constant * x, constant * y);
	return new_vector;
}

MOB_Vector MOB_Vector::operator / (double constant) {
	MOB_Vector new_vector = MOB_Vector(x / constant, y / constant);
	return new_vector;
}

bool MOB_Vector::operator == (MOB_Vector) {
	return x == x && y == y;
}

MOB_Vector MOB_Vector::up = MOB_Vector(-1, 0);

MOB_Vector MOB_Vector::down = MOB_Vector(1, 0);

MOB_Vector MOB_Vector::right = MOB_Vector(0, 1);

MOB_Vector MOB_Vector::left = MOB_Vector(0, -1);

MOB_Vector MOB_Vector::zero = MOB_Vector(0, 0);

double MOB_Vector::Distance(MOB_Vector vector1, MOB_Vector vector2) {
	return sqrt(pow(vector1.getX() - vector2.getX(), 2) + pow(vector1.getY() - vector2.getY(), 2));
}

double MOB_Vector::DotProduct(MOB_Vector vector1, MOB_Vector vector2) {
	return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY();
}

MOB_Vector MOB_Vector::ProjectOnto(MOB_Vector direction, MOB_Vector vector) {
	
	double directionMagnitude = direction.getMagnitude();
	return direction * (DotProduct(direction, vector) / (directionMagnitude * directionMagnitude));

}

MOB_Vector MOB_Vector::UnitNormal(MOB_Vector vector) {
	double n2 = 1;
	double n1 = -vector.y / vector.x;

	return MOB_Vector::Unit(n1, n2);
}

double MOB_Vector::getSignedMagnitude() {
	if (y == 0 && x < 0) {
		return -magnitude;
	}
	if (y < 0) {
		return -magnitude;
	}
	else {
		return magnitude;
	}
}

MOB_Vector MOB_Vector::Unit(double x, double y) {
	MOB_Vector new_vector = MOB_Vector(x, y);
	return new_vector / new_vector.getMagnitude();
}

MOB_Vector MOB_Vector::Unit(MOB_Vector vector) {
	return vector / vector.getMagnitude();
}

MOB_Vector MOB_Vector::Unit(double angle) {
	
	return MOB_Vector(cos(angle), sin(angle));
}

double MOB_Vector::AngleBetween(MOB_Vector vector1, MOB_Vector vector2) {
	return acos(DotProduct(vector1, vector2) / (vector1.getMagnitude() * vector2.getMagnitude()));
}


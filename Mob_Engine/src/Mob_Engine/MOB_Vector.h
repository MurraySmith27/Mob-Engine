#ifndef VECTOR_HEADER
#define VECTOR_HEADER
class MOB_Vector
{
public:

	MOB_Vector();

	MOB_Vector(double _x, double _y);

	~MOB_Vector();

	static MOB_Vector up;

	static MOB_Vector down;

	static MOB_Vector right;
	
	static MOB_Vector left;

	static MOB_Vector zero;

	/* Return the distance between vector1 and vector2.
	*/
	static double Distance(MOB_Vector vector1, MOB_Vector vector2);

	/* Return a unit vector in the direction of (x, y)
	*/
	static MOB_Vector Unit(double x, double y);

	static MOB_Vector Unit(double angle);

	static MOB_Vector Unit(MOB_Vector vector);

	/* Return the dot product of vector1 and vector2
	*/
	static double DotProduct(MOB_Vector vector1, MOB_Vector vector2);

	/* Return the projection of vector2 onto vector1
	*/
	static MOB_Vector ProjectOnto(MOB_Vector direction, MOB_Vector vector);


	/* Return the angle between vector1 and vector2 in radians.
	*/
	static double AngleBetween(MOB_Vector vector1, MOB_Vector vector2);

	//Overriding operators

	MOB_Vector operator + (MOB_Vector vector);

	MOB_Vector operator - (MOB_Vector vector);

	MOB_Vector operator * (double constant);

	MOB_Vector operator / (double constant);

	bool operator == (MOB_Vector vector);

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	double getMagnitude() {
		return magnitude;
	}

private:

	double magnitude;

	double x;

	double y;


	



	/*
	*/

};
#endif


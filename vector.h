
#ifndef __VECTOR_H
#define __VECTOR_H

#include <math.h>

struct Vector {
	double x, y;

	double lenSqr()                                             { return (x * x + y * y); };
	double len()                                                { return sqrt(lenSqr()); };

	Vector &operator =(const Vector &other)                     { x = other.x; y = other.y; return *this; };
};

inline Vector operator+(const Vector &v1, const Vector &v2)    { Vector r; r.x = v1.x + v2.x; r.y = v1.y + v2.y; return r; };
inline Vector operator-(const Vector &v1, const Vector &v2)    { Vector r; r.x = v1.x - v2.x; r.y = v1.y - v2.y; return r; };

#endif // __VECTOR_H

#pragma once
#include <tgmath.h>

class DimensionedVector {
private:
	float Matrix[4];

public:
	DimensionedVector();

	DimensionedVector(float X, float Y, float Z, float Height = 1.0f);

	DimensionedVector(const DimensionedVector& LinkToVector);

	virtual ~DimensionedVector() { ; }

	float operator [] (const int Index) const;
	float& operator [] (const int Index);

	DimensionedVector operator + (const DimensionedVector& LinkToVector) const;
	DimensionedVector operator - (const DimensionedVector& LinkToVector) const;
	DimensionedVector& operator = (const DimensionedVector& LinkToVector);
	DimensionedVector operator * (const DimensionedVector& LinkToVector) const;
	DimensionedVector operator * (float Scale) const;

	float Length()	const;
	float LengthSqr() const;
	void Normalize();

	float DotProduct(const DimensionedVector& LinkToVector) const;
	DimensionedVector CrossProduct(const DimensionedVector& LinkToVector) const;
	void SetZero();
	inline void SetVector(float X, float Y, float Z, float Height) { Matrix[0] = X; Matrix[1] = Y; Matrix[2] = Z; Matrix[3] = Height; }

};
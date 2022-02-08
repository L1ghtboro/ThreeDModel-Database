#pragma once

class DimensionedVector;

class VectorMatrix{
private:
	float Matrix[4][4];

public:
	VectorMatrix();
	VectorMatrix(const VectorMatrix& VectorRef);
	~VectorMatrix(){ }

	VectorMatrix operator*(const VectorMatrix& VectorRef) const;
	DimensionedVector operator*(const DimensionedVector& VectorRef) const;

	void RotationRateX(float Deg);
	void RotationRateY(float Deg);
	void RotationRateZ(float Deg);
	void Translate(const DimensionedVector& VectorToTranslate);

	void SetZero();
	void SetIdentity();
	const float* PointerRef() const;
	void SetScale(float X, float Y, float Z);
};
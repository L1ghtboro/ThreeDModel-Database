#include <cmath>
#include <memory.h>

#include "CustomVectorDimension.h"
#include "VectorMatrix.h"

VectorMatrix::VectorMatrix(){
	SetIdentity();
}

VectorMatrix::VectorMatrix(const VectorMatrix& VectorRef){
	int ActualSize = sizeof(Matrix);
	memcpy_s((&Matrix[0][0]), ActualSize, VectorRef.PointerRef(), ActualSize);
}

const float* VectorMatrix::PointerRef() const{
	return &(Matrix[0][0]);
}

void VectorMatrix::SetZero(){
	memset(&Matrix, 0, sizeof(Matrix));
}

void VectorMatrix::SetIdentity(){
	SetZero();
	Matrix[0][0] = Matrix[1][1] = Matrix[2][2] = Matrix[3][3] = 1.0f;
}

VectorMatrix VectorMatrix::operator* (const VectorMatrix& VectorRef) const{
	VectorMatrix Result;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			Result.Matrix[i][j] = 0;

			for (int k = 0; k < 4; k++)
				Result.Matrix[i][j] += Matrix[i][k] * VectorRef.Matrix[k][j];
		}
	}

	return Result;
}

DimensionedVector VectorMatrix::operator* (const DimensionedVector& VectorRef) const{
	DimensionedVector Result;

	Result = VectorRef;

	Result[0] = (Matrix[0][0] * VectorRef[0]) + (Matrix[0][1] * VectorRef[1]) + (Matrix[0][2] * VectorRef[2]) + (Matrix[0][3] * VectorRef[3]);
	Result[1] = (Matrix[1][0] * VectorRef[0]) + (Matrix[1][1] * VectorRef[1]) + (Matrix[1][2] * VectorRef[2]) + (Matrix[1][3] * VectorRef[3]);
	Result[2] = (Matrix[2][0] * VectorRef[0]) + (Matrix[2][1] * VectorRef[1]) + (Matrix[2][2] * VectorRef[2]) + (Matrix[2][3] * VectorRef[3]);
	Result[3] = (Matrix[3][0] * VectorRef[0]) + (Matrix[3][1] * VectorRef[1]) + (Matrix[3][2] * VectorRef[2]) + (Matrix[3][3] * VectorRef[3]);

	return Result;
}

void VectorMatrix::RotationRateX(float Deg){
	Matrix[0][0] = 1, Matrix[0][1] = 0, Matrix[0][2] = 0, Matrix[0][3] = 0;
	Matrix[1][0] = 0, Matrix[1][1] = cos(Deg / (180 * 3.14)), Matrix[1][2] = sin(Deg / (180 * 3.14)), Matrix[1][3] = 0;
	Matrix[2][0] = 0, Matrix[2][1] = -sin(Deg / (180 * 3.14)), Matrix[2][2] = cos(Deg / (180 * 3.14)), Matrix[2][3] = 0;
	Matrix[3][0] = 0, Matrix[3][1] = 0, Matrix[3][2] = 0, Matrix[3][3] = 1;
}

void VectorMatrix::RotationRateY(float Deg){
	Matrix[0][0] = cos(Deg / (180 * 3.14)), Matrix[0][1] = 0, Matrix[0][2] = -sin(Deg / (180 * 3.14)), Matrix[0][3] = 0;
	Matrix[1][0] = 0, Matrix[1][1] = 1, Matrix[1][2] = 0, Matrix[1][3] = 0;
	Matrix[2][0] = sin(Deg / (180 * 3.14)), Matrix[2][1] = 0, Matrix[2][2] = cos(Deg / (180 * 3.14)), Matrix[2][3] = 0;
	Matrix[3][0] = 0, Matrix[3][1] = 0, Matrix[3][2] = 0, Matrix[3][3] = 1;
}

void VectorMatrix::RotationRateZ(float Deg){
	Matrix[0][0] = cos(Deg / (180 * 3.14)), Matrix[0][1] = -sin(Deg / (180 * 3.14)), Matrix[0][2] = 0, Matrix[0][3] = 0;
	Matrix[1][0] = sin(Deg / (180 * 3.14)), Matrix[1][1] = cos(Deg / (180 * 3.14)), Matrix[1][2] = 0, Matrix[1][3] = 0;
	Matrix[2][0] = 0, Matrix[2][1] = 0, Matrix[2][2] = 1, Matrix[2][3] = 0;
	Matrix[3][0] = 0, Matrix[3][1] = 0, Matrix[3][2] = 0, Matrix[3][3] = 1;
}

void VectorMatrix::Translate(const DimensionedVector& VectorToTranslate){
	Matrix[0][2] = VectorToTranslate[0];
	Matrix[1][2] = VectorToTranslate[1];
	Matrix[2][2] = VectorToTranslate[2];
}

void VectorMatrix::SetScale(float SetSclaedX, float SetSclaedY, float SetSclaedZ){
	Matrix[0][0] = SetSclaedX, Matrix[0][1] = 0, Matrix[0][2] = 0, Matrix[0][3] = 0;
	Matrix[1][0] = 0, Matrix[1][1] = SetSclaedY, Matrix[1][2] = 0, Matrix[1][3] = 0;
	Matrix[2][0] = 0, Matrix[2][1] = 0, Matrix[2][2] = SetSclaedZ, Matrix[2][3] = 0;
	Matrix[3][0] = 0, Matrix[3][1] = 0, Matrix[3][2] = 0, Matrix[3][3] = 1;
}

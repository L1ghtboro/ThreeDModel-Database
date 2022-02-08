#include "CustomVectorDimension.h"

DimensionedVector::DimensionedVector(){
	Matrix[0] = 0.0f;
	Matrix[1] = 0.0f;
	Matrix[2] = 0.0f;
	Matrix[3] = 1.0f;
}

DimensionedVector::DimensionedVector(float X, float Y, float Z, float Height = 1.0f){
	Matrix[0] = X; 
	Matrix[1] = Y;
	Matrix[2] = Z; 
	Matrix[3] = Height;
}

DimensionedVector::DimensionedVector(const DimensionedVector& LinkToVector){
	Matrix[0] = LinkToVector[0];
	Matrix[1] = LinkToVector[1];
	Matrix[2] = LinkToVector[2];
	Matrix[3] = LinkToVector[3];
}

float DimensionedVector::operator[] (const int Index) const{
	return Matrix[Index];
}

float& DimensionedVector::operator[] (const int Index){
	return Matrix[Index];
}

DimensionedVector DimensionedVector::operator + (const DimensionedVector& LinkToVector) const{
	return DimensionedVector((*this)[0] + LinkToVector[0], (*this)[1] + LinkToVector[1], (*this)[2] + LinkToVector[2], (*this)[3] + LinkToVector[3]);
}

DimensionedVector DimensionedVector::operator - (const DimensionedVector& LinkToVector) const{
	return DimensionedVector((*this)[0] - LinkToVector[0], (*this)[1] - LinkToVector[1], (*this)[2] - LinkToVector[2], (*this)[3] - LinkToVector[3]);
}

DimensionedVector& DimensionedVector::operator = (const DimensionedVector& LinkToVector){
	Matrix[0] = LinkToVector[0];
	Matrix[1] = LinkToVector[1];
	Matrix[2] = LinkToVector[2];
	Matrix[3] = LinkToVector[3];
	return *this;
}

DimensionedVector DimensionedVector::operator * (const DimensionedVector& LinkToVector) const{
	return DimensionedVector(Matrix[0] * LinkToVector[0], Matrix[1] * LinkToVector[1], Matrix[2] * LinkToVector[2], Matrix[3] * LinkToVector[3]);
}

DimensionedVector DimensionedVector::operator * (float scale) const{
	return DimensionedVector(Matrix[0] * scale,Matrix[1] * scale, Matrix[2] * scale, Matrix[3] * scale);
}

float DimensionedVector::Length() const{
	return sqrtf(Matrix[0] * Matrix[0] + Matrix[1] * Matrix[1] + Matrix[2] * Matrix[2] + Matrix[3] * Matrix[3]);
}

float DimensionedVector::LengthSqr() const{
	return Matrix[0] * Matrix[0] + Matrix[1] * Matrix[1] + Matrix[2] * Matrix[2] + Matrix[3] * Matrix[3];
}

float DimensionedVector::DotProduct(const DimensionedVector& LinkToVector) const{
	return Matrix[0] * LinkToVector[0] + Matrix[1] * LinkToVector[1] + Matrix[2] * LinkToVector[2] + Matrix[3] * LinkToVector[3];
}

void DimensionedVector::Normalize(){
	float length = this->Length();

	if (length > 1.0e-8f){
		float invLen = 1.0f / length;

		Matrix[0] *= invLen;
		Matrix[1] *= invLen;
		Matrix[2] *= invLen;
		Matrix[3] *= invLen;
	}
}

DimensionedVector DimensionedVector::CrossProduct(const DimensionedVector& LinkToVector) const{
	return DimensionedVector((Matrix[1] * LinkToVector[2] - Matrix[2] * LinkToVector[1]), (Matrix[2] * LinkToVector[0] - Matrix[0] * LinkToVector[2]), (Matrix[0] * LinkToVector[1] - Matrix[1] * LinkToVector[0]), 1.0f);
}

void DimensionedVector::SetZero(){
	Matrix[0] = Matrix[1] = Matrix[2] = Matrix[3] = 0.0f;
}
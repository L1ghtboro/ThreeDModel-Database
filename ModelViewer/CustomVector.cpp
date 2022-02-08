#include "CustomVector.h"

FlatVector::FlatVector(void){
	Initialize(0.0f, 0.0f);
}

FlatVector::FlatVector(float x, float y){
	Initialize(x, y);
}

FlatVector::FlatVector(const FlatVector& Vector){
	Copy(Vector);
}

FlatVector& FlatVector::operator= (const FlatVector& rhs) {
	if (this != &rhs)
		Copy(rhs);
	return *this;
}

const FlatVector FlatVector::operator+(const FlatVector& other) const {
	FlatVector result;
	result.SetX(StoreX + other.GetX()), result.SetY(StoreY + other.GetY());
	return result;
}

const FlatVector FlatVector::operator-(const FlatVector& other) const {
	FlatVector result;
	result.SetX(StoreX - other.GetX()), result.SetY(StoreY - other.GetY());
	return result;
}

void FlatVector::Initialize(float x, float y) {
	StoreX = x, StoreY = y;
}

void FlatVector::Copy(const FlatVector& Vector) {
	StoreX = Vector.GetX(), StoreY = Vector.GetY();
}
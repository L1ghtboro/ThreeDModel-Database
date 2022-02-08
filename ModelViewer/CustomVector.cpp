#include "CustomVector.h"

FlatVector::FlatVector(void){
	Initialize(0.0f, 0.0f);
}

FlatVector::FlatVector(float X, float Y){
	Initialize(X, Y);
}

FlatVector::FlatVector(const FlatVector& Vector){
	Copy(Vector);
}

FlatVector& FlatVector::operator= (const FlatVector& VectorRef) {
	if (this != &VectorRef)
		Copy(VectorRef);
	return *this;
}

const FlatVector FlatVector::operator+(const FlatVector& ThirdParty) const {
	FlatVector Result;
	Result.SetX(StoreX + ThirdParty.GetX()), Result.SetY(StoreY + ThirdParty.GetY());
	return Result;
}

const FlatVector FlatVector::operator-(const FlatVector& ThirdParty) const {
	FlatVector Result;
	Result.SetX(StoreX - ThirdParty.GetX()), Result.SetY(StoreY - ThirdParty.GetY());
	return Result;
}

void FlatVector::Initialize(float X, float Y) {
	StoreX = X, StoreY = Y;
}

void FlatVector::Copy(const FlatVector& Vector) {
	StoreX = Vector.GetX(), StoreY = Vector.GetY();
}
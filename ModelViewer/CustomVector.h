#pragma once
#include <string>

class FlatVector {
public:
	FlatVector(void);
	FlatVector(float X, float Y);
	FlatVector(const FlatVector& Vector);
	~FlatVector(void){}

	FlatVector& operator= (const FlatVector& rhs);
	const FlatVector operator+(const FlatVector& other) const;
	const FlatVector operator-(const FlatVector& other) const;

	float GetX(void) const { return StoreX; }
	void SetX(float X) { StoreX = X; }
	float GetY(void) const{ return StoreY; }
	void SetY(float Y){ StoreY = Y; }

private:
	float StoreX;
	float StoreY;

	void Initialize(float X, float Y);
	void Copy(const FlatVector& Vector);
};
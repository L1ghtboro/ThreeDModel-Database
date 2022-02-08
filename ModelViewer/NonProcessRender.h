#pragma once

class VectorMatrix;

class Render{
public:
	virtual void RenderInit(const VectorMatrix* trans = 0) = 0;
};
#pragma once

class VectorMatrix;

class Render{
public:

	virtual void RenderInit(const VectorMatrix* TranslatedRate = 0) = 0;
};
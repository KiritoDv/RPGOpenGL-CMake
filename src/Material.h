#pragma once
#include "Texture.h"
class Material{
	public:
		const char *displayName;
		int textureId;
		int materialId;
		Material();
		Material(int materialId, int textureId, const char* displayName);
		Texture getTexture();		
	private:
		Texture tex;
};


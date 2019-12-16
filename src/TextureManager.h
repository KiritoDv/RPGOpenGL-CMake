#pragma once
#include "Block.h"
#include <map>
#include "Texture.h"

using namespace std;

class TextureManager{
	public:
		static TextureManager& instance() { static TextureManager textureManager; return textureManager; }
		void loadTexture(int id, const char* filename);
		Texture getTexture(int id);
	private:
		map<int, Texture> textures;
};


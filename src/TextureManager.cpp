#include "TextureManager.h"
#include <iostream>

void TextureManager::loadTexture(int id, const char *path) {
	if(textures.find(id) == textures.end())
		textures.insert(pair<int, Texture>(id, Texture(path)));	
}

Texture TextureManager::getTexture(int id) {	
	if (textures.find(id) != textures.end()) {		
		return textures[id];
	}
	return Texture();
}

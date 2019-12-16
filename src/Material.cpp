#include "Material.h"
#include "TextureManager.h"

Material::Material() {
	textureId = -1;
	materialId = -1;
	displayName = "NULL";
}

Material::Material(int id, int texture, const char* display) {
	materialId = id;
	textureId = texture;
	displayName = display;
	tex = TextureManager::instance().getTexture(texture);
}

Texture Material::getTexture() {
	return tex;
}
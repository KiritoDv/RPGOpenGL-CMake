#include "Texture.h"
#include "GL/glew.h"
#include <iostream>

#include <stb_image.h>

Texture::Texture(){

}

Texture::Texture(const char *filename) {

	//printf("Loading %s\n", filename);

	glGenTextures(1, &id);

	int nrChannels;
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, STBI_rgb_alpha);

	if (data) {
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);		

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else {
		//printf("Unable to load texture");
	}
}

void Texture::bindTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, id);
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}
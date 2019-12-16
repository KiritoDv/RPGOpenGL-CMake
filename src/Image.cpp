#include "Image.h"

#include <stb_image.h>
#include <iostream>

void Image::initData(const char* filename) {	
	int nrChannels;	
	while (!_imgData) {
		_imgData = stbi_load(filename, &width, &height, &nrChannels, STBI_rgb_alpha);
		std::cout << "Loading Texture" << std::endl;
	}
}

void Image::freeData() {
	//stbi_image_free(data);
}
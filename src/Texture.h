#pragma once

class Texture{
	private:
		unsigned int id;
		int width;
		int height;		
	public:
		Texture();
		Texture(const char *filename);
		void bindTexture();
		int getWidth();
		int getHeight();
		int getTextureId();
};


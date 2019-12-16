#pragma once
#include "Color.h"

class GFXUtil{
	public:
		static void drawRect(float x, float y, float w, float h, Color c);
		static void drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight);
};


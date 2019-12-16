#pragma once
#include <glm/vec3.hpp>
#include "Color.h"
#include "Material.h"

using namespace glm;

class Block{
	public:
		vec3 location;
		Color color;
		Material material;
		Block();
		Block(vec3 location, Material material);
	private: 
		Color genColor();
};


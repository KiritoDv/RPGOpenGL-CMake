#pragma once

#include "Material.h"

class MaterialManager{
	public:
		static MaterialManager& instance() { static MaterialManager materialManager; return materialManager; }
		Material GRASS;
		Material STONE;
	private:
		MaterialManager();
};


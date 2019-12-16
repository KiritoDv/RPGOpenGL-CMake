#pragma once
#include "Block.h"
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Map{
	public:
		static Map& instance() { static Map map; return map; }

		vector<Block> blocks;
		void setBlock(vec3 loc, Material m);
};


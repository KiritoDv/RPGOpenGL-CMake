#include "Map.h"

void Map::setBlock(vec3 loc, Material m) {
	blocks.push_back(Block(loc, m));
}
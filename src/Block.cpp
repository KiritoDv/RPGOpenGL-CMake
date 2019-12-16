#include "Block.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Block::Block() {
	Block::location = vec3();
	Block::material = Material();
	Block::color = genColor();
}

Block::Block(vec3 location, Material material) {
	Block::location = location;
	Block::material = material;
	Block::color = genColor();
}

Color Block::genColor() {
	srand(time(NULL));
	int c = 255 - (rand() % 16);
	return Color(c, c, c);
}
#include "MapRenderer.h"

#include "Texture.h"
#include "GFXUtil.h"
#include <vector>
#include <algorithm>
#include "GL/glew.h"
#include "IDisplay.h"
#include "Camera.h"
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

MaterialManager* mManager;
IDisplay* dManager;

void MapRenderer::initMap(MaterialManager mm) {
	mManager = &mm;
	dManager = &IDisplay::instance();

	for (int a = 0; a < 200; a++) {
		for (int b = 0; b < 200; b++) {
			map.setBlock(vec3(a, b, 0), mManager->GRASS);
		}
	}

	map.setBlock(vec3(0, 0, 0), mManager->STONE);

}

void MapRenderer::drawMap(TextureManager tManager) {

	vector<Block> mapCopy;
	// Remove blocks outside the camera

	copy_if(map.blocks.begin(), map.blocks.end(), std::back_inserter(mapCopy), [](Block b) {

		vec3 pos = Camera::instance().getPosition();
		int tW = 32;
		int tH = 32;
		int x = (b.location.x - b.location.y) * (tW / 2);
		int y = (((b.location.x + b.location.y) * (tH / 4))) - ((b.location.z) * (tH / 2));

		return (x + tW > pos.x&& y + tH > pos.y&& x <= (pos.x + dManager->windowWidth) && y <= (pos.y + dManager->windowHeight));
	});

	// Filter blocks by Z

	sort(mapCopy.begin(), mapCopy.end(), [](Block a, Block b) {
		return (a.location.x + a.location.y + a.location.z) < (b.location.x + b.location.y + b.location.z);
	});

	// Draw blocks

	for (auto i = mapCopy.begin(); i != mapCopy.end(); i++) {
		Block b = *i;

		int tW = 32;
		int tH = 32;

		int x = (b.location.x - b.location.y) * (tW / 2);
		int y = (((b.location.x + b.location.y) * (tH / 4))) - ((b.location.z) * (tH / 2));

		tManager.getTexture(b.material.textureId).bindTexture();
		b.color.bindColor();

		//printf("Drawing Block owo");

		GFXUtil::drawTexture(x, y, 0, 0, tW, tH, tW, tH);
	}
}

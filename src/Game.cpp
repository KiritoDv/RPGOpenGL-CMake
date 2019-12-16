#include "Game.h"

#include <GL/glew.h>
#include "GFXUtil.h"
#include "TextureManager.h"
#include "MapRenderer.h"

MapRenderer mapRenderer;
TextureManager tex = TextureManager::instance();

void Game::init() {
	tex.loadTexture(-1, "assets/Null.png");
	tex.loadTexture(0, "assets/Grass.png");
	tex.loadTexture(1, "assets/Stone.png");

	mapRenderer.initMap(MaterialManager::instance());
}

void Game::update() {
	
}

void Game::draw() {
	glColor3f(1, 1, 1);
	mapRenderer.drawMap(tex);
}
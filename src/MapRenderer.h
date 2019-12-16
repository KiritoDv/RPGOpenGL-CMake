#pragma once

#include "Map.h"
#include "TextureManager.h"
#include "MaterialManager.h"

class MapRenderer{
	public:
		virtual void drawMap(TextureManager tManager);
		void initMap(MaterialManager mManager);	
	private:
		Map map = Map::instance();		
};


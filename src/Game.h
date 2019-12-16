#pragma once

class Game {
	public:
		static Game& instance() { static Game game; return game; }
		void init();
		void update();
		void draw();
};

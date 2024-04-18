#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Player.h"
#include "EnemyManager.h"
#include "LevelManager.h"
#include "Background.h"

namespace prg
{
	class GameWindow 
	{
		public:
			GameWindow();
			~GameWindow();

			void main_loop(void);

		private:
			sf::RenderWindow  m_render_window;
			sf::Event         m_window_events;
			bool              m_running;

		private: // Game objects
			game::Player        m_player;
			game::LevelManager  m_level_manager;
			game::EnemyManager  m_enemy_manager;
			game::Background    m_background;

		private: // mainloop functions
			inline void m_update_screen();
			inline void m_render_screen();
	};
}
#endif // !GAME_WINDOW_H
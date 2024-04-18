#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Constants.h"


#define DEFAULT_LEVEL 1u

#define FONT_PATH "res/game font.ttf"

namespace game 
{
	class LevelManager
	{
		public:
			LevelManager();
			~LevelManager();

			void renderText(sf::RenderTarget& target);

			void addPoints();
			void resetPoints();

			const uint8_t& getPointReference()
			{	return m_current_points;	}

		private: // Variables
			uint8_t   m_current_points;
			sf::Text  m_level_text;
			sf::Font  m_level_font;

		private:
			void m_updateText();
	};
}
#endif // ! LEVEL_MANAGER_H
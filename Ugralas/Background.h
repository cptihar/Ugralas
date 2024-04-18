#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"

#define  ROWS		WINDOW_HEIGHT / BLOCK_SIZE
#define  COLUMNS    WINDOW_WIDTH  / BLOCK_SIZE

// Colors
#define DEFAULT_COLOR sf::Color::Yellow

#define GRASS_COLOR			   sf::Color(87, 250, 2)
#define ROAD_COLOR			   sf::Color(92, 92, 92)
#define ROAD_SPEPARATOR_COLOR  sf::Color::White //sf::Color(232, 184, 9)

// Ids
#define ROAD_ID  1
#define GRASS_ID 2

namespace game 
{
	class Background
	{
		public:
			Background();
			~Background();

			void renderBackgrounds(sf::RenderTarget& target);

			const auto& getTileMap() const
			{	return m_tile_map;	}

			const std::vector<float> getLanes() const;

		private: // Variables

			sf::RectangleShape  m_tile_body;

			// Tile map
			uint8_t m_tile_map[ROWS][COLUMNS] = {
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Grass
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Grass
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Grass
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Road
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Grass
				{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}  // Grass
			};

		private: // Functions
			void  m_drawRoadTile(sf::RenderTarget& target);
	};
}
#endif // ! BACKGROUND_H
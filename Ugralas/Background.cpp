#include "Background.h"

game::Background::Background()
{
	m_tile_body.setSize({ (float)BLOCK_SIZE, (float)BLOCK_SIZE });
	m_tile_body.setFillColor(sf::Color::Yellow);
}

game::Background::~Background()
{
}


//////////////////////////////////////////////////////////////////|
// 
//  Iterates through the tile map and draws the tiles accordingly
//
//  Called by: mainloop
// 
//  Return: void
// 
//////////////////////////////////////////////////////////////////|
void game::Background::renderBackgrounds(sf::RenderTarget& target)
{
	for (uint8_t i = 0; i < ROWS; ++i) {
		for (uint8_t j = 0; j < COLUMNS; ++j) {

			m_tile_body.setPosition((float)BLOCK_SIZE * j, (float)BLOCK_SIZE * i);
			// Determine tile logic
			switch (m_tile_map[i][j]) {

				// Grass Tile //
				case GRASS_ID:
					m_tile_body.setFillColor(GRASS_COLOR);
					target.draw(m_tile_body);
					break;

				// Road Tile //
				case ROAD_ID:
					m_tile_body.setFillColor(ROAD_COLOR);
					target.draw(m_tile_body);
					m_drawRoadTile(target);
					break;

				// Default //
				default:
					m_tile_body.setFillColor(DEFAULT_COLOR);
					target.draw(m_tile_body);
					break;
			}	
		}
	}
}


/////////////////////////////////////|
// 
//  Returns the lanes' Y coordinates
// 
//  Return: const std::vector<float>
//
/////////////////////////////////////|
const std::vector<float> game::Background::getLanes() const
{
	std::vector<float> ret = {};

	for (uint8_t i = 0; i < ROWS; ++i) {
		if (m_tile_map[i][0] == ROAD_ID) {
			ret.push_back(float(i * BLOCK_SIZE));
		}
	}

	return ret;
}


/////////////////////////////////////////////////////|
// 
//  Draws the the road tiles
// 
//  Changes the tile body!!!!!
//		-> But resets it to the standard tile format
// 
//  Return: void
//
/////////////////////////////////////////////////////|
void game::Background::m_drawRoadTile(sf::RenderTarget& target)
{
	// Get position
	sf::Vector2f block_position = m_tile_body.getPosition();

	// Reshape it
	m_tile_body.setFillColor(ROAD_SPEPARATOR_COLOR);
	m_tile_body.setSize({ BLOCK_SIZE - 10.0f, BLOCK_SIZE / 4.0f });

	float diffX = BLOCK_SIZE - m_tile_body.getSize().x;
	m_tile_body.setPosition(block_position.x + diffX / 2.0f,
							block_position.y + m_tile_body.getSize().y * 1.5f);

	// Draw
	target.draw(m_tile_body);

	// Setup for tile use
	m_tile_body.setSize({ (float)BLOCK_SIZE, (float)BLOCK_SIZE });
}
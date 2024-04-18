#include "LevelManager.h"

game::LevelManager::LevelManager()
	:m_current_points(DEFAULT_LEVEL)
{
	// Setup the text
	m_level_font.loadFromFile(FONT_PATH);
	m_level_text.setFont(m_level_font);
	m_level_text.setFillColor(sf::Color::Red);
	m_level_text.setPosition({0.0f, WINDOW_HEIGHT - 2 * static_cast<float>(m_level_text.getCharacterSize())});


	m_updateText();
}

game::LevelManager::~LevelManager()
{
}


///////////////////////////|
// 
//  Renders the text
//  
//  Called by the mainloop
// 
//  Return: void
//
///////////////////////////|
void game::LevelManager::renderText(sf::RenderTarget& target)
{
	target.draw(m_level_text);
}


/////////////////////////|
// 
//  Increments the level
// 
//  Updates the text
// 
//  Return: void
//
/////////////////////////|
void game::LevelManager::addPoints()
{
	m_current_points++;
	m_updateText();
}


/////////////////////////////////////////////|
// 
//  Resets the points value to default value
//  
//	Return: void
// 
/////////////////////////////////////////////|
void game::LevelManager::resetPoints()
{
	m_current_points = DEFAULT_LEVEL;
	m_updateText();
}


/////////////////////|
// 
//  Updates the text
// 
//  Return: void
//
/////////////////////|
void game::LevelManager::m_updateText()
{
	std::stringstream ss;
	ss << (int) m_current_points;
	m_level_text.setString(ss.str());
}

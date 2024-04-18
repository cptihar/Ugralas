#include "Window.h"

prg::GameWindow::GameWindow()
	:m_running(true), 
	 m_window_events(), 
	 m_level_manager(), 
	 m_enemy_manager(m_level_manager.getPointReference()),
	 m_background()
{
	m_render_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		                  "xdxd",
		                  sf::Style::Close | sf::Style::Titlebar);
	m_render_window.setFramerateLimit(WINDOW_FPS);

	m_enemy_manager.setupEnemies(m_background.getLanes());
}

prg::GameWindow::~GameWindow()
{
}


///////////////////////////////////|
//
//  It is the mainloop
// 
//  Handles updating and rendering
// 
//  Return: void
// 
///////////////////////////////////|
void prg::GameWindow::main_loop(void)
{
	while (m_running) {
		m_update_screen();
		m_render_screen();
	}
}


///////////////////////////////////////////|
//
//  Updates everything related to the game
// 
//  Updates: 
//		-> Events
//		-> Objects
//
//  Call happens every frame
// 
//  Return: void
//
///////////////////////////////////////////|
inline void prg::GameWindow::m_update_screen()
{
	// Handle events
	auto current_key = sf::Keyboard::B;
	while (m_render_window.pollEvent(m_window_events)) {
		switch (m_window_events.type) {
			case sf::Event::Closed:
				m_running = false;
				break;

			case sf::Event::KeyPressed:
				current_key = m_window_events.key.code;
				break;

			default:
				break;
		}
	}

	// Object updaters
	m_player.update_player(current_key);
	m_enemy_manager.updateEnemies(m_player.getHitBox());

	if (m_enemy_manager.hadCollision()) {
		m_player.setDefaultPosition();
		m_level_manager.resetPoints();
	}

	else if (m_player.finishedLevel()) {
		m_level_manager.addPoints();
		m_player.resetFinishedLevel();
	}
}


///////////////////////////////////////////|
//
//  Renders everything related to the game
// 
//  Renders: 
//		-> Objects
//
//  Call happens every frame
// 
//  Return: void
//
///////////////////////////////////////////|
inline void prg::GameWindow::m_render_screen()
{
	m_render_window.clear(sf::Color(161, 161, 161)); // Clear the window

	m_background.renderBackgrounds(m_render_window);
	m_player.render_object(m_render_window);
	m_enemy_manager.renderEnemies(m_render_window);
	m_level_manager.renderText(m_render_window);

	m_render_window.display(); // Display objects
}
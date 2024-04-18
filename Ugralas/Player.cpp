#include "Player.h"

game::Player::Player()
	:m_finished_level(false)
{
	m_player_texture.loadFromFile(PLAYER_SPRITE_PATH);
	util::GameObject::set_object_texture(m_player_texture);
	util::GameObject::set_origin_to_middle();

	// setup player scale
	sf::Vector2f player_size = { util::GameObject::get_bounds().width,
								 util::GameObject::get_bounds().height };

	util::GameObject::set_object_scale({ BLOCK_SIZE / player_size.x,
									     BLOCK_SIZE / player_size.y });

	// Setup hitbox
	m_hitbox.setSize({ util::GameObject::get_bounds().width - 20.0f,
					   util::GameObject::get_bounds().height - 20.0f });

	m_hitbox.setOrigin(m_hitbox.getGlobalBounds().width / 2, 
					   m_hitbox.getGlobalBounds().height / 2);

	setDefaultPosition();
}


//////////////////////////////////|
// 
//  Updater for the player
// 
//  Called each frame by mainloop
// 
//  Return: void
// 
//////////////////////////////////|
void game::Player::update_player(sf::Keyboard::Key current_key)
{
	
	sf::FloatRect player_information = util::GameObject::get_bounds();

	// Calculate horizontal, vertical movement
	auto move_speed_x = ((current_key == sf::Keyboard::A) * -player_information.width) + ( (current_key == sf::Keyboard::D) * player_information.width);
	auto move_speed_y = ((current_key == sf::Keyboard::W) * -player_information.height) + ( (current_key == sf::Keyboard::S) * player_information.height);

	// Move the player
	util::GameObject::move_object({ move_speed_x, move_speed_y });

	// Handle the rotation
	float rotation = m_calculateRotations(current_key);

	if (rotation != 0.0f)
		util::GameObject::set_object_rotation(rotation);

	// Update helpers
	m_updateOutOfBounds();

	// set the hitbox's position
	m_hitbox.setPosition(util::GameObject::get_position());
	
}


/////////////////////////////////////////////////////|
// 
//  Calculates the rotation based on the pressed key
// 
//  Parameter: sf::Keyboard::Key
// 
//  If no keys were pressed returns 0
// 
//  Return: float
//
/////////////////////////////////////////////////////|
float game::Player::m_calculateRotations(sf::Keyboard::Key key)
{
	float ret = 0.0f;

	float rotate_left = (key == sf::Keyboard::A) * 270.0f; // Rotate left
	float rotate_right = (key == sf::Keyboard::D) * 90.0f; // Rotate right
    float rotate_up = (key == sf::Keyboard::W) * 360.0f;   // Rotate up
	float rotate_down = (key == sf::Keyboard::S) * 180.0f; // Rotate down

	ret += (rotate_left + rotate_right + rotate_up + rotate_down);
	return ret;
}


////////////////////////////////|
// 
//  Returns the player's hitbox
//
//  Return: const sf::FloatRect
// 
////////////////////////////////|
const sf::FloatRect game::Player::getHitBox() const
{
	return m_hitbox.getGlobalBounds();
}

///////////////////////////////////|
// 
//  Defaults the player's position
// 
//  Return: void
//
///////////////////////////////////|
void game::Player::setDefaultPosition()
{
	util::GameObject::set_object_position({ WINDOW_WIDTH / 2, WINDOW_HEIGHT - (BLOCK_SIZE / 2) });
	util::GameObject::set_object_rotation(360.0f);
}


///////////////////////////////////////////////|
// 
//  Checks whether the player is out play area
//
//  Return: void
// 
///////////////////////////////////////////////|
void game::Player::m_updateOutOfBounds()
{
	// Sprite position
	auto pos = util::GameObject::get_position();

	if (pos.x >= WINDOW_WIDTH || pos.x < 0 || 
		pos.y >= WINDOW_HEIGHT || pos.y < 0) {

		m_finished_level = (pos.y < 0);
		setDefaultPosition();
	}
}
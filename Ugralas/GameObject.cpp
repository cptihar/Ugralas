#include "GameObject.h"

util::GameObject::GameObject(const sf::Texture& texture)
{
	set_object_texture(texture);
}


util::GameObject::~GameObject()
{}


////////////////////////////|
//
//  Moves the game object 
// 
//  Parameter: sf::Vector2f
//  
//  Return: void
//
////////////////////////////|
void util::GameObject::move_object(const sf::Vector2f move_speed)
{
	m_sprite.move(move_speed);
}


/////////////////////////////////////|
// 
//  Renders the object to the screen
// 
//  Parameter: sf::RenderTarget&
// 
//  Return: void
//
/////////////////////////////////////|
void util::GameObject::render_object(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}


//////////////////////////////////|
// 
//  Setter for the object's scale
// 
//  Parameter: sf::Vector2f
// 
//  Return: void
//
//////////////////////////////////|
void util::GameObject::set_object_scale(const sf::Vector2f new_scale)
{
	m_sprite.setScale(new_scale);
}


/////////////////////////////////////|
// 
//  Setter for the object's position
// 
//  Parameter: sf::Vector2f
// 
//  Return: void
//
/////////////////////////////////////|
void util::GameObject::set_object_position(const sf::Vector2f new_position)
{
	m_sprite.setPosition(new_position);
}


////////////////////////////////////|
// 
//  Setter for the object's texture
// 
//	Parameter: const sf::Texture&
// 
//  Return: void
//
////////////////////////////////////|
void util::GameObject::set_object_texture(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}


/////////////////////////////////////////|
// 
//  Setter for the object's texture rect
//
//  Parameter: const sf::IntRect
// 
//  Return: void
// 
/////////////////////////////////////////|
void util::GameObject::set_object_texture_rect(const sf::IntRect new_rect)
{
	m_sprite.setTextureRect(new_rect);
}


/////////////////////////////////////|
// 
//  Setter for the object's rotation
// 
//  Parameter: float
// 
//  Return: void
//
/////////////////////////////////////|
void util::GameObject::set_object_rotation(float angle)
{
	m_sprite.setRotation(angle);
}


//////////////////////////////////////////|
// 
//  Sets the sprites origin to the middle
// 
//  Should be called after initialization
// 
//  Parameters: none
//
//  Return: void
//
//////////////////////////////////////////|
void util::GameObject::set_origin_to_middle(void)
{
	sf::FloatRect object_information = m_sprite.getGlobalBounds();

	m_sprite.setOrigin(object_information.width / 2, object_information.height / 2);
}

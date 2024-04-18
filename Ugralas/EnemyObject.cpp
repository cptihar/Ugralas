#include "EnemyObject.h"

util::EnemyObject::EnemyObject(const sf::Texture& ob_texture, util::EnemyInfo enemy_info)
	:m_player_size({0.0f, 0.0f}),
	 m_enemy_info(enemy_info),
	 m_player_intersection(false)
{
	// Setup the sprite
	util::GameObject::set_object_texture(ob_texture);
	m_player_size = { util::GameObject::get_bounds().width, util::GameObject::get_bounds().height };

	float y_factor = BLOCK_SIZE / m_player_size.y;
	util::GameObject::set_object_scale({ y_factor * -enemy_info._direction, y_factor });
}

util::EnemyObject::~EnemyObject()
{}


///////////////////////////////////////////////|
// 
//  Checks whether the object is out of bounds
// 
//  Return: const bool
//
///////////////////////////////////////////////|
const bool util::EnemyObject::outOfBounds() const
{
	return (util::GameObject::get_position().x < -util::GameObject::get_bounds().width - 20.0f) ||
		   (util::GameObject::get_position().x > WINDOW_WIDTH + util::GameObject::get_bounds().width + 20.0f);
}


/////////////////////////////////////////////////////////////|
// 
//  Returns whether there is an intersection with the player
//
//  Return: const bool
//
/////////////////////////////////////////////////////////////|
const bool util::EnemyObject::intersectsPlayer() const
{
	return m_player_intersection;
}


/////////////////////////////////////////////////|
// 
//  Returns the spawn position for the right side
// 
//  Return: const float
// 
/////////////////////////////////////////////////|
const float util::EnemyObject::getRightSideSpawn() const
{
	return (WINDOW_WIDTH + util::GameObject::get_bounds().width);
}


/////////////////////////////////////////////////|
// 
//  Returns the spawn position for the left side
// 
//  Return: const float
// 
/////////////////////////////////////////////////|
const float util::EnemyObject::getLeftSideSpawn() const
{
	return (-util::GameObject::get_bounds().width);
}


///////////////////////////////|
// 
//  Updates the enemy object
//  Handles:
//		-> Movement
//		-> Out of bound checks
// 
//
//  Return: void
//
///////////////////////////////|
void util::EnemyObject::updateEnemy(const sf::FloatRect& player_bounds)
{
	// Move the enemy
	util::GameObject::move_object({ m_enemy_info._speed * m_enemy_info._direction, 0.0f });

	// Update player collision
	if (util::GameObject::get_bounds().intersects(player_bounds)) {
		m_player_intersection = true;
	}
}
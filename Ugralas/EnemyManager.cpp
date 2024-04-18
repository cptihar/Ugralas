#include "EnemyManager.h"

game::EnemyManager::EnemyManager(const uint8_t& level)
	:m_current_level(level),
	 m_collided(false)
{}

game::EnemyManager::~EnemyManager()
{}


///////////////////////////////////////////////////|
// 
//  Renders the enemy objects stored in the vector
//
//  Should be called once, by mainloop
// 
//  Return: void
// 
///////////////////////////////////////////////////|
void game::EnemyManager::renderEnemies(sf::RenderTarget& target)
{
	for (const auto& enemy : m_enemy_vector) {
		enemy.render_object(target);
	}
}


///////////////////////////////////////////////////|
// 
//  Updates the enemy objects stored in the vector
//
//  Should be called once, by mainloop
// 
//  Return: void
// 
///////////////////////////////////////////////////|
void game::EnemyManager::updateEnemies(const sf::FloatRect& player_bounds)
{
	m_collided = false;

	for (auto enemy = m_enemy_vector.begin(); enemy != m_enemy_vector.end();) {

		// Update the enemy
		enemy->updateEnemy(player_bounds);

		// Check for collision
		if (enemy->intersectsPlayer()) {
			m_collided = true;
		}
			
		// Check whether it is out of bounds
		if (enemy->outOfBounds() || m_collided) {

			// Get the lane
			float lane_y = enemy->get_position().y;

			// Delete the enemy
			m_enemy_vector.erase(enemy);

			auto new_enemy = m_spawnEnemy();

			// Adjust spawn position
			if (new_enemy.getInfo()._direction == ENEMY_DIRECTION_LEFT)
				new_enemy.set_object_position({ new_enemy.getRightSideSpawn(), lane_y });

			else
				new_enemy.set_object_position({new_enemy.getLeftSideSpawn(), lane_y });

			m_enemy_vector.push_back(new_enemy);

			if (m_collided)
				break;
		}
		else
			++enemy;
	}
}


/////////////////////////////|
// 
//  Sets up the enemy vector
//
//  Return: void
//
/////////////////////////////|
void game::EnemyManager::setupEnemies(const std::vector<float>& lanes)
{
	m_enemy_vector.reserve(lanes.size()); // optimize for emplace_back

	// 
	for (auto lane : lanes) {
		auto new_enemy = m_spawnEnemy();
		new_enemy.set_object_position({ new_enemy.get_position().x, lane });
		m_enemy_vector.emplace_back(new_enemy);
	}
}


//////////////////////////////////////////////////////|
// 
//  Returns whether the player and the enemy collided
//  
//  Return: const bool
//
//////////////////////////////////////////////////////|
const bool game::EnemyManager::hadCollision() const
{
	return m_collided;
}


//////////////////////////////|
// 
//  Handles enemy spawning
// 
//  Return: util::EnemyObject
//
//////////////////////////////|
util::EnemyObject game::EnemyManager::m_spawnEnemy()
{
	// Handle random direction
	int rand_dir = rand() % 2;
	int8_t final_dir = (ENEMY_DIRECTION_LEFT & -(rand_dir == 0)) + (ENEMY_DIRECTION_RIGHT & (rand_dir == 1));

	// Handle speed
	int spd_multiplier = (rand() % 6) + 1;
	float enemy_speed = (m_current_level % 10) + DEFAULT_ENEMY_SPEED + (float)spd_multiplier;

	// Handle random type
	uint8_t type = m_generateEnemyType();

	return util::EnemyObject(m_texture_manager.getTexture(type), 
							 util::EnemyInfo(final_dir, enemy_speed));
}


///////////////////////////////////////|
// 
//	Generates a enemy type random type
//
//  Return: const int
//
///////////////////////////////////////|
const int game::EnemyManager::m_generateEnemyType()
{
	// Generate a random number
	int random = static_cast<int>(rand() % 100) + 1;

	// Calculate the identifiers
	int fire_truck = util::enemy_identifiers::fire_truck & ((random > 1 && random <= 33) * util::enemy_identifiers::fire_truck);
	int car = util::enemy_identifiers::car & ((random > 33 && random <= 67) * util::enemy_identifiers::car);
	int tractor = util::enemy_identifiers::tractor & ((random > 67 && random <= 100) * util::enemy_identifiers::tractor);

	return fire_truck + car + tractor;
}
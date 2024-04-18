#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "EnemyObject.h"

#include <vector>

#define DEFAULT_ENEMY_SPEED 5.0f

namespace game
{
	class EnemyManager
	{
		public:
			EnemyManager(const uint8_t& level);
			~EnemyManager();

			void renderEnemies(sf::RenderTarget& target);
			void updateEnemies(const sf::FloatRect& player_bounds);

			void setupEnemies(const std::vector<float>& lanes);

			const bool hadCollision() const;


		private: // Variables
			std::vector<util::EnemyObject>  m_enemy_vector;
			util::TextureManager		    m_texture_manager;
			const uint8_t&					m_current_level;
			bool							m_collided;

		private:
			util::EnemyObject  m_spawnEnemy();
			const int		   m_generateEnemyType();
	};
}
#endif // ! ENEMY_MANAGER_H
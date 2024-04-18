#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "GameObject.h"
#include "Constants.h"

#define ENEMY_DIRECTION_LEFT  -1
#define ENEMY_DIRECTION_RIGHT  1
#define DEFAULT_SPEED          5.0f

namespace util
{
	struct EnemyInfo {
		int8_t _direction;
		float   _speed;

		EnemyInfo()
			:_direction(0), _speed(0.0f)
		{}

		EnemyInfo(uint8_t dir, float spd)
			:_direction(dir), _speed(spd)
		{}
	};

	class EnemyObject : public util::GameObject
	{
		public:
			EnemyObject() = default;
			EnemyObject(const sf::Texture& ob_texture, util::EnemyInfo enemy_info);

			~EnemyObject();

			const bool outOfBounds() const;
			const bool intersectsPlayer() const;

			const float getRightSideSpawn() const;
			const float getLeftSideSpawn() const;

			const util::EnemyInfo getInfo() const
			{	return m_enemy_info;	}

			void updateEnemy(const sf::FloatRect& player_bounds);

		private: // Variables
			sf::Vector2f     m_player_size;
			util::EnemyInfo  m_enemy_info;
			bool			 m_player_intersection;

		private: // Helper functions

	};
}
#endif // ! ENEMY_OBJECT_H
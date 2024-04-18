#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Constants.h"

#define PLAYER_SPRITE_PATH  "res/ezmi.png"

namespace game
{
	class Player : public util::GameObject
	{
		public:
			Player();
			void update_player(sf::Keyboard::Key current_key);

			const bool finishedLevel() const
			{	return m_finished_level;	}

			void resetFinishedLevel(void) 
			{	m_finished_level = false;	}

			const sf::FloatRect  getHitBox() const;
			void				 setDefaultPosition();

		private: // Variables
			sf::Texture			m_player_texture;
			bool				m_finished_level;
			sf::RectangleShape  m_hitbox;

		private: // Helper functions
			float  m_calculateRotations(sf::Keyboard::Key key);
			void   m_updateOutOfBounds();
	};
}
#endif // ! PLAYER_H
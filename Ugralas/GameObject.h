#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace util 
{
	class GameObject
	{
		public:
			GameObject() = default;
			GameObject(const sf::Texture& texture);
			virtual ~GameObject();

			void  render_object(sf::RenderTarget& target) const;
			void  set_object_scale(const sf::Vector2f new_scale);
			void  set_object_position(const sf::Vector2f new_position);
			void  move_object(const sf::Vector2f move_speed);
			void  set_object_texture(const sf::Texture& texture);
			void  set_object_texture_rect(const sf::IntRect new_rect);
			void  set_object_rotation(float angle);
			void  set_origin_to_middle(void);

			const sf::Vector2f get_position() const
			{	return m_sprite.getPosition();	}

			const sf::FloatRect get_bounds() const
			{	return m_sprite.getGlobalBounds();	}

			const float get_rotation() const
			{	return m_sprite.getRotation();	}

		private:
			sf::Sprite  m_sprite; // The game object's sprite
	};
}
#endif // ! GAME_OBJECT_H
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <string>

#define  CAR_TEXTURE_PATH      "res/kocsika.png"
#define  FIRE_TEXTURE_PATH	   "res/tuzoto.png"
#define  TRACTOR_TEXTURE_PATH  "res/jancsi.png"

namespace util 
{
	enum enemy_identifiers 
	{
		car,
		fire_truck,
		tractor,
	};

	class TextureManager
	{
		public:
			TextureManager();
			~TextureManager();

			const sf::Texture& getTexture(int enemy_id) const;

		private: // Variables
			std::vector<sf::Texture>  m_enemy_textures;
			std::vector<std::string>  m_texture_paths;

		private: // Helper functions
			void  m_initializeTextures();
	};
}
#endif // ! TEXTURE_MANAGER_H
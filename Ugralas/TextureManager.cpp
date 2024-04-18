#include "TextureManager.h"

util::TextureManager::TextureManager()
{
	// Initialize paths
	m_texture_paths = { CAR_TEXTURE_PATH, FIRE_TEXTURE_PATH, TRACTOR_TEXTURE_PATH };

	m_initializeTextures(); // Load texture from paths
	m_texture_paths.clear(); // Delete texture paths, no longer needed just extra space
}

util::TextureManager::~TextureManager()
{}


///////////////////////////////////////|
// 
//  Returns a texture at a given index
// 
//  Parameter: int
// 
//  Return: const sf::Texture&
//
///////////////////////////////////////|
const sf::Texture& util::TextureManager::getTexture(int enemy_id) const
{
	return m_enemy_textures[enemy_id];
}


///////////////////////////////////////////////|
// 
//  Initializes the textures from path vector
//  
//  Cleans up the path vector
// 
//  Should only be called once, by constructor
// 
//  Return: void
// 
///////////////////////////////////////////////|
void util::TextureManager::m_initializeTextures()
{
	// Reserve size for the textures
	m_enemy_textures.reserve(m_texture_paths.size());

	for (const auto& a : m_texture_paths) {

		// Load the texture
		sf::Texture texture;

		#if DEBUG_STATE == 0
		texture.loadFromFile(a);
		#endif

		#if DEBUG_STATE == 1
		if (!texture.loadFromFile(a)) {
			E_LOG("Couldn't load file, file name:");
			E_LOG(a);
			E_LOG("TextureManager::m_initializeTextures")
			return;
		}
		#endif

		// emplace back the texture
		m_enemy_textures.emplace_back(texture);
	}
}
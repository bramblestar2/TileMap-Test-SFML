#include "TextureHandler.h"
#include <iostream>

TextureHandler::TextureHandler()
{
}

TextureHandler::~TextureHandler()
{
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    // destructor deletes all the textures from memory
    for (auto texture : m_textures)
    {
        delete texture.second;
    }
}

TextureHandler::ErrorCode TextureHandler::loadTexture(const std::string& texture_id, const std::string& texture_path)
{
    std::lock_guard<std::mutex> lock(m_texture_mutex);
	// check if the texture is already loaded
    auto texture = m_textures.find(texture_id);
    if (texture != m_textures.end())
    {
        std::cout << texture_id << ": Texture already exists." << std::endl;
        return ErrorCode::NONE;
    }

    std::string ext = texture_path.substr(texture_path.find_last_of(".") + 1);
    if (ext != "png" && ext != "jpg" && ext != "bmp")
        return ErrorCode::INVALID_FILE_TYPE;

    // create a new texture object
    sf::Texture* texture_ptr = new sf::Texture();

    // load the texture from file
    if (!texture_ptr->loadFromFile(texture_path))
    {
        // if the texture failed to load, delete the texture object and return
        delete texture_ptr;
        std::cout << texture_id << ": Texture failed to load." << std::endl;
        return ErrorCode::FILE_LOAD_FAILED;
    }
    texture_ptr->setSmooth(true);

    // insert the texture into the unordered map
    m_textures[texture_id] = texture_ptr;

    std::cout << texture_id << ": Texture loaded successfully." << std::endl;

    return ErrorCode::NONE;
}

void TextureHandler::deleteTexture(const std::string& texture_id)
{
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    // find the texture in the unordered map
    auto texture = m_textures.find(texture_id);

    // if the texture was found
    if (texture != m_textures.end())
    {
        // delete the texture from memory
        delete texture->second;
        // remove the texture from the unordered map
        m_textures.erase(texture);
    }
}

sf::Texture* TextureHandler::getTexture(const std::string& texture_id)
{
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    // find the texture in the unordered map
    auto texture = m_textures.find(texture_id);

    // if the texture was found
    if (texture != m_textures.end())
    {
        return texture->second;
    }
    return nullptr;
}

std::vector<std::string> TextureHandler::getAllTextureIDs()
{
    std::vector<std::string> texture_ids;
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    for (auto& texture : m_textures)
    {
        texture_ids.push_back(texture.first);
    }
    return texture_ids;
}
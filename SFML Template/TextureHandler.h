#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <mutex>

class TextureHandler
{
public:
    enum class ErrorCode
    {
        NONE,
        FILE_NOT_FOUND,
        FILE_LOAD_FAILED,
        INVALID_FILE_TYPE
    };

    TextureHandler();
    ~TextureHandler();

    ErrorCode loadTexture(const std::string& texture_id, const std::string& texture_path);
    void deleteTexture(const std::string& texture_id);
    sf::Texture* getTexture(const std::string& texture_id);
    std::vector<std::string> getAllTextureIDs();

private:
    std::unordered_map<std::string, sf::Texture*> m_textures;
    std::mutex m_texture_mutex;
};



#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class AssetManager {
public:
    // Lay instance duy nhat (Singleton)
    static AssetManager& getInstance();

    // Tai texture neu chua co, sau do tra ve reference
    const sf::Texture& getTexture(const std::string& filename);

    // Tai font neu chua co, sau do tra ve reference
    const sf::Font& getFont(const std::string& filename);

private:
    AssetManager() = default; // Ham dung private
    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    std::unordered_map<std::string, sf::Texture> m_textures;
    std::unordered_map<std::string, sf::Font> m_fonts;
};


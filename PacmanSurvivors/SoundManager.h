#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <list>
#include <memory>

class SoundManager
{
public:
    static SoundManager& getInstance();

    void playSound(const std::string& filename, float pitchVariation = 0.0f);

    void playMusic(const std::string& filename);
    void stopMusic();

private:
    SoundManager();
    // Kho chứa SoundBuffer (Dữ liệu âm thanh thô)
    std::map<std::string, sf::SoundBuffer> m_buffers;

    // Danh sách các âm thanh ĐANG phát
    std::list<sf::Sound> m_sounds;
    // Nhạc nền
    std::unique_ptr<sf::Music> m_music;
};
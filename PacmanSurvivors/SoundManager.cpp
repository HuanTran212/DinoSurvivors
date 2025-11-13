#include "SoundManager.h"
#include <iostream>
#include <random>

SoundManager& SoundManager::getInstance()
{
    static SoundManager instance;
    return instance;
}

SoundManager::SoundManager()
{
    m_music = std::make_unique<sf::Music>();
}

void SoundManager::playSound(const std::string& filename, float pitchVariation)
{
    // 1. Dọn dẹp các âm thanh đã dừng
    m_sounds.remove_if([](const sf::Sound& s) {
        return s.getStatus() == sf::Sound::Status::Stopped;
        });

    // 2. Tải buffer nếu chưa có
    if (m_buffers.find(filename) == m_buffers.end())
    {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filename))
        {
            std::cerr << "!! [SoundManager] Khong the tai: " << filename << std::endl;
            return;
        }
        m_buffers[filename] = std::move(buffer);
    }

    // 3. Tạo Sound mới
    m_sounds.emplace_back(m_buffers.at(filename));

    sf::Sound& sound = m_sounds.back();

    // 4. Biến thiên độ cao (Pitch)
    if (pitchVariation > 0.0f)
    {
        float randomPitch = 1.0f + (static_cast<float>(rand()) / RAND_MAX * pitchVariation * 2.0f - pitchVariation);
        sound.setPitch(randomPitch);
    }

    sound.setVolume(50.f);
    sound.play();
}

void SoundManager::playMusic(const std::string& filename)
{
    if (!m_music->openFromFile(filename))
    {
        std::cerr << "!! [SoundManager] Khong the tai nhac: " << filename << std::endl;
        return;
    }

    m_music->setLooping(true);
    m_music->setVolume(15.f);
    m_music->play();
}

void SoundManager::stopMusic()
{
    m_music->stop();
}
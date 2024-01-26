#pragma once
#include "Sprite.hpp"
#include "Animation.hpp"

class SpriteSheet : Sprite
{
private:
    int                    m_frame = 0;
    int                    m_width;
    float                  m_latency;
    std::vector<Animation> m_animations;
    std::string            m_current_animation;
public:
    SpriteSheet(std::string path, int width_given);
    ~SpriteSheet() = default;
    void setTextureRect(const sf::IntRect rect) {m_sprite.setTextureRect( {rect.left, rect.top, rect.width, rect.height}); }
    void add_animation(std::string, std::vector<int>);
    void play_animation(std::string anim, sf::Clock& clock);
    int locate_animation(std::string ref);
};

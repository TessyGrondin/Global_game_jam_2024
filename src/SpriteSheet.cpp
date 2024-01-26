#include "../include/SpriteSheet.hpp"

SpriteSheet::SpriteSheet(std::string path, int width_given) :
Sprite(path)
{
    m_width = width_given;
}

int SpriteSheet::locate_animation(std::string anim)
{
    int limit = animations.size();

    for (int i = 0; !anim.empty() && i < limit; i++)
        if (anim == animations[i].get_name())
            return i;
    return -1;
}

bool SpriteSheet::in_range(int anim, int anima)
{
    for (int i = 0;  i < animations[anima].get_frames().size(); i++)
        if (animations[anima].get_frames()[i] == anim)
            return true;
    return false;
}

void SpriteSheet::play_animation(std::string anim, sf::Clock& clock)
{
    float timing = clock.getElapsedTime().asSeconds();
    sf::IntRect rect = m_sprite.getTextureRect();
    int anim_used = locate_animation(anim);

    if (anim_used == -1)
        return;
    if (timing - m_latency >= 0.10) {
        if ((m_frame == animations[anim_used].last() && animations[anim_used].get_loop()) || !in_range(m_frame, anim_used)) {
            m_frame = animations[anim_used].first();
            rect.left = animations[anim_used].first() * m_width;
        } else {
            rect.left += m_width;
            m_frame++;
        }
        m_sprite.setTextureRect(rect);
        m_latency = timing;
    }
}

void SpriteSheet::add_animation(std::string new_anim, std::vector<int> frames)
{
    int exist = locate_animation(new_anim);

    if (frames.empty() || new_anim.empty())
        return;
    if (animations[0].get_name() == "") {
        animations[0].set_name(new_anim);
        animations[0].set_frames(frames);
    } else if (exist != -1)
        animations[exist].set_frames(frames);
    else
        animations.push_back(Animation(new_anim, frames));
}
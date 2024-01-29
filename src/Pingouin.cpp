#include "../include/Pingouin.hpp"

Pingouin::Pingouin() :
SpriteSheet("assets/pingouin_bleu.png", 142)
{
    add_animation("walk", {2, 3});
    add_animation("stand", {1});
    add_animation("sit", {0});
    m_animations[1].set_loop(false);
    m_animations[2].set_loop(false);
    m_sprite.setOrigin({71, 89});
}

void Pingouin::animate()
{
    if (m_dead)
        return;
    if (is_cliked()) {
        m_moving = false;
        play_animation("stand");
    }
    if (m_moving) {
        move();
        play_animation("walk");
    }
}

void Pingouin::set_dir(sf::Vector2f start)
{
    float angle = atan2((800 - start.y), (870 - start.x));
    m_dir = {cos(angle), sin(angle)};
}

#include "../include/Pingouin.hpp"

Pingouin::Pingouin() :
SpriteSheet("assets/pingouin_bleu.png", 142)
{
    add_animation("walk", {2, 3});
    add_animation("stand", {1});
    add_animation("sit", {0});
    m_animations[1].set_loop(false);
    m_animations[2].set_loop(false);
}

void Pingouin::animate()
{
    if (m_dead)
        play_animation("sit");
    else if (m_moving)
        play_animation("walk");
    else
        play_animation("stand");
}

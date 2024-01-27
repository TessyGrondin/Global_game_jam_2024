#pragma once
#include "Engine.hpp"

class Pingouin
{
private:
    sf::Music                m_music;
    TextBox                  m_rule;
    Sprite                   m_background;
    std::vector<SpriteSheet> m_pinguins;
    Sprite                   m_chair;
public:
    Pingouin(/* args */);
    ~Pingouin();
};

Pingouin::Pingouin(/* args */)
{
}

Pingouin::~Pingouin()
{
}

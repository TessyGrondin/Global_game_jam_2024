#pragma once
#include "Engine.hpp"

class End
{
private:
    sf::Text  m_text;
    sf::Music m_music;
    Sprite    m_background;
    sf::Clock m_clock;
    sf::Font  m_font;
public:
    End();
    ~End() = default;
    int loop(sf::RenderWindow& win, sf::Event evt, int value);
};

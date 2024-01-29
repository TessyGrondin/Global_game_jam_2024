#pragma once
#include "Engine.hpp"

class Menu
{
private:
    Sprite    m_background;
    sf::Text  m_title;
    sf::Music m_music;
    sf::Text  m_message;
    Sound     m_sound;
    sf::Font  m_font;
public:
    Menu();
    ~Menu() = default;
    void draw(sf::RenderWindow& win);
    void loop(sf::RenderWindow& win, sf::Event evt);
};

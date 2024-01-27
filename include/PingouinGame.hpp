#pragma once
#include "Engine.hpp"
#include "Pingouin.hpp"

class PingouinGame
{
private:
    sf::Music                m_music;
    TextBox                  m_rule;
    Sprite                   m_background;
    std::vector<std::shared_ptr<Pingouin>>    m_pinguins;
    Sprite                   m_chair;
    Sprite                   m_blue_square;
    Sprite                   m_pink_square;
    sf::Clock                m_clock;
    bool                     m_defeat = false;
    int                      m_score = 0;
    sf::Font                 m_font;
    Pingouin                 m_pen;
    int                      m_local_score = 0;
public:
    PingouinGame();
    ~PingouinGame() = default;
    int loop(sf::RenderWindow& win, sf::Event evt);
    void loop_rule(sf::RenderWindow& win, sf::Event evt);
    void draw(sf::RenderWindow& win);
    void add_penguin();
    void play_defeat(sf::RenderWindow& win, bool color);
    void drag_and_drop();
    void destroy_pingouin(int index);
};

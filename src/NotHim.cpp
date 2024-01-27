/*
** EPITECH PROJECT, 2024
** Global_game_jam_2024
** File description:
** NotHim
*/

#include "NotHim.hpp"

NotHim::NotHim()
{
    for (int i = 0; i < 20; i++) {
        m_allSprite.push_back(Sprite("assets/c_moi_imposteur.png"));
        m_allSprite[i].set_position({float(rand() % 1920), float(rand() % 1080)});
    }
}

NotHim::~NotHim()
{
}

int NotHim::loop(sf::RenderWindow& win, sf::Event evt) {
    while (win.isOpen()) {
        loop_rule(win, evt);
    }
    return 0;
}

void NotHim::loop_rule(sf::RenderWindow& win, sf::Event evt)
{
    while (win.isOpen()) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        }
        win.clear();
        MoveAll();
        for (size_t i = 0; i < m_allSprite.size(); i++) {
            m_allSprite[i].draw(win);
        }
        win.display();
    }
}

void NotHim::MoveAll() {
    for (size_t i = 0; i < m_allSprite.size(); i++) {
        m_allSprite[i].move(rand() % 21 + (-10), rand() % 21 + (-10));
        // sf::Vector2f pos = m_allSprite[i].get_position();
    }
}


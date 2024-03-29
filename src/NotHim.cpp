/*
** EPITECH PROJECT, 2024
** Global_game_jam_2024
** File description:
** NotHim
*/

#include "NotHim.hpp"

NotHim::NotHim() :
    m_yay("assets/yay.wav"),
    m_huh("assets/huh.wav")
{
    m_ivrogne.openFromFile("assets/ivrogne.ogg");
    m_ivrogne.setLoop(true);
    m_ivrogne.play();
    for (int i = 0; i < 20; i++) {
        std::shared_ptr<Sprite> newimpostor = std::make_shared<Sprite>("assets/c_moi_imposteur.png");
        newimpostor->set_scale({2, 2});
        m_allSprite.push_back(newimpostor);
        m_allSprite[i]->set_position({float(rand() % 1920), float(rand() % 1080)});
        m_dir.push_back({rand() % 10 - (rand() % 10), rand() % 10 - (rand() % 10)});
    }
    std::shared_ptr<Sprite> him = std::make_shared<Sprite>("assets/c_moi.png");
    him->set_scale({2, 2});
    m_allSprite.push_back(him);
    m_allSprite.back()->set_position({float(rand() % 1920), float(rand() % 1080)});
}

NotHim::~NotHim()
{
}

int NotHim::loop(sf::RenderWindow& win, sf::Event evt) {
    while (win.isOpen() && !m_clicked) {
        loop_rule(win, evt);
    }
    return m_score;
}

void NotHim::loop_rule(sf::RenderWindow& win, sf::Event evt)
{
    while (win.isOpen() && !m_clicked) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            if (evt.type == sf::Event::MouseButtonPressed && !m_allSprite.back()->is_cliked()) {
                if (m_score > 0)
                    m_score--;
                m_huh.play();
            }
            if (m_allSprite.back()->is_cliked()) {
                m_clicked = true;
                m_yay.play();
                m_ivrogne.stop();
            }
        }
        win.clear();
        m_background.draw(win);
        MoveAll();
        for (size_t i = 0; i < m_allSprite.size(); i++) {
            m_allSprite[i]->draw(win);
        }
        win.display();
    }
}

void NotHim::MoveAll() {
    for (size_t i = 0; i < m_allSprite.size(); i++) {
        m_allSprite[i]->move(cos(m_dir[i].x) * m_speed, sin(m_dir[i].y) * m_speed);
        sf::Vector2f pos = m_allSprite[i]->get_position();
        if (pos.x < 0 || pos.x > 1920 || pos.y < 0 || pos.y > 1080) {
            m_allSprite[i]->set_position({float(rand() % 1920), float(rand() % 1080)});
        }
        if (m_clock.getElapsedTime().asMilliseconds() > 500) {
            m_dir[i] = {rand() % 50 - (rand() % 50), rand() % 50 - (rand() % 50)};
        }
    }
    if (m_clock.getElapsedTime().asMilliseconds() > 500) {
        m_clock.restart();
    }
}


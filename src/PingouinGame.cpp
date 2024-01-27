#include "../include/PingouinGame.hpp"

PingouinGame::PingouinGame()
{
    m_font.loadFromFile("assets/Super Enjoy.ttf");
    m_rule.load("C'est l'histoire des pingouin qui respiraient par les fesses.\nUn jour ils s'assoient et ils meurent.\nEmpeche les en les ramenant dans le rectangle de la bonne\ncouleur avec ta souris.", m_font, "");
    m_blue_square.set_texture("assets/bluerec.png");
    m_pink_square.set_texture("assets/pinkrec.png");
    m_chair.set_texture("assets/chaise.png");
    m_background.set_texture("assets/pingouin_background.png");
    m_rule.set_character_size(60);
    m_rule.setposition({100, 400}, {0, 0});
    m_blue_square.set_position({100, 100});
    m_pink_square.set_position({1400, 100});
    m_chair.set_position({870, 800});
    m_chair.set_scale({3, 3});
    m_music.openFromFile("assets/Penguin.ogg");
}

void PingouinGame::loop_rule(sf::RenderWindow& win, sf::Event evt)
{
    m_music.play();
    while (win.isOpen()) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            if (evt.type == sf::Event::TextEntered && evt.text.unicode == '\r')
                return;
        }
        win.clear();
        m_background.draw(win);
        m_rule.draw(win);
        win.display();
    }
}

int PingouinGame::loop(sf::RenderWindow& win, sf::Event evt)
{
    loop_rule(win, evt);
    while (win.isOpen() && !m_defeat) {
        while (win.pollEvent(evt))
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        win.clear();
        add_penguin();
        draw(win);
        win.display();
    }
    m_music.stop();
    int lim = m_pinguins.size();
    int exact = 0;
    for (int i = 0; i < lim; i++)
        if (!(*m_pinguins[i]).get_moving() && (*m_pinguins[i]).get_death())
            exact++;
    m_score = exact / 10;
    return m_score;
}

void PingouinGame::draw(sf::RenderWindow& win)
{
    int lim = m_pinguins.size();
    m_background.draw(win);
    m_blue_square.draw(win);
    m_pink_square.draw(win);
    m_chair.draw(win);
    for (int i = 0; i < lim; i++) {
        (*m_pinguins[i]).animate();
        (*m_pinguins[i]).draw(win);
    }
}

void PingouinGame::add_penguin()
{
    float timing = m_clock.getElapsedTime().asSeconds();
    if (timing < 2)
        return;
    srand(std::time(0));
    int i = rand() % 2;
    int x = rand() % 244 + 1014;
    shared_ptr<Pingouin> pinguoin = std::make_shared<Pingouin>();
    pinguoin->set_position({(float)x, 0});
    if (!i) {
        pinguoin->set_color(false);
        pinguoin->set_texture("assets/pingouin_rose.png");
    }
    m_pinguins.push_back(pinguoin);
    m_clock.restart();
}

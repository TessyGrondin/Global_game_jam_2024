#include "../include/PingouinGame.hpp"

PingouinGame::PingouinGame() :
m_yoink("assets/yoink.wav"),
m_death("assets/penguin-squeak.wav"),
m_yay("assets/yay.wav")
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
    m_music.setLoop(true);
    m_pen.set_position({870, 800});
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

void PingouinGame::play_defeat(sf::RenderWindow& win, bool color)
{
    if (!color)
        m_pen.set_texture("assets/pingouin_rose.png");
    m_pen.set_origin({0, 0});
    m_death.play();
    m_clock.restart();
    while (win.isOpen() && m_clock.getElapsedTime().asSeconds() < 2) {
        m_pen.play_animation("sit");
        win.clear();
        m_background.draw(win);
        m_chair.draw(win);
        m_pen.draw(win);
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
        drag_and_drop();
        draw(win);
        for (int i = 0; i < (int)m_pinguins.size(); i++) {
            sf::Vector2f pos = (*m_pinguins[i]).get_position();
            if (pos.x >= (800 + 32) && pos.y >= (870 + 32)) {
                play_defeat(win, (*m_pinguins[i]).get_color());
                m_defeat = true;
            }
        }
        win.display();
    }
    m_music.stop();
    m_score = m_local_score / 10;
    return m_score;
}

bool contains(Sprite square, Pingouin pin)
{
    sf::FloatRect sq = square.get_global_bound();
    sf::FloatRect pi = pin.get_global_bound();
    if (pi.intersects(sq))
        return true;
    return false;
}

void PingouinGame::destroy_pingouin(int index)
{
    if (m_pinguins.empty())
        return;
    int last = m_pinguins.size() - 1;
    if (last != 0)
        m_pinguins[index] = m_pinguins[last];
    m_pinguins.pop_back();
    m_yay.play();
    m_local_score++;
}

void PingouinGame::draw(sf::RenderWindow& win)
{
    m_background.draw(win);
    m_blue_square.draw(win);
    m_pink_square.draw(win);
    m_chair.draw(win);
    for (int i = 0; i < (int)m_pinguins.size(); i++) {
        if (contains(m_blue_square, (*m_pinguins[i])) && (*m_pinguins[i]).get_color()) {
            destroy_pingouin(i);
            break;
        }
        if (contains(m_blue_square, (*m_pinguins[i])) && !(*m_pinguins[i]).get_color()) {
            play_defeat(win, (*m_pinguins[i]).get_color());
            m_defeat = true;
        }
        if (contains(m_pink_square, (*m_pinguins[i])) && !(*m_pinguins[i]).get_color()) {
            destroy_pingouin(i);
            break;
        }
        if (contains(m_pink_square, (*m_pinguins[i])) && (*m_pinguins[i]).get_color()) {
            play_defeat(win, (*m_pinguins[i]).get_color());
            m_defeat = true;
        }
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
    int x = (rand() % 729) + 560;
    shared_ptr<Pingouin> pinguoin = std::make_shared<Pingouin>();
    pinguoin->set_position({(float)x, 0});
    pinguoin->set_dir({(float)x, 0});
    if (!i) {
        pinguoin->set_color(false);
        pinguoin->set_texture("assets/pingouin_rose.png");
    }
    m_pinguins.push_back(pinguoin);
    m_clock.restart();
}

void PingouinGame::drag_and_drop()
{
    int lim = m_pinguins.size();
    for (int i = 0; i < lim; i++) {
        if ((*m_pinguins[i]).is_cliked() && !(*m_pinguins[i]).get_death()) {
            m_yoink.play();
            (*m_pinguins[i]).set_position({(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y});
            break;
        }
    }
}

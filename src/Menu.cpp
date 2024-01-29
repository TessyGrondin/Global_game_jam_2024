#include "../include/Menu.hpp"

Menu::Menu() :
m_background("assets/menu.png"),
m_sound("assets/yay.wav")
{
    m_font.loadFromFile("assets/Super Enjoy.ttf");
    m_title.setString("Les Blagues de Tonton : le Jeu");
    m_title.setFont(m_font);
    m_title.setFillColor(sf::Color::Black);
    m_title.setOutlineThickness(1);
    m_title.setOutlineColor(sf::Color::White);
    m_title.setCharacterSize(70);
    m_title.setPosition({200, 300});
    m_music.openFromFile("assets/menu.ogg");
    m_music.setVolume(1000);
    m_music.setLoop(true);
    m_message.setPosition({200, 500});
    m_message.setString("appuyez sur entree pour commencer");
    m_message.setFont(m_font);
    m_message.setFillColor(sf::Color::Black);
    m_message.setOutlineThickness(1);
    m_message.setOutlineColor(sf::Color::White);
    m_message.setCharacterSize(70);
    m_background.set_scale({0.4, 0.3});
}

void Menu::draw(sf::RenderWindow& win)
{
    m_background.draw(win);
    win.draw(m_title);
    win.draw(m_message);
}

void Menu::loop(sf::RenderWindow& win, sf::Event evt)
{
    m_music.play();
    while (win.isOpen()) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            if (evt.type == sf::Event::TextEntered && evt.text.unicode == '\r') {
                m_sound.play();
                m_music.stop();
                return;
            }
        }
        win.clear();
        draw(win);
        win.display();
    }
}

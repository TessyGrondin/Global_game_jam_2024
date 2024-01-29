#include "../include/End.hpp"

End::End() :
m_background("assets/menu.png")
{
    m_font.loadFromFile("assets/Super Enjoy.ttf");
    m_text.setString("Ton score : ");
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::Black);
    m_text.setOutlineThickness(1);
    m_text.setOutlineColor(sf::Color::White);
    m_text.setCharacterSize(70);
    m_text.setPosition({200, 300});
    m_music.openFromFile("assets/win.ogg");
}

int End::loop(sf::RenderWindow& win, sf::Event evt, int value)
{
    std::string str = m_text.getString();
    str += std::to_string(value);
    str += "\ncompare avec tes amis !";
    m_text.setString(str);
    m_music.play();
    while (win.isOpen() && m_clock.getElapsedTime().asSeconds() < 4) {
        std::cout << "hello" << std::endl;
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            if (evt.type == sf::Event::TextEntered && evt.text.unicode == '\r') {
                m_music.stop();
                return 0;
            }
        }
        win.clear();
        m_background.draw(win);
        win.draw(m_text);
        win.display();
    }
    m_music.stop();
    return 0;
}

#include "../include/Sprite.hpp"
#include <iostream>

Sprite::Sprite()
{
}

Sprite::Sprite(std::string path)
{
    if (!m_texture.loadFromFile(path)) {
        std::cout << "file not found" << std::endl;
        exit(0);
    }
    m_sprite.setTexture(m_texture);
}

void Sprite::draw(sf::RenderWindow& win)
{
    win.draw(m_sprite);
}

void Sprite::set_texture(std::string path)
{
    m_texture.loadFromFile(path);
    m_sprite.setTexture(m_texture);
}

bool Sprite::collide(Sprite other)
{
    if (m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds()))
        return true;
    return false;
}

#pragma once
#include "Engine.hpp"

class Pingouin : public SpriteSheet
{
private:
    bool         m_color = true;
    bool         m_moving = true;
    bool         m_dead = false;
    sf::Vector2f m_dir;
public:
    Pingouin();
    ~Pingouin() = default;
    void animate();
    void set_color(bool color) {m_color = color;}
    bool get_death() {return m_dead;}
    bool get_moving() {return m_moving;}
    void move() {m_sprite.move(m_dir);}
    void set_dir(sf::Vector2f start);
    bool get_color() {return m_color;}
};

#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    int score = 0;
    win.create(sf::VideoMode(1920, 1080), "Les Blagues de Tonton : le Jeu");
    Quiz quiz;
    NotHim nothim;
    nothim.loop(win, evt);
    score += quiz.loop(win, evt);
    return 0;
}

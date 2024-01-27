#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    // int score = 0;
    win.create(sf::VideoMode(1920, 1080), "test");
    Quiz quiz;
    NotHim nothim;
    // score += quiz.loop(win, evt);
    nothim.loop(win, evt);
    return 0;
}

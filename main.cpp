#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    int score = 0;
    Quiz quiz;
    score += quiz.loop(win, evt);
    return 0;
}

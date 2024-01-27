#include "include/Game.hpp"

int main(void)
{
    int score = 0;
    win.create(sf::VideoMode(1920, 1080), "Les Blagues de Tonton : le Jeu");
    // Quiz quiz;
    PingouinGame pingouin;
    score += pingouin.loop(win, evt);
    return 0;
}

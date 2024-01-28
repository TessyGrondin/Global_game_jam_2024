#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    int score = 0;
    win.create(sf::VideoMode(1920, 1080), "Les Blagues de Tonton : le Jeu");
    Menu menu;
    // Quiz quiz;
    // NotHim nothim;
    PingouinGame pingouin;
    End end;
    menu.loop(win, evt);
    // score += quiz.loop(win, evt);
    // score += nothim.loop(win, evt);
    score += pingouin.loop(win, evt);
    score += end.loop(win, evt, score);
    return 0;
}

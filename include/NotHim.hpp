/*
** EPITECH PROJECT, 2024
** Global_game_jam_2024
** File description:
** NotHim
*/

#ifndef NOTHIM_HPP_
#define NOTHIM_HPP_
    #include "Engine.hpp"

class NotHim {
    public:
        NotHim();
        ~NotHim();
        void MoveAll();
        int loop(sf::RenderWindow& win, sf::Event evt);
        void loop_rule(sf::RenderWindow& win, sf::Event evt);
    protected:
    private:
        Sprite                              m_background = Sprite("assets/beach.png");
        sf::Clock                           m_clock;
        sf::Clock                           m_speedClock;
        std::vector<shared_ptr<Sprite>>     m_allSprite;
        std::vector<sf::Vector2i>           m_dir;
        float                               m_speed = 1;
        bool                                m_clicked = false;
};

#endif /* !NOTHIM_HPP_ */

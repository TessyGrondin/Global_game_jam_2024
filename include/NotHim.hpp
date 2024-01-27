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
        std::vector<Sprite>     m_allSprite;
};

#endif /* !NOTHIM_HPP_ */

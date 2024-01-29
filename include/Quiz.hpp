#pragma once
#include "Engine.hpp"

class Quiz
{
private:
    std::vector<std::string> m_reference;
    TextBox                  m_question_box;
    TextBox                  m_enter;
    TextBox                  m_answer_box;
    TextBox                  m_rule;
    std::string              m_answer;
    int                      m_score = 0;
    int                      m_local_score = 5;
    sf::Font                 m_font;
    Sprite                   m_background;
    int                      m_turn = 0;
    sf::Music                m_music;
    Sound                    m_right;
    Sound                    m_wrong;
public:
    Quiz();
    ~Quiz() = default;
    void load_ref();
    void load();
    void translate_answer();
    void draw(sf::RenderWindow& win);
    bool valid_format();
    bool check_entry();
    void catch_input(sf::RenderWindow& win, sf::Event evt);
    void reload();
    int loop(sf::RenderWindow& win, sf::Event evt);
    void loop_rule(sf::RenderWindow& win, sf::Event evt);
};

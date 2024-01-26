#include "../include/Quiz.hpp"

Quiz::Quiz()
{
    m_font.loadFromFile("assets/Super Enjoy.ttf");
    m_answer_box.load("", m_font, "");
    m_enter.load("", m_font, "assets/base_rectangle.png");
    m_question_box.load("", m_font, "");
    m_background.set_texture("assets/quiz_background.png");
    m_rule.load("Le Quiz des blagues de Tonton :\nreponds aux question posee avec des lettres sans accent\nle format de la reponse sera a l'ecran.", m_font, "");
    load_ref();
    load();
}

void Quiz::load_ref()
{
    std::fstream source_file;
    std::string line;
    source_file.open("../config/joke.txt");
    if (source_file.is_open()) {
        while (source_file.good()) {
            std::getline(source_file, line);
            m_reference.push_back(line);
        }
    }
    source_file.close();
}

void Quiz::load()
{
    srand(std::time(0));
    std::string question;
    std::string line = m_reference[rand() % m_reference.size()];
    int i = line.find(';');
    question = line.substr(0, i);
    m_question_box.set_string(question);
    m_answer = line.substr(i + 1);
    translate_answer();
}

bool letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

void Quiz::translate_answer()
{
    std::string str = "";
    for (int i = 0; m_answer[i]; i++) {
        if (letter(m_answer[i]))
            str.append("*");
        else
            str += m_answer[i];
    }
    m_answer_box.set_string(str);
}

void Quiz::draw(sf::RenderWindow& win)
{
    m_background.draw(win);
    m_answer_box.draw(win);
    m_enter.draw(win);
    m_question_box.draw(win);
}

bool Quiz::valid_format()
{
    std::string ref = m_answer_box.get_string();
    std::string entry = m_enter.get_string();
    if (entry.size() != m_answer.size())
        return false;
    for (int i = 0; !entry.empty() && entry[i]; i++) {
        if (ref[i] == '*' && !letter(entry[i]))
            return false;
        if (ref[i] != '*' && entry[i] != ref[i])
            return false;
    }
    return true;
}

bool Quiz::check_entry()
{
    std::string ref = m_answer_box.get_string();
    std::string entry = m_enter.get_string();
    if (!valid_format())
        return false;
    for (int i = 0; entry[i]; i++) {
        if (entry[i] != m_answer[i]) {
            m_local_score--;
            m_enter.set_string("");
            return false;
        }
    }
    m_score++;
    m_enter.set_string("");
    return true;
}

void Quiz::reload()
{
    int limit = m_reference.size();
    for (int i = 0; i < limit; i++) {
        if (m_reference[i] == m_answer) {
            m_reference[i] = m_reference[m_reference.size() - 1];
            m_reference.pop_back();
            break;
        }
    }
    m_turn++;
    load();
}

void Quiz::catch_input(sf::RenderWindow& win, sf::Event evt)
{
    std::string str = m_enter.get_string();
    while (win.pollEvent(evt)) {
        if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            win.close();
        if (evt.type == sf::Event::TextEntered) {
            if (evt.text.unicode == '\b' && !str.empty()) {
                str.pop_back();
                m_enter.set_string(str);
            }
            else if (str.size() < 42){
                str.append(1, evt.text.unicode);
                m_enter.set_string(str);
            }
            if (evt.text.unicode == '\r') {
                if (check_entry() || m_local_score <= 0)
                    reload();
            }
        }
    }
}

void Quiz::loop_rule(sf::RenderWindow& win, sf::Event evt)
{
    while (win.isOpen()) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            if (evt.type == sf::Event::TextEntered && evt.text.unicode == '\r')
                return;
        }
        m_background.draw(win);
        m_rule.draw(win);
    }
}

int Quiz::loop(sf::RenderWindow& win, sf::Event evt)
{
    loop_rule(win, evt);
    while (win.isOpen() && m_turn < 5) {
        catch_input(win, evt);
        draw(win);
    }
    return m_score;
}

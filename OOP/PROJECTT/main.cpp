#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Headers/mines.h"
using namespace std;
int option_selector_start_screen(int x, int y)
{
    if (x >= 496 && x <= 950 && y >= 362 && y <= 424)
    {
        return 1;
    }
    if (x >= 520 && x <= 936 && y >= 492 && y <= 560)
    {
        return 2;
    }
    return 0;
}
int option_selector_option_screen(int x, int y)
{
    if (x >= 620 && x <= 796 && y >= 312 && y <= 376)
    {
        return 1;
    }
    if (x >= 556 && x <= 874 && y >= 444 && y <= 510)
    {
        return 2;
    }
    if (x >= 614 && x <= 814 && y >= 570 && y <= 636)
    {
        return 3;
    }
    if (x >= 522 && x <= 894 && y >= 700 && y <= 766)
    {
        return 4;
    }
    return 0;
}
int main()
{
    Mines *a[3];
    sf::RenderWindow window(sf::VideoMode(1440, 858), "MINESWEEPER", sf::Style::Close | sf::Style::Resize);
    sf::Texture background_texture;
    background_texture.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/image/background.jpg");
    sf::Sprite background;
    background.setTexture(background_texture);
    sf::Font font;
    font.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/metallord.ttf");
    sf::Font options;
    options.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#2/OOP/PROJECTT/Fonts/HatCheck.ttf");
    while (window.isOpen())
    {
        sf::Event event;
        sf::Text Title("MINESWEEPER", font, 150);
        sf::Text Start_Game("Start Game", options, 70);
        sf::Text Exit_Game("Exit Game", options, 70);
        Title.setPosition(290, 50);
        Title.setColor(sf::Color(71, 74, 67, 255));
        Start_Game.setPosition(499, 350);
        Start_Game.setColor(sf::Color::White);
        Exit_Game.setPosition(522, 480);
        Exit_Game.setColor(sf::Color::White);
        while (window.pollEvent(event))
        {
            window.clear();
            window.draw(background);
            window.draw(Title);
            window.draw(Start_Game);
            window.draw(Exit_Game);
            window.display();
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mouse1_position = sf::Mouse::getPosition(window);
                if (option_selector_start_screen(mouse1_position.x, mouse1_position.y) == 1)
                {
                    {
                        window.close();
                        sf::RenderWindow option_window(sf::VideoMode(1440, 858), "SELECT OPTION", sf::Style::Close | sf::Style::Resize);
                        while (option_window.isOpen())
                        {
                            sf::Event event2;
                            sf::Text Title2("Select Difficulty", font, 150);
                            sf::Text option1("EASY", options, 70);
                            sf::Text option2("MEDIUM", options, 70);
                            sf::Text option3("HARD", options, 70);
                            sf::Text option4("EXIT GAME", options, 70);
                            Title2.setPosition(150, 50);
                            Title2.setColor(sf::Color(71, 74, 67, 255));
                            option1.setPosition(622, 300);
                            option2.setPosition(570, 430);
                            option3.setPosition(622, 560);
                            option4.setPosition(525, 690);
                            while (option_window.pollEvent(event2))
                            {
                                option_window.clear();
                                option_window.draw(background);
                                option_window.draw(Title2);
                                option_window.draw(option1);
                                option_window.draw(option2);
                                option_window.draw(option3);
                                option_window.draw(option4);
                                option_window.display();
                                if (event2.type == sf::Event::Closed)
                                {
                                    option_window.close();
                                    break;
                                }
                                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                                {
                                    sf::Vector2i mouse_position = sf::Mouse::getPosition(option_window);
                                    if (option_selector_option_screen(mouse_position.x, mouse_position.y) == 1)
                                    {
                                        option_window.close();
                                        a[0] = new easy_Mines();
                                    }
                                    if (option_selector_option_screen(mouse_position.x, mouse_position.y) == 2)
                                    {
                                        option_window.close();
                                        a[1] = new medium_Mines();
                                    }
                                    if (option_selector_option_screen(mouse_position.x, mouse_position.y) == 3)
                                    {
                                        option_window.close();
                                        a[2] = new hard_Mines();
                                    }
                                    if (option_selector_option_screen(mouse_position.x, mouse_position.y) == 4)
                                    {
                                        option_window.close();
                                    }
                                }
                            }
                        }
                    }
                }
                if (option_selector_start_screen(mouse1_position.x, mouse1_position.y) == 2)
                {
                    window.close();
                }
            }
        }
    }
}

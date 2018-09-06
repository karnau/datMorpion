//
// Created by armandmgt on 9/6/18.
//

#include <iostream>
#include "MyWindow.h"

MyWindow::MyWindow(unsigned int w, unsigned int h) : sf::RenderWindow(sf::VideoMode{w, h, 32}, "Dat Morpion", sf::Style::Close) {
    setFramerateLimit(60);
}

void MyWindow::run() {
    Player turn{Player::CIRCLE};
    while (isOpen()) {
        sf::Event evt{};
        while (pollEvent(evt)) {
            switch (evt.type) {
                case sf::Event::EventType::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        close();
                    break;
                case sf::Event::EventType::MouseButtonPressed:
                    handleClick(turn);
                default:
                    break;
            }
        }
        drawBoard();
        drawCircles();
        drawCrosses();
        display();
    }
}

void MyWindow::handleClick(Player &turn) {
    auto mousePos = sf::Mouse::getPosition(*this);
    std::cout << mousePos.x << " " << mousePos.y << std::endl;
    if (cells[mousePos.x / cellLength][mousePos.y / cellLength] != Player::NONE)
        return;
    cells[mousePos.x / cellLength][mousePos.y / cellLength] = turn;
    turn = turn == Player::CIRCLE ? Player::CROSS : Player::CIRCLE;
}

void MyWindow::drawBoard() {
    sf::RectangleShape vertLine{{2, 800}};
    sf::RectangleShape horLine{{800, 2}};
    vertLine.setFillColor(sf::Color::White);
    horLine.setFillColor(sf::Color::White);

    for (auto i = 1; i < 3; i++) {
        for (auto j = 1; j < 3; j++) {
            vertLine.setPosition({i * 800.f / 3.f, 0});
            horLine.setPosition({0, j * 800.f / 3.f});
            draw(vertLine);
            draw(horLine);
        }
    }
}

void MyWindow::drawCircles() {
    constexpr auto radius = cellLength / 2.f - 40;
    sf::CircleShape circle{radius};
    circle.setOrigin({radius, radius});
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(10);

    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            if (cells[i][j] != Player::CIRCLE)
                continue;
            circle.setPosition({i * cellLength + cellLength / 2, j * cellLength + cellLength / 2});
            draw(circle);
        }
    }
}

void MyWindow::drawCrosses() {
    constexpr auto barLength = cellLength - 40;
    sf::RectangleShape bar{{10, barLength}};
    bar.setFillColor(sf::Color::White);
    bar.setOrigin(5, barLength / 2.f);

    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            if (cells[i][j] != Player::CROSS)
                continue;
            bar.setPosition({i * cellLength + cellLength / 2, j * cellLength + cellLength / 2});
            bar.setRotation(45);
            draw(bar);
            bar.setRotation(-45);
            draw(bar);
        }
    }
}

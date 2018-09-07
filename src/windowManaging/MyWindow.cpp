//
// Created by armandmgt on 9/6/18.
//

#include <iostream>
#include "MyWindow.hpp"

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
        drawContent();
        display();
    }
}

void MyWindow::handleClick(Player &turn) {
    auto mousePos = sf::Mouse::getPosition(*this);
    std::cout << mousePos.x << " " << mousePos.y << std::endl;
    if (gb.at(mousePos.x / cellLength, mousePos.y / cellLength).setCell(turn))
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

void MyWindow::drawCircle(const unsigned int x, const unsigned int y)
{
    constexpr auto radius = cellLength / 2.f - 40;
    sf::CircleShape circle{radius};
    circle.setOrigin({radius, radius});
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(10);

    circle.setPosition({x * cellLength + cellLength / 2, y * cellLength + cellLength / 2});
    draw(circle);
}

void MyWindow::drawCross(const unsigned int x, const unsigned int y)
{
    constexpr auto barLength = cellLength - 40;
    sf::RectangleShape bar{{10, barLength}};
    bar.setFillColor(sf::Color::White);
    bar.setOrigin(5, barLength / 2.f);

    bar.setPosition({x * cellLength + cellLength / 2, y * cellLength + cellLength / 2});
    bar.setRotation(45);
    draw(bar);
    bar.setRotation(-45);
    draw(bar);
}

void MyWindow::drawContent()
{
        drawBoard();
	std::for_each(gb.begin(), gb.end(), [this](const Cell &cell) {
		if (cell.getCell() == Player::CIRCLE)
			drawCircle(cell.x, cell.y);
		else if (cell.getCell() == Player::CROSS)
			drawCross(cell.x, cell.y);
	});
}

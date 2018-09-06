//
// Created by armandmgt on 9/6/18.
//

#ifndef DATMORPION_MYWINDOW_H
#define DATMORPION_MYWINDOW_H

#include <SFML/Graphics.hpp>

enum class Player {
    NONE, CIRCLE, CROSS
};

class MyWindow : public sf::RenderWindow {
public:
    MyWindow(unsigned int i, unsigned int i1);

    void run();

    void handleClick(Player &turn);

    void drawBoard();

    void drawCircles();

    void drawCrosses();

private:
    std::array<std::array<Player, 3>, 3> cells{};
    static constexpr auto cellLength = 800.f / 3.f;
};


#endif //DATMORPION_MYWINDOW_H

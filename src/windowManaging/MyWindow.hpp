//
// Created by armandmgt on 9/6/18.
//

#ifndef DATMORPION_MYWINDOW_H
#define DATMORPION_MYWINDOW_H

#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"

class MyWindow : public sf::RenderWindow {
public:
	MyWindow(unsigned int i, unsigned int i1);

	void run();
	void handleClick(Player &turn);

	void drawBoard();
	void drawCircle(const unsigned int i, const unsigned int i1);
	void drawCross(const unsigned int i, const unsigned int i1);

private:
	GameBoard gb;
	static constexpr auto cellLength = 800.f / 3.f;

	void drawContent();
};


#endif //DATMORPION_MYWINDOW_H

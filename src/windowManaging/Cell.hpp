//
// Created by armandmgt on 9/6/18.
//

#ifndef DATMORPION_CELLS_HPP
#define DATMORPION_CELLS_HPP

#include "PlayerEnum.hpp"

class Cell {
public:
	Cell();

	const unsigned int x;
	const unsigned int y;

	Player getCell() const;
	bool setCell(Player p);

private:
	static unsigned int index;
	Player p{Player::NONE};
};

#endif //DATMORPION_CELLS_HPP

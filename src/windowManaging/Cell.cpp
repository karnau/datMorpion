//
// Created by armandmgt on 9/6/18.
//

#include "Cell.hpp"

unsigned int Cell::index = 0;

Cell::Cell() : x(index % 3), y(index / 3) {
	index++;
}

bool Cell::setCell(Player val) {
	if (p != Player::NONE)
		return false;
	p = val;
	return true;
}

Player Cell::getCell() const {
	return p;
}

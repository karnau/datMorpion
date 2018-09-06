//
// Created by armandmgt on 9/6/18.
//

#include <algorithm>
#include "GameBoard.hpp"

GameBoard::GameBoard() noexcept {
}

std::array<Cell, 9>::const_iterator GameBoard::begin() const {
	return cells.begin();
}

std::array<Cell, 9>::const_iterator GameBoard::end() const {
	return cells.end();
}

std::array<Cell, 9>::iterator GameBoard::begin() {
	return cells.begin();
}

std::array<Cell, 9>::iterator GameBoard::end() {
	return cells.end();
}

Cell &GameBoard::at(float x, float y)
{
	return cells.at(static_cast<unsigned long>(x + y * 3));
}

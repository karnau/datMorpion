//
// Created by armandmgt on 9/6/18.
//

#ifndef DATMORPION_GAMEBOARD_HPP
#define DATMORPION_GAMEBOARD_HPP

#include <array>
#include <iterator>
#include "Cell.hpp"

class GameBoard {
public:
	GameBoard() noexcept;

	std::array<Cell, 9>::const_iterator begin() const;
	std::array<Cell, 9>::const_iterator end() const;

	std::array<Cell, 9>::iterator begin();
	std::array<Cell, 9>::iterator end();

	Cell &at(float x, float y);

private:
	std::array<Cell, 9> cells{};
};

#endif //DATMORPION_GAMEBOARD_HPP

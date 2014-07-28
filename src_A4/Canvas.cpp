
/*
 * Canvas.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Canvas.h"
#include <vector>
#include <iostream>

/**
 * Constructor taking the width and height of the canvas
 * @param col, number of columns of the canvas
 * @param row, number of rows of the canvas
 */
Canvas::Canvas(int col, int row) {

	std::vector<char> cols(col, ' ');
	grid.resize( row, cols);
//	std::cout << col << ":" << row << std::endl;

}

/**
 * Clears the canvas replacing anything on the canvas by the given character
 * @param cc, the char to replace anything on the canvas.
 */
void Canvas::clear(char cc) {

	for (auto& row : this->grid) {
		for (auto& col : row) {
			col = cc;
		}
	}
}

/**
 * Accessor for the height of the canvas
 * @return the number of rows on the canvas
 */
int Canvas::geth() const {
	return grid.size();
}

/**
 * Accessor for the width of the canvas
 * @return the number of columns on the canvas
 */
int Canvas::getw() const {
	if (grid.size() > 0)
		return grid.at(0).size();
	return 0;
}

/**
 * Place a char at a column and row location on the canvas
 * @param c, column where the char will be placed
 * @param r, row where the char will be placed
 * @param ch, the character that will be placed on the canvas
 */
void Canvas::put(int c, int r, char ch) {
	if (r < geth() && c < getw())
		grid.at(r).at(c) = ch;
}

/**
 * Return a char at a column and row location on the canvas
 * @param c, column where the char will be taken
 * @param r, row where the char will be taken
 * @return, the character that will be returned on the canvas
 */
char Canvas::get(int c, int r) const {
	return grid.at(r).at(c);
}

/**
 * decorate the canvas, this is overriden in derivatives
 */
void Canvas::decorate() {
}

/**
 * Extractor that outputs the canvas to the output stream
 * @return the output stream
 */
std::ostream& operator <<(std::ostream& out, Canvas& c) {

	for (auto row : c.grid) {
		for (auto col : row) {
			std::cout << col;
		}
		std::cout << std::endl;
	}
	return out;
}


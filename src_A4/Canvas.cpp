
/*
 * Canvas.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Canvas.h"
#include <vector>
#include <iostream>


Canvas::Canvas(int col, int row) {

	std::vector<char> cols(col, ' ');
	grid.resize( row, cols);
//	std::cout << col << ":" << row << std::endl;

}

void Canvas::clear(char cc) {

	for (auto& row : this->grid) {
		for (auto& col : row) {
			col = cc;
		}
	}
}

int Canvas::geth() const {
	return grid.size();
}

int Canvas::getw() const {
	if (grid.size() > 0)
		return grid.at(0).size();
	return 0;
}

void Canvas::put(int c, int r, char ch) {
	if (r < geth() && c < getw())
		grid.at(r).at(c) = ch;
}

char Canvas::get(int c, int r) const {
	return grid.at(r).at(c);
}

void Canvas::decorate() {
}

std::ostream& operator <<(std::ostream& out, Canvas& c) {

	for (auto row : c.grid) {
		for (auto col : row) {
			std::cout << col;
		}
		std::cout << std::endl;
	}
	return out;
}

//int main() {
//	Canvas c(5, 10);
//	c.clear('-');
//	std::cout << c << std::endl;
//	c.put(0, 0, '*');
//	c.put(4, 9, c.get(0, 0));
//	std::cout << c << std::endl;
//
//
//	return 0;
//}

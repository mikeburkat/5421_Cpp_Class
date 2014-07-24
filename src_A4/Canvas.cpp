
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

	std::vector<char> rows(row, ' ');
	grid.resize( col, rows);

}

void Canvas::clear(char cc) {

	for (auto& row : this->grid) {
		for (auto& col : row) {
			col = cc;
		}
	}
}

int Canvas::geth() const {
	if (grid.size() > 0)
		return grid.at(0).size();
	return 0;
}

int Canvas::getw() const {
	return grid.size();
}

char Canvas::put(int c, int r, char ch) {
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

int main() {
	Canvas c(2, 2);
	std::cout << c << std::endl;
	c.clear('-');
	std::cout << c << std::endl;



	return 0;
}

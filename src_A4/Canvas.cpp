
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
	grid = std::vector,.
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


}

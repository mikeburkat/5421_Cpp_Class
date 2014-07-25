/*
 * BorderedCanvas.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "BorderedCanvas.h"

BorderedCanvas::BorderedCanvas(int col, int row) : Canvas(col + 2, row + 2){
//	std::cout << col << ":" << row << std::endl;
	decorate();
}

void BorderedCanvas::clear(char ch) {
	for (int r = 0; r < geth() - 2; r++){
		for (int c = 0; c < getw() - 2; c++) {
			put(c, r, ch);
		}
	}
}

void BorderedCanvas::put(int c, int r, char ch) {
	c++;
	r++;
//	std::cout << "put: " << c << ":" << r << " h: " << geth() - 1 << " w: " << getw() -1 << std::endl;
	if (c >= 1 && c <= getw() - 2 && r >= 1 && r <= geth() - 2) {
		Canvas::put(c, r, ch);
	}
}

char BorderedCanvas::get(int c, int r) const {
	c++;
	r++;
//	std::cout << "get: " << c << ":" << r << std::endl;
	if (c >= 1 && c <= getw() - 2 && r >= 1 && r <= geth() - 2) {
		return Canvas::get(c, r);
	}
	return ' ';
}

void BorderedCanvas::decorate() {
	// add corners
	Canvas::put(0, 0, '+');
	Canvas::put(getw() - 1, 0, '+');
	Canvas::put(0, geth() - 1, '+');
	Canvas::put(getw() - 1, geth() - 1, '+');

	// fill top border
	for (int c = 1, r = 0; c < getw() - 1; c++) {
		Canvas::put(c, r, '-');
	}

	// fill bottom border
	for (int c = 1, r = geth() - 1; c < getw() - 1; c++) {
		Canvas::put(c, r, '-');
	}

	// fill left border
	for (int c = 0, r = 1; r < geth() - 1; r++) {
		Canvas::put(c, r, '|');
	}

	// fill right border
	for (int c = getw() - 1, r = 1; r < geth() - 1; r++) {
		Canvas::put(c, r, '|');
	}
}



//int main() {
//	BorderedCanvas c(10, 20);
//	c.clear('-');
//	std::cout << c << std::endl;
//	c.put(0, 0, '*');
//	c.put( 4, 9, c.get(0, 0) );
//	std::cout << c << std::endl;
//
//
//	return 0;
//}



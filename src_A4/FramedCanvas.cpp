/*
 * FramedCanvas.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "FramedCanvas.h"

FramedCanvas::FramedCanvas(int col, int row, std::string title) : title(title), Canvas(col + 2, row + 4){
	decorate();
}

void FramedCanvas::clear(char ch) {
	for (int r = 0; r < geth() - 4; r++){
		for (int c = 0; c < getw() - 2; c++) {
			put(c, r, ch);
		}
	}
}

void FramedCanvas::put(int c, int r, char ch) {
//	std::cout << " f Canvas ";
	c++;
	r += 3;
//	std::cout << "put: " << c << ":" << r << " h: " << geth() - 1 << " w: " << getw() -1 << std::endl;
	if (c >= 1 && c <= getw() - 2 && r >= 3 && r < geth() - 1) {
		Canvas::put(c, r, ch);
	}
}

char FramedCanvas::get(int c, int r) const {
	c++;
	r += 3;
//	std::cout << "get: " << c << ":" << r << std::endl;
	if (c >= 1 && c <= getw() - 2 && r >= 3 && r < geth() - 1) {
		return Canvas::get(c, r);
	}
	return ' ';
}

void FramedCanvas::decorate() {
	// add corners
	Canvas::put(0, 0, '+');
	Canvas::put(getw() - 1, 0, '+');
	Canvas::put(0, geth() - 1, '+');
	Canvas::put(getw() - 1, geth() - 1, '+');

	// fill top border
	for (int c = 1, r = 0; c < getw() - 1; c++) {
		Canvas::put(c, r, '-');
	}

	// fill title area
	for (int c = 1, r = 1; c < getw() - 1 && c <= title.length(); c++) {
		Canvas::put(c, r, title[c-1] );
	}

	// fill middle border
	for (int c = 1, r = 2; c < getw() - 1; c++) {
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
//	FramedCanvas c(10, 20, "A Framed Canvas");
//	c.clear('0');
//	std::cout << c << std::endl;
//	c.put(0, 0, '*');
//	c.put( 4, 9, c.get(0, 0) );
//	std::cout << c << std::endl;
//
//	return 0;
//}



/*
 * BorderedCanvas.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "BorderedCanvas.h"

/**
 * Constructor taking the width and height of the canvas
 * it adds the required space to contain the boarders
 * @param col, number of columns of the canvas
 * @param row, number of rows of the canvas
 */
BorderedCanvas::BorderedCanvas(int col, int row) : Canvas(col + 2, row + 2){
	decorate();
}

/**
 * Clears the canvas replacing anything on the canvas by the given character
 * it takes into account the boarders
 * @param cc, the char to replace anything on the canvas.
 */
void BorderedCanvas::clear(char ch) {
	for (int r = 0; r < geth() - 2; r++){
		for (int c = 0; c < getw() - 2; c++) {
			put(c, r, ch);
		}
	}
}

/**
 * Place a char at a column and row location on the canvas
 * it takes into account the boarders.
 * @param c, column where the char will be placed
 * @param r, row where the char will be placed
 * @param ch, the character that will be placed on the canvas
 */
void BorderedCanvas::put(int c, int r, char ch) {
	c++;
	r++;
	if (c >= 1 && c <= getw() - 2 && r >= 1 && r < geth() - 1) {
		Canvas::put(c, r, ch);
	}
}

/**
 * Return a char at a column and row location on the canvas
 * it takes into account the boarders.
 * @param c, column where the char will be taken
 * @param r, row where the char will be taken
 * @return, the character that will be returned on the canvas
 */
char BorderedCanvas::get(int c, int r) const {
	c++;
	r++;
	if (c >= 1 && c <= getw() - 2 && r >= 1 && r < geth() - 1) {
		return Canvas::get(c, r);
	}
	return ' ';
}

/**
 * decorate the canvas, with boarders.
 */
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




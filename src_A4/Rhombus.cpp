/*
 * Rhombus.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Rhombus.h"
#include "Canvas.h"
#include "Shape.h"
#include <cmath>

/**
 * Constructor for the Rhombus
 * @param h, is the height of the rhombus
 * @param description, is the description of the rhombus
 */
Rhombus::Rhombus(int h, std::string description) : Shape("Rhombus", description) {
	setD(h);
}

/**
 * Accessor for the diagonal of the shape
 * @return the heigh of the shape.
 */
int Rhombus::getD() const {
	return this->d;
}

/**
 * Mutator for the diagonal of the shape
 * @param h, the new diagonal of the shape
 */
void Rhombus::setD(int d) {
	if ( d%2 == 0 ) {
		d++;
	}
	this->d = d;
}

/**
 * Scaling funtion to increase of decrease the size of the shape
 * it will scale only if the resulting shape hight is larger than zero
 * @param n, the scaling factor
 */
void Rhombus::scale(int n) {
	if (getD() + n > 0) {
		setD(getD() + n * 2);
	}
}

/**
 * Computes the geometrical area of the shape.
 * @return the geometrical area of the shape.
 */
double Rhombus::geoArea() const {
	return (getD() * getD()) / 2.0;
}

/**
 * Computes the geometrical perimeter of the shape.
 * @return the geometrical perimeter of the shape.
 */
double Rhombus::geoPerimeter() const {
	return std::sqrt(2) * 2.0 * getD();
}

/**
 * Computes the screen area of the shape.
 * @return the screen area of the shape.
 */
int Rhombus::scrArea() const {
	int n = getD() / 2;
	return 2 * n * (n + 1) + 1;
}

/**
 * Computes the screen perimeter of the shape.
 * @return the screen perimeter of the shape.
 */
int Rhombus::scrPerimeter() const {
	return 2 * (getD() - 1);
}

/**
 * Computes the horizontal extent of the shape.
 * @return the horizontal extent of the shape.
 */
int Rhombus::hExtent() const {
	return getD();
}

/**
 * Computes the vertical extent of the shape.
 * @return the vertical extent of the shape.
 */
int Rhombus::vExtent() const {
	return getD();
}

/**
 * Draws the shape to a defined location on the canvas using a certain specified character.
 * @param c, the column location where the shape will be drawn
 * @param r, the row location where the shape will be drawn
 * @param canvas, the canvas on which the shape will be drawn
 * @param ch, the character used to draw the shape
 */
void Rhombus::draw(int c, int r, Canvas& canvas, char ch) const {
	for (int i = 0; i < getD() ; i++) {
		int stars = 0;

		if (i < (getD() / 2) ) stars = i * 2 + 1;
		else if (i == getD() / 2) stars = getD();
		else stars = ( getD() - (i + 1) ) * 2 + 1;

		int start = (getD() / 2) - (stars / 2);

		for (int j = start; j < stars + start; j++) {
			canvas.put(c+j, r+i, ch);
		}
	}
}


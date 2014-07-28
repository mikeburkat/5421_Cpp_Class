/*
 * RightIsosceles.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include <cmath>
#include "RightIsosceles.h"
#include "Canvas.h"
#include "Shape.h"

/**
 * Constructor for the Right isosceles
 * @param h, is the height of the righ isosceles
 * @param description, is the description of the right isosceles
 */
RightIsosceles::RightIsosceles(int h, std::string description) : Shape("Right Isosceles", description), h(h) {
}

/**
 * Accessor for the height of the right isosceles
 * @return the heigh of the right isosceles.
 */
int RightIsosceles::getH() const {
	return this->h;
}

/**
 * Mutator for the height of the shape
 * @param h, the new heigh of the shape
 */
void RightIsosceles::setH(int h) {
	this->h = h;
}

/**
 * Scaling funtion to increase of decrease the size of the shape
 * it will scale only if the resulting shape hight is larger than zero
 * @param n, the scaling factor
 */
void RightIsosceles::scale(int n) {
	if (getH() + n > 0) {
		setH(getH() + n);
	}
}

/**
 * Computes the geometrical area of the shape.
 * @return the geometrical area of the shape.
 */
double RightIsosceles::geoArea() const {
	return getH() * getH() / 2.0;
}

/**
 * Computes the geometrical perimeter of the shape.
 * @return the geometrical perimeter of the shape.
 */
double RightIsosceles::geoPerimeter() const {
	return ( 2.0 + std::sqrt(2) ) * getH();
}

/**
 * Computes the screen area of the shape.
 * @return the screen area of the shape.
 */
int RightIsosceles::scrArea() const {
	return getH() * (getH() + 1) / 2;
}

/**
 * Computes the screen perimeter of the shape.
 * @return the screen perimeter of the shape.
 */
int RightIsosceles::scrPerimeter() const {
	return 3 * (getH() - 1);
}

/**
 * Computes the horizontal extent of the shape.
 * @return the horizontal extent of the shape.
 */
int RightIsosceles::hExtent() const {
	return getH();
}

/**
 * Computes the vertical extent of the shape.
 * @return the vertical extent of the shape.
 */
int RightIsosceles::vExtent() const {
	return getH();
}

/**
 * Draws the shape to a defined location on the canvas using a certain specified character.
 * @param c, the column location where the shape will be drawn
 * @param r, the row location where the shape will be drawn
 * @param canvas, the canvas on which the shape will be drawn
 * @param ch, the character used to draw the shape
 */
void RightIsosceles::draw(int c, int r, Canvas& canvas, char ch) const {
	for (int i = 0; i < getH(); i++) {
		for (int j = 0; j < getH() && j <= i; j++) {
//			std::cout << getH() << ", " << c+i << ":" << c+j << std::endl;
			canvas.put(c+j, r+i, ch);
		}
	}
}





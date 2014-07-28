/*
 * Isosceles.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include <cmath>
#include "Isosceles.h"
#include "Canvas.h"
#include "Shape.h"

/**
 * Constructor for the Isosceles
 * @param h, is the height of the isosceles
 * @param description, is the description of the isosceles
 */
Isosceles::Isosceles(int h, std::string description) : Shape("Isosceles", description), h(h) {
}

/**
 * Accessor for the height of the shape.
 * @return the heigh of the shape.
 */
int Isosceles::getH() const {
	return this->h;
}

/**
 * Mutator for the height of the shape
 * @param h, the new heigh of the shape
 */
void Isosceles::setH(int h) {
	this->h = h;
}

/**
 * Accessor for the base of the shape.
 * @return the base of the shape.
 */
int Isosceles::getB() const{
	return getH() * 2 - 1;
}

/**
 * Scaling funtion to increase of decrease the size of the shape
 * it will scale only if the resulting shape hight is larger than zero
 * @param n, the scaling factor
 */
void Isosceles::scale(int n) {
	if (getH() + n > 0) {
		setH(getH() + n);
	}
}

/**
 * Computes the geometrical area of the shape.
 * @return the geometrical area of the shape.
 */
double Isosceles::geoArea() const {
	return getB() * getH() / 2.0;
}

/**
 * Computes the geometrical perimeter of the shape.
 * @return the geometrical perimeter of the shape.
 */
double Isosceles::geoPerimeter() const {
	return getB() + 2.0 * std::sqrt( 0.25 * getB() * getB() + getH() * getH() );
}

/**
 * Computes the screen area of the shape.
 * @return the screen area of the shape.
 */
int Isosceles::scrArea() const {
	return getH() * getH();
}

/**
 * Computes the screen perimeter of the shape.
 * @return the screen perimeter of the shape.
 */
int Isosceles::scrPerimeter() const {
	return 4 * ( getH() - 1 );
}

/**
 * Computes the horizontal extent of the shape.
 * @return the horizontal extent of the shape.
 */
int Isosceles::hExtent() const {
	return getB();
}

/**
 * Computes the vertical extent of the shape.
 * @return the vertical extent of the shape.
 */
int Isosceles::vExtent() const {
	return getH();
}

/**
 * Draws the shape to a defined location on the canvas using a certain specified character.
 * @param c, the column location where the shape will be drawn
 * @param r, the row location where the shape will be drawn
 * @param canvas, the canvas on which the shape will be drawn
 * @param ch, the character used to draw the shape
 */
void Isosceles::draw(int c, int r, Canvas& canvas, char ch) const {
	for (int i = getH()-1, start = 0; i >= 0; i--, start++) {

		int stars =  (i+1) * 2 - 1 ;
		for (int j = start; j < start + stars; j++) {
			canvas.put(c+j, r+i, ch);
		}
	}
}






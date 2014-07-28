/*
 * Rectangle.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Rectangle.h"
#include "Canvas.h"

/**
 * Constructor for the Riectangle
 * @param w, is the width of the rectangle
 * @param h, is the height of the rectangle
 * @param description, is the description of the rectangle
 */
Rectangle::Rectangle(int w, int h, std::string description) : Shape("Rectangle", description), w(w), h(h){

}

/**
 * Accessor for the height of the shape.
 * @return the heigh of the shape.
 */
int Rectangle::getH() const {
	return h;
}

/**
 * Mutator for the height of the shape
 * @param h, the new heigh of the shape
 */
void Rectangle::setH(int h) {
	this->h = h;
}

/**
 * Accessor for the width of the shape.
 * @return the width of the shape.
 */
int Rectangle::getW() const {
	return w;
}

/**
 * Mutator for the width of the shape
 * @param h, the new width of the shape
 */
void Rectangle::setW(int w) {
	this->w = w;
}

/**
 * Scaling funtion to increase of decrease the size of the shape
 * it will scale only if the resulting shape hight is larger than zero
 * @param n, the scaling factor
 */
void Rectangle::scale(int n) {
	if (getH() + n > 0 && getW() + n > 0) {
		setH(getH() + n);
		setW(getW() + n);
	}
}

/**
 * Computes the geometrical area of the shape.
 * @return the geometrical area of the shape.
 */
double Rectangle::geoArea() const {
	return getH() * getW();
}

/**
 * Computes the geometrical perimeter of the shape.
 * @return the geometrical perimeter of the shape.
 */
double Rectangle::geoPerimeter() const {
	return 2 * ( getH() + getW() );
}

/**
 * Computes the screen area of the shape.
 * @return the screen area of the shape.
 */
int Rectangle::scrArea() const {
	return getH() * getW();
}

/**
 * Computes the screen perimeter of the shape.
 * @return the screen perimeter of the shape.
 */
int Rectangle::scrPerimeter() const {
	return 2 * ( getH() + getW() ) - 4;
}

/**
 * Computes the horizontal extent of the shape.
 * @return the horizontal extent of the shape.
 */
int Rectangle::hExtent() const {
	return getW();
}

/**
 * Computes the vertical extent of the shape.
 * @return the vertical extent of the shape.
 */
int Rectangle::vExtent() const {
	return getH();
}

/**
 * Draws the shape to a defined location on the canvas using a certain specified character.
 * @param c, the column location where the shape will be drawn
 * @param r, the row location where the shape will be drawn
 * @param canvas, the canvas on which the shape will be drawn
 * @param ch, the character used to draw the shape
 */
void Rectangle::draw(int c, int r, Canvas& canvas, char ch) const {

	for (int i = 0; i < getW(); i++) {
		for (int j = 0; j < getH(); j++) {
			canvas.put(c+i, r+j, ch);
		}
	}

}

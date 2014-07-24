/*
 * Rectangle.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Rectangle.h"
#include "Canvas.h"

Rectangle::Rectangle(int w, int h, std::string description) : Shape("Rectangle", description), w(w), h(h){

}


int Rectangle::getH() const {
	return h;
}

void Rectangle::setH(int h) {
	this->h = h;
}

int Rectangle::getW() const {
	return w;
}

void Rectangle::setW(int w) {
	this->w = w;
}

void Rectangle::scale(int n) {
	if (getH() + n > 0 && getW() + n > 0) {
		setH(getH() + n);
		setW(getW() + n);
	}
}

double Rectangle::geoArea() {
	return getH() * getW();
}

double Rectangle::geoPerimeter() {
	return 2 * ( getH() + getW() );
}

int Rectangle::scrArea() {
	return getH() * getW();
}

int Rectangle::scrPerimeter() {
	return 2 * ( getH() + getW() ) - 4;
}

int Rectangle::hExtent() {
	getW();
}

int Rectangle::vExtent() {
	getH();
}

void Rectangle::draw(int c, int r, Canvas& canvas, char ch) const {
}

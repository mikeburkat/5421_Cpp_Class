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

Isosceles::Isosceles(int h, std::string description) : Shape("Isosceles", description), h(h) {
}

int Isosceles::getH() const {
	return this->h;
}

void Isosceles::setH(int h) {
	this->h = h;
}

int Isosceles::getB() const{
	return getH() * 2 - 1;
}

void Isosceles::scale(int n) {
	if (getH() + n > 0) {
		setH(getH() + n);
	}
}

double Isosceles::geoArea() {
	return getB() * getH() / 2.0;
}

double Isosceles::geoPerimeter() {
	return getB() + 2.0 * std::sqrt( 0.25 * getB() * getB() + getH() * getH() );
}

int Isosceles::scrArea() {
	return getH() * getH();
}

int Isosceles::scrPerimeter() {
	return 4 * ( getH() - 1 );
}

int Isosceles::hExtent() {
	return getB();
}

int Isosceles::vExtent() {
	return getH();
}

void Isosceles::draw(int c, int r, Canvas& canvas, char ch) const {
	for (int i = getH()-1, start = 0; i >= 0; i--, start++) {

		int stars =  (i+1) * 2 - 1 ;

		for (int j = start; j < start + stars; j++) {

//			std::cout << getH() << ", " << c+i << ":" << c+j
//					<< ", start: " << start
//					<< ", stars: " << stars
//					<< std::endl;

			canvas.put(c+j, r+i, ch);
		}
	}
}






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

Isoceles::Isoceles(int h, std::string description) : Shape("Isosceles", description) {
}

int Isoceles::getH() const {
	return this->h;
}

void Isoceles::setH(int h) {
	this->h = h;
}

int Isoceles::getB() {
	return getH() * 2 - 1;
}

void Isoceles::scale(int n) {
	if (getH() + n > 0) {
		setH(getH() + n);
	}
}

double Isoceles::geoArea() {
	return getB() * getH() / 2.0;
}

double Isoceles::geoPerimeter() {
	return getB() + 2.0 * std::sqrt( 0.25 * getB() * getB() + getH() * getH() );
}

int Isoceles::scrArea() {
	return getH() * getH();
}

int Isoceles::scrPerimeter() {
	return 4 * ( getH() - 1 );
}

int Isoceles::hExtent() {
	return getB();
}

int Isoceles::vExtent() {
	return getH();
}

void Isoceles::draw(int c, int r, Canvas& canvas, char ch) const{
}






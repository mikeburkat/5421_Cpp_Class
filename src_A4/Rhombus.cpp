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

Rhombus::Rhombus(int h, std::string description) : Shape("Rhombus", description) {
	setD(h);
}

int Rhombus::getD() const {
	return this->d;
}

void Rhombus::setD(int d) {
	if ( d%2 == 0 ) {
		d++;
	}
	this->d = d;
}

void Rhombus::scale(int n) {
	if (getD() + n > 0) {
		setD(getD() + n * 2);
	}
}

double Rhombus::geoArea() {
	return (getD() * getD()) / 2.0;
}

double Rhombus::geoPerimeter() {
	return std::sqrt(2) * 2.0 * getD();
}

int Rhombus::scrArea() {
	int n = getD() / 2;
	return 2 * n * (n + 1) + 1;
}

int Rhombus::scrPerimeter() {
	return 2 * (getD() - 1);
}

int Rhombus::hExtent() {
	return getD();
}

int Rhombus::vExtent() {
	return getD();
}

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


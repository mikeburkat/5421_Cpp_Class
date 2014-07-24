/*
 * RightIsosceles.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include <cmath>

RightIsosceles::RightIsosceles(int h, std::string description) {
}

int RightIsosceles::getH() const {
	return this->h;
}

void RightIsosceles::setH(int h) {
	this->h = h;
}

void RightIsosceles::scale(int n) {
	if (getH() + n > 0) {
		setH(getH() + n);
	}
}

double RightIsosceles::geoArea() {
	return getH() * getH() / 2.0;
}

double RightIsosceles::geoPerimeter() {
	return ( 2.0 + std::sqrt(2) ) * getH();
}

int RightIsosceles::scrArea() {
	return getH() * (getH() + 1) / 2;
}

int RightIsosceles::scrPerimeter() {
	return 3 * (getH() - 1);
}

int RightIsosceles::hExtent() {
	getH();
}

int RightIsosceles::vExtent() {
	getH();
}

void RightIsosceles::draw() {
}





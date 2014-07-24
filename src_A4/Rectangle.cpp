/*
 * Rectangle.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

Rectangle::Rectangle(int w, int h, std::string description) : genericName("Rectangle"), description(description), w(w), h(h){

}


int Rectangle::getH() const {
	return h;
}

void Rectangle::setH(int h) {
	this->h = h;
}

int Rectangle::getV() const {
	return w;
}

void Rectangle::setV(int v) {
	this->w = w;
}

void Rectangle::scale(int n) {
	if (getH() + n > 0 && getW() + n > 0) {
		setH(getH() + n);
		setV(getW() + n);
	}
}

double Rectangle::geoArea() {
	return getH() * getW();
}

double Rectangle::geoPerimeter() {
	return 2 ( getH() + getW() );
}

int Rectangle::scrArea() {
	return getH() * getW();
}

int Rectangle::scrPerimeter() {
	return 2 ( getH() + getW() ) - 4;
}

int Rectangle::hExtent() {
	getW();
}

int Rectangle::vExtent() {
	getH();
}

void Rectangle::draw() {
}

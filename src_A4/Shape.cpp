/*
 * Shape.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Shape.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <iomanip>

int Shape::shapeID = 0;


Shape::Shape(std::string genericName, std::string description)
	: id(++shapeID), genericName(genericName), description(description){

}

int Shape::getId() {
	return this->id;
}

std::string Shape::getGenericName() {
	return this->genericName;
}

std::string Shape::getDescription() {
	return this->description;
}

void Shape::setDescription(std::string description) {
	this->description = description;
}

std::string Shape::toString() {

	std::stringstream ss;

	ss << "Shape Information" << std::endl;
	ss << "-----------------" << std::endl;
	ss << "Type of this:  " << typeid(this).name() << std::endl;
	ss << "Type of *this: " << typeid(*this).name() << std::endl;
	ss << "Generic Name:  " << getGenericName() << std::endl;
	ss << "Description:   " << getDescription() << std::endl;
	ss << "id:            " << getId() << std::endl;
	ss << "H extent:      " << this->hExtent() << std::endl;
	ss << "V extent:      " << this->vExtent() << std::endl;
	ss << "Scr area:      " << this->scrArea() << std::endl;
	ss << "Geo area:      " << std::fixed << std::setprecision(2) << this->geoArea() << std::endl;
	ss << "Scr perimeter: " << this->scrPerimeter() << std::endl;
	ss << "Geo perimeter: " << this->geoPerimeter() << std::endl;

	return ss.str();
}


std::ostream& operator <<(std::ostream& out, Shape& s) {

	out << s.toString() << std::endl;

	return out;
}


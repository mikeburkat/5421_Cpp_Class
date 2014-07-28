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

/**
 * initializes the shape id to zero, in order to track the number of shapes.
 */
int Shape::shapeID = 0;

/**
 * Constructor for the shape class.
 * @param genericName, the generic name of the shape.
 * @param description, the description of the shape, there is a defult value of "Generic" + the genericName.
 */
Shape::Shape(std::string genericName, std::string description)
	: id(++shapeID), genericName(genericName), description(description){
}

/**
 * Accessor for the shape's id.
 * @return shape id.
 */
int Shape::getId() const {
	return this->id;
}

/**
 * Accessor for the generic name of the shape.
 * @return shape's generic name.
 */
std::string Shape::getGenericName() const {
	return this->genericName;
}

/**
 * Accessor for the description of the shape.
 * @return shape's description.
 */
std::string Shape::getDescription() const {
	return this->description;
}

/**
 * Mutator for the description of the shape.
 * @param description, the new description.
 */
void Shape::setDescription(std::string description) {
	this->description = description;
}

/**
 * A string representation of the shape, with information about it.
 * @return shape's information as a string.
 */
std::string Shape::toString() const {

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

/**
 * Extractor for the shape information, used to output the shape's information.
 * @return the output stream object.
 */
std::ostream& operator <<(std::ostream& out, Shape& s) {
	out << s.toString() << std::endl;
	return out;
}


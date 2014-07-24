/*
 * Shape.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "Shape.h"
#include <iostream>

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
	std::cout << "toString()" << std::endl;
}

/*
 * Shape.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#include "shape.h"

int Shape::shapeID = 0;


Shape::Shape() : id(++shapeID){

}


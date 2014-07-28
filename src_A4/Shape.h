/*
 * Shape.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include "Canvas.h"


class Shape {

private:
	static int shapeID; // the id's of the static shape class, used to track the number of shape instances.

	int id; // the id of the shape instance.
	std::string genericName; // the generic name of the shape.
	std::string description; // the description of the shape.

public:
	Shape(std::string, std::string); // constructor accepting a generic name and description.

	int getId() const; // accessor for the shape's id.
	std::string getGenericName() const; // accessor for the generic name.
	std::string getDescription() const; // accessor for the description.

	virtual void setDescription(std::string); // mutator used to change the shape description.

	std::string toString() const; // returns the shape information as a string.

	friend std::ostream& operator<<(std::ostream&, Shape&); // outputs the shape information.

	// purely virtual methods that need to be overriden by derivatives.
	virtual void scale(int) = 0; // increases the size of the shape by an integer value.
	virtual double geoArea() const = 0; // returns the geometric area.
	virtual double geoPerimeter() const = 0; // returns the geometric perimeter.
	virtual int scrArea() const = 0; // returns the screen area.
	virtual int scrPerimeter() const = 0; // returns the screen permimeter.
	virtual int hExtent() const = 0; // returns the horizontal extent.
	virtual int vExtent() const = 0; // returns the vertical extent.
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const = 0; // draws the shape onto the canvas parameter.

};


#endif /* SHAPE_H_ */

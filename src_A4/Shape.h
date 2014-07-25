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
	static int shapeID;

	int id; // const?
	std::string genericName; // const?
	std::string description;

public:
	Shape(std::string, std::string);

	int getId();
	std::string getGenericName();
	std::string getDescription();

	virtual void setDescription(std::string);

	std::string toString();

	virtual void scale(int) = 0;
	virtual double geoArea() = 0;
	virtual double geoPerimeter() = 0;
	virtual int scrArea() = 0;
	virtual int scrPerimeter() = 0;
	virtual int hExtent() = 0;
	virtual int vExtent() = 0;
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const = 0;

	friend std::ostream& operator<<(std::ostream&, Shape&);
};


#endif /* SHAPE_H_ */

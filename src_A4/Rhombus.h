/*
 * Rhombus.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef RHOMBUS_H_
#define RHOMBUS_H_

#include "Canvas.h"
#include "Shape.h"

class Rhombus: public Shape {

private:
	int d;

public:
	Rhombus(int, std::string = "Generic Rhombus");
	int getD() const;
	void setD(int d);

	virtual void scale(int) override; // overriding the scale function from the Shape class.
	virtual double geoArea() const override; // overriding the gometric area function from the Shape class.
	virtual double geoPerimeter() const override; // overriding the geometric perimeter function from the Shape class.
	virtual int scrArea() const override; // overriding the screen area function from the Shape class.
	virtual int scrPerimeter() const override; // overriding the screen perimeter function from the Shape class.
	virtual int hExtent() const override; // overriding the horizontal extent function from the Shape class.
	virtual int vExtent() const override; // overriding the vertical extent funtion from the Shape class.
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override; // overriding the draw funtion from the Shape class.

};




#endif /* RHOMBUS_H_ */

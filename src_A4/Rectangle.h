/*
 * Rectangle.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Canvas.h"
#include "Shape.h"

class Rectangle: public Shape {

private:
	int w;
	int h;

public:
	Rectangle(int, int, std::string = "Generic Rectangle");
	int getH() const;
	void setH(int h);
	int getW() const;
	void setW(int w);

	virtual void scale(int) override; // overriding the scale function from the Shape class.
	virtual double geoArea() const override; // overriding the gometric area function from the Shape class.
	virtual double geoPerimeter() const override; // overriding the geometric perimeter function from the Shape class.
	virtual int scrArea() const override; // overriding the screen area function from the Shape class.
	virtual int scrPerimeter() const override; // overriding the screen perimeter function from the Shape class.
	virtual int hExtent() const override; // overriding the horizontal extent function from the Shape class.
	virtual int vExtent() const override; // overriding the vertical extent funtion from the Shape class.
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override; // overriding the draw funtion from the Shape class.


};

#endif /* RECTANGLE_H_ */

/*
 * RightIsosceles.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef RIGHTISOSCELES_H_
#define RIGHTISOSCELES_H_

#include "Canvas.h"
#include "Shape.h"

class RightIsosceles: public Shape {

private:
	int h; // height of the right isosceles.

public:
	RightIsosceles(int, std::string = "Generic Right Isosceles Triangle"); // constructor accepting a height and description.

	int getH() const; // accessor for the height of the triangle.
	void setH(int h); // mutator for the height of the triangle.

	virtual void scale(int) override; // overriding the scale function from the Shape class.
	virtual double geoArea() const override; // overriding the gometric area function from the Shape class.
	virtual double geoPerimeter() const override; // overriding the geometric perimeter function from the Shape class.
	virtual int scrArea() const override; // overriding the screen area function from the Shape class.
	virtual int scrPerimeter() const override; // overriding the screen perimeter function from the Shape class.
	virtual int hExtent() const override; // overriding the horizontal extent function from the Shape class.
	virtual int vExtent() const override; // overriding the vertical extent funtion from the Shape class.
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override; // overriding the draw funtion from the Shape class.

};

#endif /* RIGHTISOSCELES_H_ */

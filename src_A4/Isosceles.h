/*
 * Isosceles.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef ISOSCELES_H_
#define ISOSCELES_H_

#include "Canvas.h"
#include "Shape.h"

class Isosceles: public Shape {

private:
	int h;

public:
	Isosceles(int, std::string = "Generic Isoceles Triangle");
	int getH() const;
	void setH(int h);
	int getB() const;

	virtual void scale(int) override; // overriding the scale function from the Shape class.
	virtual double geoArea() const override; // overriding the gometric area function from the Shape class.
	virtual double geoPerimeter() const override; // overriding the geometric perimeter function from the Shape class.
	virtual int scrArea() const override; // overriding the screen area function from the Shape class.
	virtual int scrPerimeter() const override; // overriding the screen perimeter function from the Shape class.
	virtual int hExtent() const override; // overriding the horizontal extent function from the Shape class.
	virtual int vExtent() const override; // overriding the vertical extent funtion from the Shape class.
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override; // overriding the draw funtion from the Shape class.


};


#endif /* ISOSCELES_H_ */

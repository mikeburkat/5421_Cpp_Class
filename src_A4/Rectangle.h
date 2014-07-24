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

	virtual void scale(int) override;
	virtual double geoArea() override;
	virtual double geoPerimeter() override;
	virtual int scrArea() override;
	virtual int scrPerimeter() override;
	virtual int hExtent() override;
	virtual int vExtent() override;
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override;

};

#endif /* RECTANGLE_H_ */

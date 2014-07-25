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

	virtual void scale(int) override;
	virtual double geoArea() override;
	virtual double geoPerimeter() override;
	virtual int scrArea() override;
	virtual int scrPerimeter() override;
	virtual int hExtent() override;
	virtual int vExtent() override;
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override;

};


#endif /* ISOSCELES_H_ */

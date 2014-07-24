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
	int h;

public:
	RightIsosceles(int, std::string = "Generic Right Isosceles Triangle");
	int getH() const;
	void setH(int h);

	virtual void scale(int) override;
	virtual double geoArea() override;
	virtual double geoPerimeter() override;
	virtual int scrArea() override;
	virtual int scrPerimeter() override;
	virtual int hExtent() override;
	virtual int vExtent() override;
	virtual void draw(int c, int r, Canvas& canvas, char ch = '*') const override;

};



#endif /* RIGHTISOSCELES_H_ */

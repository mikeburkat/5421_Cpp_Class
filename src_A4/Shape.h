/*
 * Shape.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {

private:
	static int shapeID;


protected:
	int id; // const?
	std::string genericName; // const?
	std::string description;

public:
	Shape();

	int getId();
	std::string getGenericName();
	std::string getDescription();

	virtual void setDescription(std::string);

	std::string toString();

	virtual void scale(int);
	virtual double geoArea();
	virtual double geoPerimeter();
	virtual int scrArea();
	virtual int scrPerimeter();
	virtual int hExtent();
	virtual int vExtent();
	virtual void draw();

};


#endif /* SHAPE_H_ */

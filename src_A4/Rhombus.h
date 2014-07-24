/*
 * Rhombus.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef RHOMBUS_H_
#define RHOMBUS_H_

class Rhombus: public Shape {

private:
	int d;

public:
	Rhombus(int, std::string = "Generic Rhombus");
	int getD() const;
	void setD(int d);

	virtual void scale(int) override;
	virtual double geoArea() override;
	virtual double geoPerimeter() override;
	virtual int scrArea() override;
	virtual int scrPerimeter() override;
	virtual int hExtent() override;
	virtual int vExtent() override;
	virtual void draw() override;

};




#endif /* RHOMBUS_H_ */

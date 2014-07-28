/*
 * BorderedCanvas.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef BORDEREDCANVAS_H_
#define BORDEREDCANVAS_H_

#include "Canvas.h"
#include <vector>
#include <iostream>

class BorderedCanvas : public Canvas {

public:
	BorderedCanvas(int, int); // constructor taking the width and height of the canvas
	virtual void clear(char = ' ') override; // clear the canvas replacing it by the char param
	virtual void put(int, int, char = '*') override; // place a char at a column and row location on the canvas
	virtual char get(int, int) const override; // get the char at a column and row location on the canvas
	virtual void decorate() override; // decorate the canvas. overriden in derivatives

};


#endif /* BORDEREDCANVAS_H_ */

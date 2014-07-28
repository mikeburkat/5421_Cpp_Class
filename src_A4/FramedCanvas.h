/*
 * FramedCanvas.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef FRAMEDCANVAS_H_
#define FRAMEDCANVAS_H_


#include "Canvas.h"
#include <vector>
#include <iostream>

class FramedCanvas : public Canvas {

private:
	std::string title; // string containing the frame title

public:
	FramedCanvas(int, int, std::string); // constructor taking the width and height of the canvas and a string for the frame name.
	virtual void clear(char = ' ') override; // clear the canvas replacing it by the char param
	virtual void put(int, int, char = '*') override; // place a char at a column and row location on the canvas
	virtual char get(int, int) const override; // get the char at a column and row location on the canvas
	virtual void decorate() override; // decorate the canvas. overriden in derivatives

};


#endif /* FRAMEDCANVAS_H_ */

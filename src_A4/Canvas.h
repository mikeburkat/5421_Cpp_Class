/*
 * Canvas.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Mike
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include <vector>
#include <iostream>

class Canvas {

private:
	std::vector<std::vector<char>> grid; // the grid containing the char image

public:
	Canvas(int, int); // constructor taking the width and height of the canvas
	int geth() const; // accessor for the height of the canvas
	int getw() const; // accessor for the width of the canvas

	virtual void clear(char = ' '); // clear the canvas replacing it by the char param
	virtual void put(int, int, char ch = '*'); // place a char at a column and row location on the canvas
	virtual char get(int, int) const; // get the char at a column and row location on the canvas
	virtual void decorate(); // decorate the canvas. overriden in derivatives

	friend std::ostream& operator<<(std::ostream&, Canvas&); // extractor used to print the canvas to output stream

};




#endif /* CANVAS_H_ */

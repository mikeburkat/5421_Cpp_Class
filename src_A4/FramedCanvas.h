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
	std::string title;

public:
	FramedCanvas(int, int, std::string);
	virtual void clear(char = ' ') override;
	virtual void put(int, int, char = '*') override;
	virtual char get(int, int) const override;
	virtual void decorate() override;

};


#endif /* FRAMEDCANVAS_H_ */

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
	BorderedCanvas(int, int);
	virtual void clear(char = ' ') override;
	virtual void put(int, int, char = '*') override;
	virtual char get(int, int) const override;
	virtual void decorate() override;

};


#endif /* BORDEREDCANVAS_H_ */

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
	std::vector<std::vector<char>> grid;

public:
	Canvas(int, int);
void clear(char);



friend std::ostream& operator<<(std::ostream&, Canvas&);

};




#endif /* CANVAS_H_ */

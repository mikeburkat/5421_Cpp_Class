/*
 * WordNode.h
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#include "WordData.h"

#ifndef WORDNODE_H_
#define WORDNODE_H_

class WordNode {
public:
	WordNode();
	virtual ~WordNode();

private:
	WordData wordData;
	WordNode *wordNode;
};

#endif /* WORDNODE_H_ */

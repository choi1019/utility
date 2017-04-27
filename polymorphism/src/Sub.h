/*
 * Sub.h
 *
 *  Created on: 2017. 2. 17.
 *      Author: Sungwoon Choi
 */

#ifndef SUB_H_
#define SUB_H_

#include "Super.h"

class Sub: public Super {
public:
	Sub();
	virtual ~Sub();

	void Print();
};

#endif /* SUB_H_ */

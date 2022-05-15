/*
 * Serializable.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_ "SERIALIZABLE_H_"

#include "Exception.h"
#include "Array.h"
#include <string>
#include <sstream>
using namespace std;

class Serializable {
private:

public:
	virtual void read(Lex& lex, string key) throw() {}
	virtual void write(Lex& lex) throw() {}
};

#endif /* SERIALIZABLE_H_ */

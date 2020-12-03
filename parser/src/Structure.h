/*
 * Structure.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_ "STRUCTURE_H_"


#include "Map.h"
#include "Element.h"
#include <string>
//#include <map>

using namespace std;


class Structure: public Element {
protected:
	Map elements;
public:
	Structure();
	virtual ~Structure();

	virtual ENodeType getType();

	void clearElements();
	Element *getElement(string key) throw();
	void addElement(Element *pElement) throw();

	void read(Lex& lex, string key) throw();
	void write(Lex& lex) throw();
};

#endif /* STRUCTURE_H_ */

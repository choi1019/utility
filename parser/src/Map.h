/*
 * Map.h
 *
 *  Created on: 2017. 4. 9.
 *      Author: choi.sungwoon
 */

#ifndef MAP_H_
#define MAP_H_

#include "Exception.h"
#include "Element.h"

#include <string>
using namespace std;

#define MAXMAPLENGTH 20
class Map {
private:
	int length;
	string keys[MAXMAPLENGTH];
	Element *pElements[MAXMAPLENGTH];
public:
	Map() { this->length = 0; }
	virtual ~Map() {}

	int getLength() { return this->length; }
	void clear() { this->length = 0; }

	Element* getElement(int index) throw();
	Element* find(string key) throw();
	void insert(string key, Element* pElement) throw();

};


#endif /* MAP_H_ */

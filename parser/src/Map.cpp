/*
 * Map.cpp
 *
 *  Created on: 2017. 4. 9.
 *      Author: choi.sungwoon
 */

#include "Map.h"


Element* Map::getElement(int index) throw() {
	if (index >= this->length || index < 0)
		throw Exception("Map::", "get", "indexOutOfBounds", index);

	return this->pElements[index];
}
Element* Map::find(string key) throw() {
	for (int i=0; i<this->length; i++) {
		if (this->keys[i].compare(key) == 0)
			return pElements[i];
	}
	return NULL;
}
void Map::insert(string key, Element* pElement) throw() {
	if (this->length == MAXMAPLENGTH)
		throw Exception("Map::", "insert", "Overflow", this->length);

	this->keys[this->length] = key;
	this->pElements[this->length] = pElement;
	this->length++;
}


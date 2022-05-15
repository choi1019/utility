/*
 * Array.h
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Structure.h"

class Array: public Structure {
public:
	Array();
	virtual ~Array();

	virtual ENodeType getType();

	void read(Lex& lex, string key) throw() {
		lex.readIndexEnd();
		lex.readBegin();

		this->setKey(key);
		gMessage.show("Array", "read", key);
		// read while(not end);
		int index = 0;
		while (lex.readEnd().empty() && !lex.eof()) {
			// generate new element
			Element* pElement = 0;
			if (!lex.readBegin().empty()) {
				pElement = new Structure();
			}
			else if (!lex.readIndexBegin().empty()) {
				pElement = new Array();
			}
			else {
				pElement = new Element();
			}
			// read element data
			stringstream ss;
			ss << index;
			string Indexkey;
			ss >> Indexkey;
			pElement->read(lex, Indexkey);
			index++;
			// add element
			this->addElement(pElement);
		}
	}
	void write(Lex& lex) throw() {
		for (int i = 0; i < elements.getLength(); i++) {
			Element* pElement = elements.getElement(i);
			if (pElement->getType() == eStructure) {
				lex.writeTab();
				lex.writeBegin();
				pElement->write(lex);
				lex.writeEnd();
			}
			else if (pElement->getType() == eArray) {
				lex.writeIndexBegin();
				lex.writeIndexEnd();
				lex.writeBegin();
				pElement->write(lex);
				lex.writeEnd();
			}
			else {
				lex.writeTab();
				lex.writeValue(pElement->getValue());
			}
		}
	}
};

#endif /* ARRAY_H_ */

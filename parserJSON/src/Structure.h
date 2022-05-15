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

	void read(Lex& lex, string key) throw() {
		this->setKey(key);
		// read while(not end);
		while (lex.readEnd().empty() && !lex.eof()) {
			// read key
			string elementdKey = lex.readKey();
			gMessage.show("Structure", "read", key);
			if (elementdKey.empty())
				throw Exception(STRUCTURE_H_, "Structure::read", key);
			// generate new element
			Element* pElement = nullptr;
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
			pElement->read(lex, elementdKey);
			// add element
			this->addElement(pElement);
		}
	}
	void write(Lex& lex) throw() {
		for (int i = 0; i < elements.getLength(); i++) {
			Element* pElement = elements.getElement(i);
			lex.writeKey(pElement->getKey());
			if (pElement->getType() == eStructure) {
				lex.writeSpace();
				lex.writeBegin();
				pElement->write(lex);
				lex.writeEnd();
			}
			else if (pElement->getType() == eArray) {
				lex.writeIndexBegin();
				lex.writeIndexEnd();
				lex.writeSpace();
				lex.writeBegin();
				pElement->write(lex);
				lex.writeEnd();
			}
			else {
				lex.writeValue(pElement->getValue());

			}
		}
	}
};

#endif /* STRUCTURE_H_ */

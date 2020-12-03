/*
 * Structure.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */
#include "Exception.h"
#include "Structure.h"
#include "Array.h"

Structure::Structure() {}
Structure::~Structure() {}

ENodeType Structure::getType() { return eStructure; }

void Structure::clearElements() {
	for (int i=0; i<elements.getLength(); i++) {
		Element *pElement = elements.getElement(i);
		if (pElement->getType() == eStructure) {
			Structure* pStructure = (Structure*)pElement;
			pStructure->clearElements();
		}
	}
	this->elements.clear();
}
Element *Structure::getElement(string key) throw() {
	Element* pElement = this->elements.find(key);
	return pElement;
}
void Structure::addElement(Element *pElement) throw() {
	this->elements.insert(pElement->getKey(), pElement);
}

void Structure::read(Lex& lex, string key) throw() {
	this->setKey(key);
	// read while(not end);
	while (lex.readEnd().empty() && !lex.eof()) {
		// read key
		string elementdKey = lex.readString();
		gMessage.show("Structure", "read", key);
		if (elementdKey.empty())
			throw Exception(STRUCTURE_H_, "Structure::read", key);
		// generate new element
		Element* pElement = 0;
		if (!lex.readBegin().empty()) {
			pElement = new Structure();
		} else if (!lex.readIndexBegin().empty()) {
			pElement = new Array();
		} else {
			pElement = new Element();
		}
		// read element data
		pElement->read(lex, elementdKey);
		// add element
		this->addElement(pElement);
	}
}
void Structure::write(Lex& lex) throw() {
	for (int i=0; i<elements.getLength(); i++) {
		Element *pElement = elements.getElement(i);
		lex.writeKey(pElement->getKey());
		if (pElement->getType() == eStructure) {
			lex.writeSpace();
			lex.writeBegin();
			pElement->write(lex);
			lex.writeEnd();
		} else if (pElement->getType() == eArray) {
			lex.writeIndexBegin();
			lex.writeIndexEnd();
			lex.writeSpace();
			lex.writeBegin();
			pElement->write(lex);
			lex.writeEnd();
		} else {
			lex.writeValue(pElement->getValue());

		}
	}
}




/*
 * Element.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */
#include "Element.h"

Element::Element() {}
Element::~Element() {}

ENodeType Element::getType() { return eElement; }

const string& Element::getKey() const {return key;}
void Element::setKey(const string& key) {this->key = key;}

const string& Element::getValue() const {return value;}
void Element::setValue(const string& value) {this->value = value;}




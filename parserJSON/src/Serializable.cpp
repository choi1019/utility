/*
 * Serializable.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

/*
#include "Serializable.h"
#include "Array.h"
#include <iostream>
using namespace std;

Serializable::Serializable() {pStructure = 0;}
Serializable::~Serializable() {}

int Serializable::getInt(string value) {
	int result;
	stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

float Serializable::getFloat(string value) {
	float result;
	stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

string Serializable::getString(int value) {
	string result;
	stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

string Serializable::getString(float value) {
	string result;
	stringstream ss;
	ss << value;
	ss >> result;
	return result;
}

Structure* Serializable::getStructure() { return this->pStructure; }
void Serializable::setStructure(Structure* pStructure) { this->pStructure = pStructure; }

// get Serializable data from Structures
void Serializable::get(int& result, string key) throw() {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getInt-not found", key);
		return;
	}
	gMessage.show("Serializable", "getInt", key);
	string token = pElement->getValue();
	result = this->getInt(token);
}
void Serializable::get(float& result, string key) throw() {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getFloat-not found", key);
		return;
	}
	gMessage.show("Serializable", "getFloat", key);
	string token = pElement->getValue();
	result = this->getInt(token);
}
void Serializable::get(string& result, string key) throw() {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getString-not found", key);
		return;
	}
	gMessage.show("Serializable", "getString", key);
	result = pElement->getValue();
}

void Serializable::get(Serializable& serializable, string key) throw() {
	// find a child structure named key
	Structure *pElement = (Structure*) this->pStructure->getElement(key);
	if (pElement==NULL) {
		throw Exception(SERIALIZABLE_H_, "getValueStructure-not found", key);
	}
	gMessage.show("Serializable", "pStructure", key);
	// associate the serializable with a found structure
	serializable.setStructure(pElement);
	// fill each field
	serializable.read();
}

void Serializable::get(int result[], int length, string key) throw() {
	Array *pArray = (Array*)this->pStructure->getElement(key);
	if (pArray==NULL) {
		throw Exception(SERIALIZABLE_H_, "getArray-not found", key);
	}
	gMessage.show("Serializable", "getArrayInt", pArray->getKey());

	for (int i=0; i<length; i++) {
		string indexKey = this->getString(i);
		Element *pElement = pArray->getElement(indexKey);
		if (pElement==NULL) {
			throw Exception(SERIALIZABLE_H_, "getArrayElement-not found", key, indexKey);
		}
		if (pElement->getType() == eElement) {
			result[i] = this->getInt(pElement->getValue());
		}
	}
}
void Serializable::get(float result[], int length, string key) throw() {
	Array *pArray = (Array*)this->pStructure->getElement(key);
	if (pArray==NULL) {
		throw Exception(SERIALIZABLE_H_, "getArray-not found", key);
	}
	gMessage.show("Serializable", "getArrayFloat", pArray->getKey());

	for (int i=0; i<length; i++) {
		string indexKey = this->getString(i);
		Element *pElement = pArray->getElement(indexKey);
		if (pElement==NULL) {
			throw Exception(SERIALIZABLE_H_, "getArrayElement-not found", key, indexKey);
		}
		if (pElement->getType() == eElement) {
			result[i] = this->getFloat(pElement->getValue());
		}
	}
}
void Serializable::get(string result[], int length, string key) throw() {
	Array *pArray = (Array*)this->pStructure->getElement(key);
	if (pArray==NULL) {
		throw Exception(SERIALIZABLE_H_, "getArray-not found", key);
	}
	gMessage.show("Serializable", "getArrayString", pArray->getKey());

	for (int i=0; i<length; i++) {
		string indexKey = this->getString(i);
		Element *pElement = pArray->getElement(indexKey);
		if (pElement==NULL) {
			throw Exception(SERIALIZABLE_H_, "getArrayElement-not found", key, indexKey);
		}
		if (pElement->getType() == eElement) {
			result[i] = pElement->getValue();
		}
	}
}

Structure* Serializable::prepareStructure(string key) {
	Structure* pElement = (Structure*)this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Structure();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	return pElement;
}
Array* Serializable::prepareArray(string key) {
	Array* pElement = (Array*)this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Array();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	return pElement;
}
Element* Serializable::prepareElement(string key) {
	Element* pElement = this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Element();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	return pElement;
}

// load data to child serializable structure
void Serializable::set(Serializable& serializable, string key) throw() {
	Structure* pElement = (Structure*) this->prepareStructure(key);
	gMessage.show("Serializable", "setStructure", key);

	// write serializable data to the associated structure
	serializable.setStructure(pElement);
	serializable.write();
}
void Serializable::set(int& value, string key) throw() {
	Element* pElement = this->prepareElement(key);
	string result = this->getString(value);
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}
void Serializable::set(float& value, string key) throw() {
	Element* pElement = this->prepareElement(key);
	string result = this->getString(value);
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}
void Serializable::set(string& result, string key) throw() {
	Element* pElement = this->prepareElement(key);
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}

void Serializable::set(int value[], int length, string key) throw() {
	Array* pArray = this->prepareArray(key);
	gMessage.show("Serializable", "setIntArray", key);
	for (int i=0; i<length; i++) {
		string elementKey = this->getString(i);
		Element* pElement = pArray->getElement(elementKey);
		if (pElement == NULL) {
			pElement = new Element();
			pElement->setKey(elementKey);
			pArray->addElement(pElement);
		}
		string  result = this->getString(value[i]);
		pElement->setValue(result);
		cout << "  " << "   setArrayElement" << "(" << elementKey <<  ")" << result <<endl;
	}
}
void Serializable::set(float value[], int length, string key) throw() {
	Array* pArray = this->prepareArray(key);
	gMessage.show("Serializable", "setIntArray", key);
	for (int i=0; i<length; i++) {
		string elementKey = this->getString(i);
		Element* pElement = pArray->getElement(elementKey);
		if (pElement == NULL) {
			pElement = new Element();
			pElement->setKey(elementKey);
			pArray->addElement(pElement);
		}
		string  result = this->getString(value[i]);
		pElement->setValue(result);
		cout << "  " << "   setArrayElement" << "(" << elementKey <<  ")" << result <<endl;
	}
}
void Serializable::set(string value[], int length, string key) throw() {
	Array* pArray = this->prepareArray(key);
	gMessage.show("Serializable", "setIntArray", key);
	for (int i=0; i<length; i++) {
		string elementKey = this->getString(i);
		Element* pElement = pArray->getElement(elementKey);
		if (pElement == NULL) {
			pElement = new Element();
			pElement->setKey(elementKey);
			pArray->addElement(pElement);
		}
		pElement->setValue(value[i]);
		cout << "  " << "   setArrayElement" << "(" << elementKey <<  ")" << value[i]<<endl;
	}
}

*/
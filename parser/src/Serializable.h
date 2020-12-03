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
	Structure *pStructure;

	int getInt(string value);
	float getFloat(string value);
	string getString(int value);
	string getString(float value);

	Element* prepareElement(string key);
	Structure* prepareStructure(string key);
	Array* prepareArray(string key);

public:
	Serializable();
	virtual ~Serializable();

	Structure* getStructure();
	void setStructure(Structure* pStructure);
	// get Serializable data from Structures
	virtual void read() = 0;

	void get(Serializable& serializable, string key) throw ();
	void get(int& result, string key) throw ();
	void get(float& result, string key) throw ();
	void get(string& result, string key) throw ();
	void get(int result[], int length, string key) throw ();
	void get(float result[], int length, string key) throw ();
	void get(string result[], int length, string key) throw ();
	template<class T>
	void get(T serializable[], int length, string key) throw () {
		Array *pArray = (Array*) this->pStructure->getElement(key);
		if (pArray == NULL) {
			throw Exception(SERIALIZABLE_H_, "getArray-not found", key);
		}
		gMessage.show("Serializable", "getArrayStructure", pArray->getKey());
		for (int index = 0; index < length; index++) {
			string indexKey = this->getString(index);
			Element *pElement = pArray->getElement(indexKey);
			if (pElement == NULL) {
				throw Exception(SERIALIZABLE_H_, "getArrayElement-not found",
						key, indexKey);
			}
			if (pElement->getType() == eStructure) {
				gMessage.show("  Structure::Array", "index = ", indexKey);
				// associate the serializable with a found structure
				serializable[index].setStructure((Structure*) pElement);
				// fill each field
				serializable[index].read();
			}
		}
	}

	// create Structures from Serializable data
	virtual void write() = 0;
	// load data to child serializable structure
	void set(Serializable& serializable, string key) throw ();
	void set(int& value, string key) throw ();
	void set(float& value, string key) throw ();
	void set(string& value, string key) throw ();
	void set(int value[], int length, string key) throw ();
	void set(float value[], int length, string key) throw ();
	void set(string value[], int length, string key) throw ();
	template<class T>
	void set(T serializable[], int length, string key) throw () {
		Array* pArray = this->prepareArray(key);
		for (int index = 0; index < length; index++) {
			string elementKey = this->getString(index);
			gMessage.show("Serializable", "setStructureArray", key, elementKey);
			Structure* pElement = (Structure *) pArray->getElement(elementKey);
			if (pElement == NULL) {
				pElement = new Structure();
				pElement->setKey(elementKey);
				pArray->addElement(pElement);
				serializable[index].setStructure(pElement);
			}
			serializable[index].write();
		}
	}
};

#endif /* SERIALIZABLE_H_ */

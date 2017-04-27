/*
 * Element.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_ "ELEMENT_H_"

#include "Exception.h"
#include "Lex.h"
#include <string>
using namespace std;

enum ENodeType {eElement, eStructure, eArray, eNone};

class Element {
private:
	string key;
	string value;
public:
	Element();
	virtual ~Element();

	virtual ENodeType getType();

	const string& getKey() const;
	void setKey(const string& key);

	const string& getValue() const;
	void setValue(const string& value);

	virtual void read(Lex& lex, string key) throw();
	virtual void write(Lex& lex) throw();
};

#endif /* ELEMENT_H_ */

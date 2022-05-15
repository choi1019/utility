/*
 * Parser.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef PARSER_H_
#define PARSER_H_  "PARSER_H_"

#include "Lex.h"
#include "Serializable.h"

using namespace std;

class Parser: public Structure {
private:
	Lex lex;
	string path, fileName;

	void openIn(string path, string fileName) throw() {
		this->path = path;
		this->fileName = fileName;
		this->lex.openIn(path, fileName);
		this->clearElements();
	}
	void closeIn() throw() {
		this->lex.closeIn();
	}

	void openOut(string path, string fileName) throw() {
		this->path = path;
		this->fileName = fileName;
		this->lex.openOut(path, fileName);
		this->clearElements();
	}
	void closeOut() throw() {
		this->lex.closeOut();
	}

public:
	Parser() {}
	virtual ~Parser() {
	}

	void parse(string path, string fileName) {
		this->openIn(path, fileName);
		this->read(this->lex, this->fileName);
		this->closeIn();
	}
	void parse(string path, string fileName) {
		this->openOut(path, fileName);
		this->write(this->lex);
		this->closeOut();
	}


};


#endif /* PARSER_H_ */

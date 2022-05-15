/*
 * Lex.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef LEX_H_
#define LEX_H_ "LEX_H_"

#include "Exception.h"

#include <string>
#include <fstream>
using namespace std;

#define BLANKS " \t\n\r"
#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'
#define BEGIN '{'
#define END '}'
#define INDEXBEGIN '['
#define INDEXEND ']'
#define PERIOD '.'
#define COMMA ','
#define COLON ':'
#define ZERO '0'
#define NINE '9'

#define PATHSEPARATOR "/"
#define EXTENSION ".txt"

class Lex {
private:
	ifstream fin;
	ofstream fout;

	char lookahead;
	string tabs;

	bool isBlank(char c) {
		string token;
		token.append(BLANKS);
		if (token.find(c) != string::npos) return true;
		return false;
	}
	bool isBegin(char c) {
		if (c == BEGIN) return true;
		return false;
	}
	bool isEnd(char c) {
		if (c == END) return true;
		return false;
	}
	bool isIndexBegin(char c) {
		if (c == INDEXBEGIN) return true;
		return false;
	}
	bool isIndexEnd(char c) {
		if (c == INDEXEND) return true;
		return false;
	}

	bool isDelimeter(char c) {
		if (this->isBlank(c)) return true;
		if (this->isBegin(c)) return true;
		if (this->isEnd(c)) return true;
		if (this->isIndexBegin(c)) return true;
		if (this->isIndexEnd(c)) return true;
		if (this->isComma(c)) return true;
		if (this->isColon(c)) return true;
		return false;
	}
	bool isDigit(char c) {
		if (c >= ZERO && c <= NINE) return true;
		return false;
	}
	bool isPeriod(char c) {
		if (c == PERIOD) return true;
		return false;
	}
	bool isComma(char c) {
		if (c == COMMA) return true;
		return false;
	}
	bool isColon(char c) {
		if (c == COLON) return true;
		return false;
	}

	void readBlanks() {
		while(this->isBlank(this->lookahead) && !fin.eof()) {
			fin.get(this->lookahead);
		}
	}
	string readDigits() {
		string token;
		while (this->isDigit(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readPeriod() {
		string token;
		if (this->isPeriod(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readComma() {
		string token;
		if (this->isComma(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readColon() {
		string token;
		if (this->isColon(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readChars() {
		string token;
		while(!this->isDelimeter(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readBeginToken() {
		string token;
		if (this->isBegin(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readEndToken() {
		string token;
		if (this->isEnd(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readIndexBeginToken() {
		string token;
		if (this->isIndexBegin(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readIndexEndToken() {
		string token;
		if (this->isIndexEnd(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}

	void tabIndentation() {
		this->tabs.push_back(TAB);
	}
	void untabIndentation() {
		this->tabs.erase(0, 1);
	}

	string getFullName(string path, string objectName) {
		string fullName;
		fullName.append(path);
		fullName.append(PATHSEPARATOR);
		fullName.append(objectName);
		fullName.append(EXTENSION);
		return fullName;
	}

public:
	Lex(): lookahead(BLANKS[0]) {}
	virtual ~Lex() {}

	void openIn(string path, string fileName) throw() {
		string fullName = this->getFullName(path, fileName);

		this->fin.open(fullName.c_str());
		if (!this->fin.is_open())
			throw Exception(LEX_H_, "openIn", fullName);
	}
	bool eof() { return fin.eof(); }
	void closeIn() {
		this->fin.close();
	}

	string readBegin() {
		string token;
		this->readBlanks();
		token = this->readBeginToken();
		return token;
	}
	string readEnd() {
		string token;
		this->readBlanks();
		token = this->readEndToken();
		return token;
	}
	string readIndexBegin() {
		string token;
		this->readBlanks();
		token = this->readIndexBeginToken();
		return token;
	}
	string readIndexEnd() {
		string token;
		this->readBlanks();
		token = this->readIndexEndToken();
		return token;
	}

	string readInt() {
		string token;
		this->readBlanks();
		token = this->readDigits();
		return token;
	}
	string readFloat() {
		string token;
		this->readBlanks();
		token.append(this->readDigits());
		token.append(this->readPeriod());
		token.append(this->readDigits());
		return token;
	}
	string readKey() {
		string token;
		this->readBlanks();
		token = this->readChars();
		this->readBlanks();
		this->readColon();
		return token;
	}
	string readString() {
		string token;
		this->readBlanks();
		token = this->readChars();
		return token;
	}

	void openOut(string path, string fileName) throw() {
		string fullName = this->getFullName(path, fileName);

		this->fout.open(fullName.c_str());
		if (!this->fout.is_open())
			throw Exception(LEX_H_, "openOut", fullName);
		this->tabs.clear();
	}
	void closeOut() {
		this->fout.close();
	}

	void writeBegin() {
		fout << BEGIN << NEWLINE;
		tabIndentation();
	}
	void writeEnd() {
		untabIndentation();
		fout << this->tabs << END << NEWLINE;
	}
	void writeIndexBegin() {
		fout << INDEXBEGIN;
	}
	void writeIndexEnd() {
		fout << INDEXEND;
	}

	void writeKey(string token) {
		fout << this->tabs << token << COLON;
	}
	void writeValue(string token) {
		fout << SPACE << token << NEWLINE;
	}
	void writeSpace() {
		fout << SPACE;
	}
	void writeTab() {
		fout << this->tabs;
	}
	void writeEndl() {
		fout << NEWLINE;
	}
};

#endif /* LEX_H_ */

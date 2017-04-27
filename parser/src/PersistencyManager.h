/*
 * Main.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef PERSISTENCYMANAGER_H_
#define PERSISTENCYMANAGER_H_

#include "Parser.h"
#include "VideoManager.h"
class PersistencyManager {
private:
	Parser parser;

	VideoManager videoManager1;
	VideoManager videoManager2;
	VideoManager videoManager3;

public:
	void read() {
		try {
			parser.openIn("rsc", "input");
			// read file and build parse tree
			parser.read();
			// load data to a class
			parser.load(videoManager1, "videoManager1");
//			parser.load(videoManager3, "videoManager3");
//			parser.load(videoManager2, "videoManager2");
			parser.closeIn();
		} catch (Exception& e) {
			e.what();
		}
	}
	void write() {
		try {
			parser.openOut("rsc", "output");
			// load data to the parser
//			parser.store(videoManager3, "videoManager3");
//			parser.store(videoManager2, "videoManager2");
			parser.store(videoManager1, "videoManager1");
			// write to the file
			parser.write();
			parser.closeOut();
	} catch (Exception& e) {
			e.what();
		}
	}
};



#endif /* PERSISTENCYMANAGER_H_ */

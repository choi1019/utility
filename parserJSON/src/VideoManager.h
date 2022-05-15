/*
 * VideoManager.h
 *
 *  Created on: 2017. 3. 31.
 *      Author: choi.sungwoon
 */

#ifndef VIDEOMANAGER_H_
#define VIDEOMANAGER_H_

#include "Parser.h"

/*
class VideoProfile: public Serializable {
private:
	int att3;
	float att4;
	string att5;
	int a [2];
public:
	VideoProfile() {
		// default
		this->register(this->att3, "att30");
		this->register(this->att4, "att40");
		this->register(this->a, 2, "a");
		this->register(this->att5, "att50");

	}
	virtual ~VideoProfile() {}

};

class VideoManager: public Serializable {
private:
	int att1;
	VideoProfile videoProfile[2];
	float att2;
	int array[2];

public:
	VideoManager() {
		this->register(this->array, 2, "arrayA");
		this->register(this->att1, "att10");
		this->register(this->videoProfile, 2, "videoProfile");
		this->register(this->att2, "att20");
	}
	virtual ~VideoManager() {}
};

*/

int main() {
	try {
		Parser parser;
		parser.parse("rsc", "input");
	}
	catch (Exception& e) {
		e.what();
	}

}
#endif /* VIDEOMANAGER_H_ */

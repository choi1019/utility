/*
 * VideoManager.h
 *
 *  Created on: 2017. 3. 31.
 *      Author: choi.sungwoon
 */

#ifndef VIDEOMANAGER_H_
#define VIDEOMANAGER_H_

#include "Serializable.h"

class VideoProfile: public Serializable {
private:
	int att3;
	float att4;
	string att5;
	int a [2];
public:
	VideoProfile() {
		// default
		this->att3 = 5;
		this->att4 = 2.3;

		this->a[0] = 88;
		this->a[1] = 99;
	}
	virtual ~VideoProfile() {}

	void write() {
		this->set(this->att3, "att30");
		this->set(this->att4, "att40");
		this->set(this->a, 2, "a");
		this->set(this->att5, "att50");
	}
	void read() {
		this->get(this->att3, "att30");
		this->get(this->att4, "att40");
		this->get(this->att5, "att50");
		this->get(this->a, 2, "a");

	}
};

class VideoManager: public Serializable {
private:
	int att1;
	VideoProfile videoProfile[2];
	float att2;
	int array[2];

public:
	VideoManager() {
		this->att1 = 5;
		this->att2 = 2.3;

		this->array[0] = 333;
		this->array[1] = 444;
	}
	virtual ~VideoManager() {}

	void read() {
		this->get(this->array, 2, "arrayA");
		this->get(this->att1, "att10");
		this->get(this->videoProfile, 2, "videoProfile");
		this->get(this->att2, "att20");
	}
	void write() {
		this->set(this->att1, "att10");
		this->set(this->videoProfile, 2, "videoProfile");
		this->set(this->att2, "att20");
		this->set(this->array, 2, "arrayA");
	}
};


#endif /* VIDEOMANAGER_H_ */

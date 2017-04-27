/*
 * Main.h
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "Controller.h"
#include "TrafficLight.h"

class Main {
private:
	Controller controller;
	TrafficLight trafficLight;
public:
	Main();
	virtual ~Main();
	void Initialize();

	void Run();
};

#endif /* MAIN_H_ */

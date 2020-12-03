/*
 * Controller.cpp
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#include "Controller.h"

Controller::Controller() {
	// TODO Auto-generated constructor stub

}

Controller::~Controller() {
	// TODO Auto-generated destructor stub
}

EControllerEvent Controller::GenerateEvent() {
	return E_CONTROLLER_TIMEOUT;
}

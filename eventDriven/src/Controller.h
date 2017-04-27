/*
 * Controller.h
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum EControllerEvent { E_CONTROLLER_TIMEOUT };

class Controller {
private:
//	EControllerEvent eControllerEvent;
public:
	Controller();
	virtual ~Controller();
	void Initialize() {};

	EControllerEvent GenerateEvent();
};

#endif /* CONTROLLER_H_ */

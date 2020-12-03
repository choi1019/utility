/*
 * TrafficLight.h
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include "Controller.h"

enum ETrafficLightState {
	E_TRAFFICLIGHT_SNS,
	E_TRAFFICLIGHT_SNL,
	E_TRAFFICLIGHT_EWS,
	E_TRAFFICLIGHT_EWL
};

class TrafficLight {
protected:
	ETrafficLightState eTrafficLightState;
	virtual void ChangeLightSNS();
	virtual void ChangeLightSNL();
	virtual void ChangeLightEWS();
	virtual void ChangeLightEWL();
	virtual void TimeOut();
public:
	TrafficLight();
	virtual ~TrafficLight();
	virtual void Initalize();

	virtual void ProcessEvent(EControllerEvent eControllerEvent);
};

#endif /* TRAFFICLIGHT_H_ */

/*
 * TrafficLightState.h
 *
 *  Created on: 2017. 2. 14.
 *      Author: Sungwoon Choi
 */

#ifndef TRAFFICLIGHTSTATE_H_
#define TRAFFICLIGHTSTATE_H_

#include "TrafficLight.h"

class TrafficLightState: public TrafficLight {
public:
	TrafficLightState();
	virtual ~TrafficLightState();
	virtual void Initalize();

	virtual void ProcessEvent(EControllerEvent eControllerEvent);

	void SelectState();
	void SNSState(EControllerEvent eControllerEvent);
	void SNLState(EControllerEvent eControllerEvent);
	void EWSState(EControllerEvent eControllerEvent);
	void EWLState(EControllerEvent eControllerEvent);

	virtual void ChangeLightSNS();
	virtual void ChangeLightSNL();
	virtual void ChangeLightEWS();
	virtual void ChangeLightEWL();
	virtual void TimeOut();};

#endif /* TRAFFICLIGHTSTATE_H_ */

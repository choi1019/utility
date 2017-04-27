/*
 * TrafficLight.cpp
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#include "TrafficLight.h"
#include <iostream>
using namespace std;

TrafficLight::TrafficLight() {
	this->eTrafficLightState = E_TRAFFICLIGHT_SNS;
}

TrafficLight::~TrafficLight() {
}

void TrafficLight::Initalize() {
	this->eTrafficLightState = E_TRAFFICLIGHT_SNS;
	this->ChangeLightSNS();
}

void TrafficLight::ChangeLightSNS() {
	cout<< "ChangeLightSNS" << endl;
}
void TrafficLight::ChangeLightSNL() {
	cout<< "ChangeLightSNL" << endl;
}
void TrafficLight::ChangeLightEWS() {
	cout<< "ChangeLightEWS" << endl;
}
void TrafficLight::ChangeLightEWL() {
	cout<< "ChangeLightEWL" << endl;
}

void TrafficLight::TimeOut() {
	bool bSensorSNL = true;
	bool bSensorEWL = true;

	switch(this->eTrafficLightState) {
	case E_TRAFFICLIGHT_SNS:
		if (bSensorSNL) {
			ChangeLightSNL();
			this->eTrafficLightState = E_TRAFFICLIGHT_SNL;
		} else {
			ChangeLightEWS();
			this->eTrafficLightState = E_TRAFFICLIGHT_EWS;
		}
		break;
	case E_TRAFFICLIGHT_SNL:
		ChangeLightEWS();
		this->eTrafficLightState = E_TRAFFICLIGHT_EWS;
		break;
	case E_TRAFFICLIGHT_EWS:
		if (bSensorEWL) {
			ChangeLightEWL();
			this->eTrafficLightState = E_TRAFFICLIGHT_EWL;
		} else {
			ChangeLightSNS();
			this->eTrafficLightState = E_TRAFFICLIGHT_SNS;
		}
		break;
	case E_TRAFFICLIGHT_EWL:
		ChangeLightSNS();
		this->eTrafficLightState = E_TRAFFICLIGHT_SNS;
		break;
	default:
		break;
	}
}

void TrafficLight::ProcessEvent(EControllerEvent eControllerEvent) {
	switch (eControllerEvent) {
	case E_CONTROLLER_TIMEOUT:
		TimeOut();
		break;
	default:
		break;
	}
}

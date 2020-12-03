/*
 * TrafficLightState.cpp
 *
 *  Created on: 2017. 2. 14.
 *      Author: Sungwoon Choi
 */

#include <iostream>
using namespace std;

#include "TrafficLightState.h"

TrafficLightState::TrafficLightState() {
}

TrafficLightState::~TrafficLightState() {
}

void TrafficLightState::Initalize() {
	this->eTrafficLightState = E_TRAFFICLIGHT_SNS;
	this->ChangeLightSNS();
}

void TrafficLightState::ChangeLightSNS() {
	cout<< "ChangeLightSNS" << endl;
}
void TrafficLightState::ChangeLightSNL() {
	cout<< "ChangeLightSNL" << endl;
}
void TrafficLightState::ChangeLightEWS() {
	cout<< "ChangeLightEWS" << endl;
}
void TrafficLightState::ChangeLightEWL() {
	cout<< "ChangeLightEWL" << endl;
}

void TrafficLightState::SelectState() {
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

void TrafficLightState::SNSState(EControllerEvent eControllerEvent) {
	switch (eControllerEvent) {
	case E_CONTROLLER_TIMEOUT:
		TimeOut();
		break;
	default:
		break;
	}
}

void TrafficLightState::SNLState(EControllerEvent eControllerEvent) {
	switch (eControllerEvent) {
	case E_CONTROLLER_TIMEOUT:
		TimeOut();
		break;
	default:
		break;
	}
}

void TrafficLightState::EWSState(EControllerEvent eControllerEvent) {
	switch (eControllerEvent) {
	case E_CONTROLLER_TIMEOUT:
		TimeOut();
		break;
	default:
		break;
	}
}

void TrafficLightState::EWLState(EControllerEvent eControllerEvent) {
	switch (eControllerEvent) {
	case E_CONTROLLER_TIMEOUT:
		TimeOut();
		break;
	default:
		break;
	}
}


void TrafficLightState::ProcessEvent(EControllerEvent eControllerEvent) {
	switch(this->eTrafficLightState) {
	case E_TRAFFICLIGHT_SNS:
		SNSState(eControllerEvent);
		break;
	case E_TRAFFICLIGHT_SNL:
		SNLState(eControllerEvent);
		break;
	case E_TRAFFICLIGHT_EWS:
		EWSState(eControllerEvent);
		break;
	case E_TRAFFICLIGHT_EWL:
		EWLState(eControllerEvent);
		break;
	default:
		break;
	}
}

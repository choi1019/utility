/*
 * Main.cpp
 *
 *  Created on: 2017. 2. 9.
 *      Author: Sungwoon Choi
 */

#include "Main.h"


Main::Main() {
}

Main::~Main() {
}

void Main::Initialize() {
	this->controller.Initialize();
	this->trafficLight.Initalize();

//	this->trafficLight.setEventSource(&(this->controller));
}

void Main::Run() {
	for (int i=0; i<10; i++) {
		EControllerEvent eControllerEvent = controller.GenerateEvent();
		trafficLight.ProcessEvent(eControllerEvent);
	}
}

int main() {
	Main main;
	main.Initialize();
	main.Run();
}

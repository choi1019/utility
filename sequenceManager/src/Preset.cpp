/*
 * Preset.cpp
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#include "Preset.h"

static int gid = 0;

Preset::Preset() {
	this->id = gid++;
	this->name = 0;

	this->eState = eIDLE;

	this->pan = 0;
	this->tilt = 0;
	this->zoom = 0;

	this->presetIndex = NONE;
	this->afterActionIndex = NONE;

	cout << "SequencePosition::SequencePosition-" << this->getId() << endl;

}

Preset::~Preset() {
}

void Preset::initialize() {

}

ESequenceState Preset::program() {
	cout << "    SequencePosition::program()" << this->getId() << endl;

	this->pan = 0;
	this->tilt = 0;
	this->zoom = 0;

	this->presetIndex = NONE;
	this->afterActionIndex = NONE;

	this->eState = ePROGRAMMED;


	return this->eState;
}

ESequenceState Preset::start() {
	cout << "    SequencePosition::start()" << this->getId() << endl;
	this->eState = eSTARTED;
	return this->eState;
}

ESequenceState Preset::prepare() {
	cout << "    SequencePosition::prepare()" << this->getId() << endl;
	this->eState = ePREPARED;
	if (this->presetIndex == NONE) return this->eState;
	this->setupCamera();
	return this->eState;
}

ESequenceState Preset::execute() {
	cout << "    SequencePosition::execute()" << this->getId() << endl;
	this->eState = eEXECUTED;
	// move to position -> PTZF
	this->move();
	return this->eState;
}

ESequenceState Preset::finalize() {
	cout << "    SequencePosition::finalize()" << this->getId() << endl;
	this->eState = eFINALIZED;
	if (this->afterActionIndex == NONE) return this->eState;
	// do after-action
	this->afterAct();
	return this->eState;
}

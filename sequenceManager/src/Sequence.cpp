/*
 * CompositePreset.cpp
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#include "Sequence.h"

Sequence::Sequence() {
	this->eSubState = eIDLE;
	this->presetIndex = NONE;
	this->afterActionIndex = NONE;

	this->eState = ePROGRAMMED;
}

Sequence::~Sequence() {
}

void Sequence::initialize() {
}

ESequenceState Sequence::program() {
	cout << "  Sequence::program()"  << this->getId() << endl;

	this->eState = ePROGRAMMED;
	return this->eState;
}

ESequenceState Sequence::start() {
	cout << "  Sequence::start()"  << this->getId() << endl;
	this->eState = eSTARTED;
	return this->eState;
}

ESequenceState Sequence::prepare() {
	cout << "  Sequence::prepare()"  << this->getId() << endl;
	this->sequenceItr = this->mapPreset.begin();
	this->eState = ePREPARED;
	this->eSubState = eFINALIZED;
	// action
	this->setupCamera();

	return this->eState;
}

ESequenceState Sequence::execute() {
	if (this->sequenceItr == this->mapPreset.end()) {
		this->eState = eEXECUTED;
		return this->eState;
	}

	cout << "  Sequence::execute()"  << this->getId() << endl;
	switch(this->eSubState) {
	case eFINALIZED:
		this->eSubState = this->sequenceItr->second->prepare();
		break;
	case ePREPARED:
		this->eSubState = this->sequenceItr->second->execute();
		break;
	case eEXECUTED:
		this->eSubState = this->sequenceItr->second->finalize();
		this->sequenceItr++;
		break;
	default:
		break;
	}
	return this->eState;
}

ESequenceState Sequence::finalize() {
	cout << "  Sequence::finalize()"  << this->getId() << endl;
	// action
	this->afterAct();
	this->eState = eFINALIZED;
	return this->eState;
}

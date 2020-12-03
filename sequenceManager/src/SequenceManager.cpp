/*
 * Main.cpp
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#include "SequenceManager.h"


SequenceManager::SequenceManager() {
	this->pCurrentPreset = NULL;
	this->isStateChanged = false;
}

SequenceManager::~SequenceManager() {
}

void SequenceManager::initialize() {
}

void SequenceManager::processEvent(ESequenceEvent evEvent) {
	cout << "****::processEvent()" << endl;

	this->isStateChanged = true;

	switch(evEvent) {
	case evPROGRAM:
		this->eState = this->program();
		break;
	case evSTART:
		this->eState = this->start();
		break;
	case evPREPARE:
		this->eState = this->prepare();
		break;
	case evEXECUTE:
		this->eState = this->execute();
		break;
	case evFINALIZE:
		this->eState = this->finalize();
		break;
	default:
		this->isStateChanged = false;
		break;
	}
}

ESequenceEvent SequenceManager::setEvent() {
	cout << "****::setEvent()" << endl;

	if (!this->isStateChanged) return evNONE;

	ESequenceEvent eEvent;
	switch(eState) {
	case eSTARTED:
		eEvent = evPREPARE;
		break;
	case ePREPARED:
		eEvent = evEXECUTE;
		break;
	case eEXECUTED:
		eEvent = evFINALIZE;
		break;
	case eFINALIZED:
		eEvent = evIDLE;
		break;
	default:
		break;
	}
	return eEvent;
}

ESequenceState SequenceManager::program() {
	cout << " Main::program()" << endl;
	Sequence* pTour;
	Sequence* pGroup;
	Preset* pPreset;

	// position 1
	pTour = new Sequence();
	this->insert(pTour);

	// position 1-1(2)
	pGroup = new Sequence();
	pTour->insert(pGroup);

	// position 1-1-1(3)
	pPreset = new Preset();
	pGroup->insert(pPreset);

	// position 1-1-2(4)
	pPreset = new Preset();
	pGroup->insert(pPreset);

	// sequence 1-2(5)
	pGroup = new Sequence();
	pTour->insert(pGroup);

	// position 1-2-1(6)
	pPreset = new Preset();
	pGroup->insert(pPreset);

	// position 1-2-2(7)
	pPreset = new Preset();
	pGroup->insert(pPreset);

	pGroup->setId(9);
	pTour->insert(pGroup);


	this->eState = ePROGRAMMED;
	return this->eState;
}

ESequenceState SequenceManager::start() {
	cout << " Main::start()" << endl;
	Preset *pSequencePosition = this->find(1);
	if (pSequencePosition == NULL) return eIDLE;

	this->pCurrentPreset = pSequencePosition;

	this->pCurrentPreset->start();
	this->eState = eSTARTED;
	return this->eState;
}

ESequenceState SequenceManager::prepare() {
	cout << " Main::prepare()" << endl;
	// find current preset;
	this->eState = this->pCurrentPreset->prepare();
	return this->eState;
}

ESequenceState SequenceManager::execute() {
	cout << " Main::execute()" << endl;
	this->eState = this->pCurrentPreset->execute();
	return this->eState;
}

ESequenceState SequenceManager::finalize() {
	cout << " Main::finalize()" << endl;
	this->eState = this->pCurrentPreset->finalize();
	return this->eState;
}

int main() {
	SequenceManager sequenceManager;
	ESequenceEvent evEvent;

	evEvent = evPROGRAM;
	sequenceManager.processEvent(evEvent);

	evEvent = evSTART;
	while(evEvent != evIDLE) {
		sequenceManager.processEvent(evEvent);
		evEvent = sequenceManager.setEvent();
	}
}

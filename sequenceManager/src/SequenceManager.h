/*
 * Main.h
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#ifndef SEQUENCEMANAGER_H_
#define SEQUENCEMANAGER_H_

#include "Sequence.h"

enum ESequenceEvent {evNONE, evIDLE, evPROGRAM, evSTART, evPREPARE, evEXECUTE, evFINALIZE};

class SequenceManager: public Sequence {
public:
	SequenceManager();
	virtual ~SequenceManager();
	void initialize();

	void processEvent(ESequenceEvent evEvent);
	ESequenceEvent setEvent();

protected:
	virtual ESequenceState program();

	virtual ESequenceState start();
	virtual ESequenceState prepare();
	virtual ESequenceState execute();
	virtual ESequenceState finalize();
private:
	Preset* pCurrentPreset;
	bool isStateChanged;
};

#endif /* SEQUENCEMANAGER_H_ */

/*
 * CompositePreset.h
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <map>

#include "Preset.h"
using namespace std;

class Sequence: public Preset {
public:
	Sequence();
	virtual ~Sequence();
	virtual void initialize();

	void insert(Preset *pPreset) {
		this->mapPreset.insert(make_pair(pPreset->getId(), pPreset));
	}
	Preset *find(int id) {
		map<int, Preset *>::iterator itr = this->mapPreset.find(id);
		if (itr == this->mapPreset.end()) return NULL;
		return itr->second;
	}

	virtual void setupCamera() {};
	virtual void afterAct() {};

protected:
	ESequenceState eState, eSubState;

	map<int, Preset *> mapPreset;
	map<int, Preset *>::iterator sequenceItr;

	virtual ESequenceState program();
	virtual ESequenceState start();
	virtual ESequenceState prepare();
	virtual ESequenceState execute();
	virtual ESequenceState finalize();

};

#endif /* SEQUENCE_H_ */

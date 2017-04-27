/*
 * Preset.h
 *
 *  Created on: 2017. 2. 13.
 *      Author: Sungwoon Choi
 */

#ifndef PRESET_H_
#define PRESET_H_

#include <iostream>
using namespace std;

#define NONE -1
enum ESequenceState {ePROGRAMMED, eIDLE, eSTARTED, ePREPARED, eEXECUTED, eFINALIZED};

class Preset {
private:
	// Position
	int pan;
	int tilt;
	int zoom;

protected:
	int id;
	char *name;
	ESequenceState eState;

	// precondition (optional)
	int presetIndex;
	// postcondition (optional)
	int afterActionIndex;

	virtual void setupCamera() {};
	virtual void move() {};
	virtual void afterAct() {};

public:
	Preset();
	virtual ~Preset();
	virtual void initialize();

	virtual ESequenceState program();
	virtual ESequenceState start();
	virtual ESequenceState prepare();
	virtual ESequenceState execute();
	virtual ESequenceState finalize();

	int getId() const {	return id;	}
	void setId(int id) { this->id = id;	}
	char* getName() const {	return name; }
	void setName(char* name) { this->name = name; }
};

#endif /* PRESET_H_ */

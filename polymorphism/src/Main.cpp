/*
 * Main.cpp
 *
 *  Created on: 2017. 2. 17.
 *      Author: Sungwoon Choi
 */

#include "Main.h"
#include "Super.h"
#include "Sub.h"

Main::Main() {
}

Main::~Main() {
}

void Main::Run() {
	Super super;
	super.Print();

	Sub sub;
	sub.Print();

	super = sub;
	super.Print();

	Super *pSuper;
	pSuper = &sub;
	pSuper->Print();

}

int main() {
	Main main;
	main.Run();
}

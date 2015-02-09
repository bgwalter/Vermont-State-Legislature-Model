#include <iostream>

#include "Object.h"
#include "Agent.h"	// includes Bill.h and Outside.h

#define MEMBERS 5

using namespace std;

int main(void) {
	Bill bill;
	Outside witness;
	Agent committee[MEMBERS];
	committee[0].setMmbr(0.2, 0.3, 'R');
	committee[1].setMmbr(0.3, 0.25, 'R');
	committee[2].setMmbr(-0.5, 0.3, 'D');
	committee[3].setMmbr(-0.1, 0.1, 'D');
	committee[4].setMmbr(0, 0.5, 'D');

	bill.setBill(0.2);

	committee[0].interact(&committee[1]);

	witness.setWitness(-0.15);
	witness.printWitness();
}

#include <iostream>

#include "Object.h"
#include "Agent.h"

#define MEMBERS 5

using namespace std;

int main(void) {
	Bill bill;
	Agent mmbrs[MEMBERS];
	mmbrs[0].setMmbr(0.2, 0.3, 'R');
	mmbrs[1].setMmbr(0.3, 0.25, 'R');
	mmbrs[2].setMmbr(-0.5, 0.3, 'D');
	mmbrs[3].setMmbr(-0.1, 0.1, 'D');
	mmbrs[4].setMmbr(0, 0.5, 'D');

	bill.setBill(0.2);

	mmbrs[0].interact(&mmbrs[1]);

	mmbrs[0].printMmbr();
	mmbrs[1].printMmbr();
}

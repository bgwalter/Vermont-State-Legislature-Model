/*
	Bill.h
	2014 December 3
	Brendon Walter (bwalter@bennington.edu)

	Header file for Bill class

*/

#define NUMMEMBERS 10

class Bill : public Object {
	protected:
		int influenceHistory[NUMMEMBERS][2];
};

/*
	Agent.h
	2014 December 4
	Brendon Walter (bwalter@bennington.edu)

	Header file for Agent class

	Agents are each member of the committee and are derived from the Object class. 

	USAGE:

	Agent mmbr;						// declare a new Agent called mmbr
	mmbr.setMmbr(-0.2, 0.3, 'D');	// set opinion, uncertainty, and part of mmbr
	mmbr.printMmbr();				// prints values of mmbr

	// set float and char values for each of mmbr's attributes
	float opinion, uncertainty, opinionSegment[2];
	char pparty;	
	// give the addresses of each value to getMmbr for use as output parameters
	mmbr.getMmbr(&opinion, &uncertainty, opinionSegment, &pparty);
*/

class Agent: public Object {

	protected:
		char party;		// political party
//		char* friends[NUMMEMBERS][NUMMEMBERS];

	public:

		/*
			Parameters: opinion, uncertainty, and party values of a new agent
			Returns: 1 if success, 0 if invalid input
			Sets the initial values for an agent
		*/
		int setMmbr(float opinion, float uncertainty, char pparty); 

		/*
			Parameters: Address of values to hold each attribute of the agent
				Output: Value of each attribute of the agent
			Returns: None
			Returns agent's value as output parameters
		*/
		void getMmbr(float* opinion, float* uncertainty, float opinionSegment[], 
					char* pparty); 

		/*
			Parameters: None
			Returns: None
			Prints out each attribute of the agent
		*/
		void printMmbr(void); 
};

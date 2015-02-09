/*
	Agent.h
	2014 December 4
	Brendon Walter (bwalter@bennington.edu)

	Header file for Agent class

	Agents are each member of the committee and are derived from the Object 
	class. 

	USAGE:

	// declare a new Agent called mmbr
	Agent mmbr;				
	// set opinion, uncertainty, and part of mmbr		
	mmbr.setMmbr(-0.2, 0.3, 'D');	
	// prints values of mmbr
	mmbr.printMmbr();				

	// set float and char values for each of mmbr's attributes
	float opinion, uncertainty, opinionSegment[2];
	char pparty;	
	// give the addresses of each value to getMmbr for use as output parameters
	mmbr.getMmbr(&opinion, &uncertainty, opinionSegment, &pparty);
*/

#include "Bill.h"
#include "Outside.h"

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
		
		/*
			Parameters: Bill object to form opinion on
			Return: float indicating how the agent feels about the bill
			Form an opinion on a given bill
		*/
		float formOpn(Bill bill);

		/*
			Parameters: Address of interacting Agent
			Returns: 1 if opinions changed, 0 if they did not influence each other
			Interact with another agent. If their opinion segments overlap, they will 
			influence one another towards a more middle ground
		*/
		int interact(Agent *member);

		/*
			Parameters: Witness talking to the committee
			Returns: 1 if opinion changed, 0 if witness did not influence agent
			Talk to a witness on a certain issue
		*/
		int talkToWitness(Outside witness);
};

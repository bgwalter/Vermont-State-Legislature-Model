/*
	Agent.cpp
	2014 December 4
	Brendon Walter (bwalter@bennington.edu)

	Methods for Agent class
*/

#include <iostream>
#include <cmath>

#include "Object.h"
#include "Agent.h"

using namespace std;

/*
	Parameters: opinion, uncertainty, and party values of a new agent
	Returns: 1 if success, 0 if invalid input
	Sets the initial values for an agent
*/
int Agent::setMmbr(float opinion, float uncertainty, char pparty) {
	
	// call function from Object class
	setOpns(opinion, uncertainty);

	// check validity of parameters
	if (pparty == 'D' || pparty == 'd' ||	// democrat
		pparty == 'R' || pparty == 'r' ||	// republican
		pparty == 'P' || pparty == 'p')	{	// progressive
		
		party = pparty;
		return 1;
	}
	cout << "Party can only be D/d, R/r, or P/p.\n";
	return 0;	
}

/*
	Parameters: Address of values to hold each attribute of the agent
		Output: Value of each attribute of the agent
	Returns: None
	Returns agent's value as output parameters
*/
void Agent::getMmbr(float* opinion, float* uncertainty, float opinionSegment[], 
			char* pparty) {
	getOpns(opinion, uncertainty, opinionSegment);	// fctn from Object class
	*pparty = party;
}

/*
	Parameters: None
	Returns: None
	Prints out each attribute of the agent
*/
void Agent::printMmbr(void) {
	printOpns();		// function called from Object class
	cout << "Party: " << party << endl;	
}

/*
	Parameters: Bill object to form opinion on
	Return: float indicating how the agent feels about the bill
	Form an opinion on a given bill
*/
float Agent::formOpn(Bill bill) {
	/*
		The functions to determine how an agent feels about a bill is a simple
		absolute value function. An output of 1 indicates that the position of 
		the bill is the same as the agent's opinion.
		
		Any value greater than 0 indicates the the agent is favorable of the 
		bill. 
		
		A value of 0 indicates that the position of the bill is at the edge of
		the agent's opinion segment
		
		A negative value indicates that the bill is outside of the agent's 
		opinion segment, and thus feels negatively about the bill.
	*/

	// get position of bill
	float billOpn;
	bill.getBill(&billOpn);

	return (1 - abs(billOpn - opn) / uncrtn);
}

/*
	Parameters: Address of interacting Agent
	Returns: 1 if opinions changed, 0 if they did not influence each other
	Interact with another agent. If their opinion segments overlap, they will 
	influence one another towards a more middle ground
*/
int Agent::interact(Agent *member) {

	int returnValue = 0;

	// check to make sure the opinion segments of the two members overlap
	if (opnSeg[0] < member->opnSeg[1] || opnSeg[1] > member->opnSeg[0]) {
		// agents interact and pull eachother closer to agreement
		opn += uncrtn * (member->opn - opn);
		member->opn += member->uncrtn * (opn - member->opn);

		// interaction occured, increment returnValue to be 1
		returnValue++;
	}

	/* 
		TODO introduce 'hardening' of member's opinions by decreasing 
		members' uncertainty. Refer to Meet, Discuss, and Segregate! 
		(Weisbuch et. al., 2002), equations 3 through 6
	*/

	// update opinion segments to reflect the change in new opinion
	setOpns(opn, uncrtn);
	member->setOpns(member->opn, member->uncrtn);

	// return either 0 or 1
	return returnValue;
}

/*
	Parameters: Witness talking to the committee
	Returns: 1 if opinion changed, 0 if witness did not influence agent
	Talk to a witness on a certain issue
*/
int Agent::talkToWitness(Outside witness) {

	// get values from witness
	float witnessOpn, witnessOpnSeg[2];
	witness.getWitness(&witnessOpn, witnessOpnSeg);

	int returnValue = 0;

	// check to make sure the opinion segments of the two members overlap
	if (opnSeg[0] < witnessOpnSeg[1] || opnSeg[1] > witnessOpnSeg[0]) {
		// witness pulls agents towards their opinion
		opn += uncrtn * (witnessOpn - opn);

		// interaction occured, increment returnValue to be 1
		returnValue++;
	}

	/* 
		TODO introduce 'hardening' of member's opinions by decreasing 
		members' uncertainty. Refer to Meet, Discuss, and Segregate! 
		(Weisbuch et. al., 2002), equations 3 through 6
	*/

	// update agent's opinion segment to reflect the change in new opinion
	setOpns(opn, uncrtn);

	// return either 0 or 1
	return returnValue;

}

/*
	Bill.h
	2014 December 3
	Brendon Walter (bwalter@bennington.edu)

	Header file for Bill class

*/

class Bill: public Object {
	protected:
//		int influenceHistory[NUMMEMBERS][2];

	public:
	
		/*
			Parameters: opinion
			Returns: 1 if success, 0 if invalid input
			Sets the initial values for an agent
		*/
		int setBill(float opinion);
		
		/*
			Parameters: Address of values to hold each attribute of the agent
				Output: Value of each attribute of the agent
			Returns: None
			Returns agent's value as output parameters
		*/
		void getBill(float* opinion);
		
	
		/*
			Parameters: None
			Returns: None
			Prints out position of bill
		*/
		void printBill(void);
};

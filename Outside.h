/*
	Outside.h
	2015 Feb 8
	Brendon Walter (bwalter@bennington.edu)

	Header file for outside influences (witnesses, media, constiuency) class
*/

class Outside: public Object {
	protected:


	public:
	
		/*
			Parameters: opinion of new witness
			Returns: 1 if success, 0 if failure
			Creates a new witness
		*/
		int setWitness(float opinion);

		/*
			Parameters: address of value to hold witness' opinion and opinion
				segment to hold witness' value for each
				Output: witness' opinion and opinion segment
			Returns: None
			Get information of a witness using output paramters
		*/
		void getWitness(float* opinion, float opinionSegment[]);

		/*
			Parameters: None
			Returns: None
			Prints the witness' values
		*/
		void printWitness(void);
};

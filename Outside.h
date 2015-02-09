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
			Returns: None
			Creates a new witness
		*/
		void setWitness(float opinion);

		/*
			Parameters: address of value to hold witness' opinion
				Output: witness' opinion
			Returns: None
			Get information of a witness using output paramters
		*/
		void getWitness(float* opinion);

		/*
			Parameters: None
			Returns: None
			Prints the witness' values
		*/
		void printWitness(void);
};

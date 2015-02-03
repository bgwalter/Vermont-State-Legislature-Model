/*
	Object.h
	2014 December 3
	Brendon Walter (bwalter@bennington.edu)

	Header file for Object class

	The Object class is the class from which every other object/agent in the 
	model is derived.  An Object has three values: an opinion, an uncertainty 
	value, and an opinion segment. Only the opinion and uncertainty can be set, 
	and from those two values, the opinion segment is calculated.

	Opinion can be a value from between -1 and 1
	Uncertainty is a value between 0 and 1
	Opinion Segment is calculated as ranging from the opinion minus uncertainty 
	to opinion plus uncertainty

	USAGE:
	
	// create a new Object called obj
	Object obj;				
	// set opinion and uncertainty of obj
	obj.setOpns(0.2, 0.3);	
	// prints out each value of the object
	obj.printOpns();		

	// define float values to hold each of the Object's values
	float opinion, uncertainty, opinionSeg[2];
	// pass the address of each of the above values to set them
	obj.getOpns(&opinion, &uncertainty, opinionSeg);	
	
*/

class Object {

	protected:	

		float opn;			// opinion
		float uncrtn;		// uncertainty
		float opnSeg[2];	// opinion segment

	public:

		/*
			Parameters: object's values for opinion and uncertainty about opinion
			Returns: 1 if success, 0 if input values are invalid
			Sets the inital values for each object 
		*/
 		int setOpns(float opinion, float uncertainty); 

		/*
			Parameters: Pointer to each of the object's values
				Output: Each of the object's values as stored in the class
			Returns: None
			Returns each of the object's values as output parameters
		*/
		void getOpns(float* opinion, float* uncertainty, 
					 float opinionSegment[]); 

		/*
			Parameters: None
			Returns: None
			Prints out each of the object's values to the screen
		*/
		void printOpns(void); 
};

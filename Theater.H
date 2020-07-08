#ifndef THEATER_H
#define THEATER_H
#include "Mat.H"
#include "Proj.H"

// this class inharit Mat and its instances is a matrix.
class Theater : public Mat {
public:
	
	//* constructor name: Theater
	//* Description: the constructor of Theater
	//* Parameters: rows - number of rows of the theater
	//*				cols - number of columns of the theater
	//*				TheaterNum - number of theater
	//* return value: None
	Theater(int rows, int cols, int TheaterNum); 
	
	//* function name: getTheaterNum
	//* Description: This function return the theater number
	//* Parameters: Theater instance
	//* return value: theater number
	int getTheaterNum() const; 
	
	//* function name: Reset
	//* Description: This function resets a theater matrix to zeros, meaning no seats are taken
	//* Parameters: Theater instance
	//* return value: none
	void Reset(); 
protected:
	int TheaterNum_; 
};
#endif


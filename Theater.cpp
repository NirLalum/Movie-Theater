#include "Theater.H"


//* constructor name: Theater
//* Description: the constructor of Theater
//* Parameters: rows - number of rows of the theater
//*				cols - number of columns of the theater
//*				TheaterNum - number of theater
//* return value: None
Theater::Theater(int rows, int cols, int TheaterNum):Mat(rows,cols), TheaterNum_(TheaterNum) { }

//* function name: getTheaterNum
//* Description: This function return the theater number
//* Parameters: Theater instance
//* return value: theater number
int Theater::getTheaterNum() const {
	return TheaterNum_;
}

//* function name: Reset
//* Description: This function resets a theater matrix to zeros, meaning no seats are taken
//* Parameters: Theater instance
//* return value: none
void Theater::Reset() {
	int i = 1, j = 1, rows = 0, cols = 0;
	rows = getRowsNum();
	cols = getColumnsNum();
	for (j = 1; j <= cols; j++) {
		for (i = 1; i <= rows; i++)
		{
			setElement(i, j, FREE);
		}
	}
}

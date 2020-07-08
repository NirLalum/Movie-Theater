#ifndef MAT_H
#define MAT_H

class Mat {
public:

	//* constructor name: Mat
	//* Description: the constructor of Mat
	//* Parameters: rows - number of rows of the matrix
	//*				cols - number of cols of the matrix
	//* return value: None
	Mat(int rows, int cols); //constructor;
	
	//* function name: getRowsNum
	//* Description: This function returns the number of rows of the matrix
	//* Parameters: Mat instance
	//* return value: the number of rows of the matrix
	int getRowsNum() const;
	
	//* function name: getColsNum
	//* Description: This function returns the number of columns of the matrix
	//* Parameters: Mat instance
	//* return value: the number of columns of the matrix
	int getColumnsNum() const;
	
	//* function name: getElement
	//* Description: This function returns an elemnt from the matrix
	//* Parameters: Mat instance
	//*				row - row of the element
	//*				col - column of the element
	//* return value: required element
	int getElement(int row, int col) const;
	
	//* function name: setElement
	//* Description: This function sets an elemnt in the matrix
	//* Parameters: Mat instance
	//*				row - row of the element
	//*				col - column of the element
	//* return value: none
	void setElement(int row, int col, int elem);
	
	// the destructor of Mat
	~Mat();

protected:
	int rows_;
	int cols_;
	int* matrix_;
};



#endif
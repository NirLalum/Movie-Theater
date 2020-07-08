#include "Mat.H"

//* constructor name: Mat
//* Description: the constructor of Mat
//* Parameters: rows - number of rows of the matrix
//*				cols - number of cols of the matrix
//* return value: None
Mat::Mat(int rows, int cols) : cols_(cols), rows_(rows) {
	int i;
	int* arr;
	arr = new int[rows * cols];
	for (i = 0; i < rows * cols; i++) {
		arr[i] = 0;
	}


	matrix_ = arr;
}

//* function name: getRowsNum
//* Description: This function returns the number of rows of the matrix
//* Parameters: Mat instance
//* return value: the number of rows of the matrix
int Mat::getRowsNum() const {
	return rows_;
}

//* function name: getColsNum
//* Description: This function returns the number of columns of the matrix
//* Parameters: Mat instance
//* return value: the number of columns of the matrix
int Mat::getColumnsNum() const{
	return cols_;
}

//* function name: getElement
//* Description: This function returns an elemnt from the matrix
//* Parameters: Mat instance
//*				row - row of the element
//*				col - column of the element
//* return value: required element
int Mat::getElement(int row, int col) const{
	row--;
	col--;
	return matrix_[row * cols_ + col];
}

//* function name: setElement
//* Description: This function sets an elemnt in the matrix
//* Parameters: Mat instance
//*				row - row of the element
//*				col - column of the element
//* return value: none
void Mat::setElement(int row, int col, int elem) {
	row--;
	col--;
	matrix_[row * cols_ + col] = elem;
}

// the destructor of Mat
Mat::~Mat() {
	delete []matrix_;
}


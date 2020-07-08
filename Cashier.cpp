#include <string.h>
#include "Cashier.H"


//* constructor name: Cashier
//* Description: the constructor of cashier
//* Parameters: name - a pointer to the cashier's name
//*				salary - the cashier salary
//*             schedule - a pointer to an array of pointer that represents the weekly scedule of the cashier.
//*				profit_ - the profit of the cashier
//* return value: None
Cashier::Cashier(char* name, int salary, char** schedule) : Employee(name, salary, schedule) {
	Profit_ = 0;
}

//* function name: getTicketProfit
//* Description: This function returns the profit of the cashier
//* Parameters: the cashier instance
//* return value: the profit of the cashier
int Cashier::getTicketProfit() const {
	return Profit_;
}

//* function name: sellTickets
//* Description: This function sell tickes for a given movie for a given row and chair and clac the profit of the cashier
//* Parameters: the cashier instance
//*             pMovie - a pointer to a movie
//*			    pTheater - a pointer to a theater
//*				is_dubbed - a boolian that determines if the movie is dubbed or not.
//*				tickets_num - the number of tickets
//*				row = the row number
//*				rightmost_seat - the number of the right most chair in the requested line
//* return value: 0 if the transaction failed or the profit from the sale if succeded.
int Cashier::sellTickets(Movie* pMovie, Theater* pTheater, bool is_dubbed, int tickets_num, int row, int rightmost_seat) {
	if (!pMovie || !pTheater) return 0;
	//cheking theater num
	int j = 0;
	// check if the movie is also dubbed and if the movie is screened in the given theater
	if (is_dubbed) {
		DubbedMovie* pDMovie = (DubbedMovie*)(pMovie);
		if (!(pDMovie->getHebrewTheaterNum() == pTheater->getTheaterNum()) && !(pDMovie->getTheaterNum() == pTheater->getTheaterNum())) return 0;
		DubbedMovie* pMovie = pDMovie;
	}
	// check if the not dubbed movie is screened in the given theater
	else if (!(pMovie->getTheaterNum() == pTheater->getTheaterNum())) return 0;

	//checking seats
	if (row > pTheater->getRowsNum()) return 0;
	if ((rightmost_seat > pTheater->getColumnsNum()) || ((rightmost_seat + tickets_num - 1) > pTheater->getColumnsNum())) return 0;
	// check if seats are taken
	for (j = rightmost_seat; j < (rightmost_seat + tickets_num); j++) {
		if (pTheater->getElement(row, j)) return 0;
	}
	// allocate seats in the theater
	for (j = rightmost_seat; j < (rightmost_seat + tickets_num); j++)
	{
		pTheater->setElement(row, j, TAKEN);
	}
	Profit_ += tickets_num * pMovie->getTicketPrice();
	return tickets_num * pMovie->getTicketPrice();
}
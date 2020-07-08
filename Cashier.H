#include "Employee.H"
#include "Movie.H"
#include "Theater.H"
#include "DubbedMovie.H"

#ifndef CASHIER_H
#define CASHIER_H


class Cashier : public Employee {
public: 
	//* constructor name: Cashier
	//* Description: the constructor of cashier
	//* Parameters: name - a pointer to the cashier's name
	//*				salary - the cashier salary
	//*             schedule - a pointer to an array of pointer that represents the weekly scedule of the cashier.
	//*				profit_ - the profit of the cashier
	//* return value: None
	Cashier(char* name, int salary, char** schedule);

	//* function name: getTicketProfit
	//* Description: This function returns the profit of the cashier
	//* Parameters: the cashier instance
	//* return value: the profit of the cashier
	int getTicketProfit() const;

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
	int sellTickets(Movie* pMovie, Theater* pTheater, bool is_dubbed, int tickets_num, int row, int rightmost_seat);

protected:
	int Profit_;
};


#endif // !CASHIER_H


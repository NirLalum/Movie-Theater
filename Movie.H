#include "Proj.H"
#include "Mat.H"

#ifndef MOVIE_H
#define MOVIE_H

#define DAYS_IN_WEEK 7

class Movie {
public:
	
	//* constructor name: Movie
	//* Description: the constructor of Movie
	//* Parameters: MovieName - poiter to string of the name of the movie
	//*				MovieLength - length of the movie in minuets
	//*				MovieLang - poiter to string of the language of the movie
	//*				TheaterNum - number of theater of the movie
	//* return value: None
	Movie(char* MovieName, int MovieLength, char* MovieLang, int TheaterNum); // constructor
	
	//* function name: getName
	//* Description: This function return the name of this movie
	//* Parameters: Movie instance
	//* return value: string of movie name
	char* getName() const;
	
	//* function name: getLength
	//* Description: This function return the length in minuets of this movie
	//* Parameters: Movie instance
	//* return value: movie length
	int getLength() const;
	
	//* function name: getLanguage
	//* Description: This function return the language of this movie
	//* Parameters: Movie instance
	//* return value: language of this movie
	char* getLanguage() const;
	
	//* function name: getTheaterNum
	//* Description: This function return the theater number of this movie
	//* Parameters: Movie instance
	//* return value: theater number
	int getTheaterNum() const;
	
	//* function name: getTicketPrice
	//* Description: This function return the price of a ticket to this movie
	//* Parameters: none
	//* return value: price of ticket
	static int getTicketPrice();
	
	//* function name: addScreening
	//* Description: This function adds a screening of this movie to screening timetable
	//* Parameters: Movie instance
	//*				ScreeningDay - day of screening
	//* 			ScreeningHour - hour of screening
	//* return value: TRUE for successful adding, FALSE otherwise
	BOOL addScreening(int ScreeningDay, int ScreeningHour);
	
	//* function name: getNextScreening
	//* Description: This function return next screening of this movie
	//* Parameters: Movie instance
	//*				ScreeningDay - day of screening
	//* 			ScreeningHour - hour of screening
	//* return value: time of next screening or 0 for no screenings
	int	getNextScreening(int ScreeningDay, int ScreeningHour);
	
	//destructor of Movie
	~Movie(); 
protected:
	char* MovieName_;
	int MovieLength_;
	char* MovieLang_;
	int TheaterNum_;
	static int ticketPrice;
	Mat* ScreeningMat;
};

#endif 


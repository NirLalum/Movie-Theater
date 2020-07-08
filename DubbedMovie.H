#include "Movie.H"

#ifndef DUBBEDMOVIE_H
#define DUBBEDMOVIE_H

class DubbedMovie : public Movie {
public:
	
	//* constructor name: DubbedMovie
	//* Description: the constructor of DubbedMovie
	//* Parameters: MovieName - a pointer to the movie's name
	//*				MovieLength - the movie length
	//*             MovieLang - a pointer to a string representing the movie language
	//*				TheaterNum - the theater number
	//*				DubbedTheaterNum - the dubbed theater number
	//* return value: None
	DubbedMovie(char* MovieName, int MovieLength, char* MovieLang, int TheaterNum, int DubbedTheaterNum);
	
	//* function name: getHebrewTheaterNum
	//* Description: This function returns the theater number where the dubbed movie is screened
	//* Parameters: the dubbed movie instance
	//* return value: the theater number where the dubbed movie is screened
	int getHebrewTheaterNum() const;
	
	//* function name: addHebrewScreening
	//* Description: This function adds a new screening the screening matrix
	//* Parameters: the dubbed movie instance
	//*				screeningDay - the requested day of screening
	//*				ScreeningHour - the requested hour of screening
	//* return value: TRUE is screening was added and FALSE if not
	BOOL addHebrewScreening(int ScreeningDay, int ScreeningHour);
	
	//* function name: getNextHebrewScreening
	//* Description: finds the closest screening hour relativly to the given hour.
	//* Parameters: the dubbed movie instance
	//*				screeningDay - the requested day of screening
	//*				ScreeningHour - the requested hour of screening
	//* return value: the closest screening hour or 0 if the is no next screening
	int	getNextHebrewScreening(int ScreeningDay, int ScreeningHour);
	
	// the destructor of DubbedMovie
	~DubbedMovie();
private:
	int DubbedTheaterNum_;
	Mat* DubbedScreeningMat;
};



#endif 


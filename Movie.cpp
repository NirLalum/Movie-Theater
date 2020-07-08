#include "Movie.H"

// defining static members

int Movie::ticketPrice = 35;

//* function name: getTicketPrice
//* Description: This function return the price of a ticket to this movie
//* Parameters: none
//* return value: price of ticket
int Movie::getTicketPrice() {
	return ticketPrice;
}

//* constructor name: Movie
//* Description: the constructor of Movie
//* Parameters: MovieName - poiter to string of the name of the movie
//*				MovieLength - length of the movie in minuets
//*				MovieLang - poiter to string of the language of the movie
//*				TheaterNum - number of theater of the movie
//* return value: None
Movie::Movie(char* MovieName, int MovieLength, char* MovieLang, int TheaterNum) :MovieName_(MovieName), MovieLength_(MovieLength), MovieLang_(MovieLang), TheaterNum_(TheaterNum) {
	ScreeningMat = new Mat(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY); //defining a pointer to Mat instance
}

//* function name: getName
//* Description: This function return the name of this movie
//* Parameters: Movie instance
//* return value: string of movie name
char* Movie::getName() const {
	return MovieName_;
}

//* function name: getLength
//* Description: This function return the length in minuets of this movie
//* Parameters: Movie instance
//* return value: movie length
int Movie::getLength() const {
	return MovieLength_;
}

//* function name: getLanguage
//* Description: This function return the language of this movie
//* Parameters: Movie instance
//* return value: language of this movie
char* Movie::getLanguage() const{
	return MovieLang_;
}

//* function name: getTheaterNum
//* Description: This function return the theater number of this movie
//* Parameters: Movie instance
//* return value: theater number
int Movie::getTheaterNum() const {
	return TheaterNum_;
}

//* function name: addScreening
//* Description: This function adds a screening of this movie to screening timetable
//* Parameters: Movie instance
//*				ScreeningDay - day of screening
//* 			ScreeningHour - hour of screening
//* return value: TRUE for successful adding, FALSE otherwise
BOOL Movie::addScreening(int ScreeningDay, int ScreeningHour) {
	if (ScreeningDay < 1 || ScreeningDay > 7 || ScreeningHour < 1 || ScreeningHour > 24) return FALSE;
	int i = ScreeningDay; // to fit matrix indexes
	int j = 1;
	int currentScreening = ScreeningMat->getElement(i, j); // first screening in given day
	double LengthInHours = double(MovieLength_ )/ 60;
	// if the first cell is 0 then assign ScreeninHour
	if (currentScreening == 0){ 
		ScreeningMat->setElement(i, j, ScreeningHour);
		return TRUE;
	}
	for (j = 2; j <= MAX_SCREENINGS_PER_DAY; j++) {
		int prevScreening = ScreeningMat->getElement(i, j-1);
		currentScreening = ScreeningMat->getElement(i, j);
		if (currentScreening == 0) { // if the cell is empty
			if ((ScreeningHour - prevScreening > LengthInHours)) {
				ScreeningMat->setElement(i, j, ScreeningHour);
				return TRUE;
			}
			else return FALSE;
		}
	}
	return FALSE;
}

//* function name: getNextScreening
//* Description: This function return next screening of this movie
//* Parameters: Movie instance
//*				ScreeningDay - day of screening
//* 			ScreeningHour - hour of screening
//* return value: time of next screening or 0 for no screenings
int Movie::getNextScreening(int ScreeningDay, int ScreeningHour) {
	if (ScreeningDay < 1 || ScreeningDay > 7 || ScreeningHour < 0 || ScreeningHour > 24) return FALSE;
	int i = ScreeningDay; // to fit matrix indexes
	int j = 1;
	for (j = 1; j <= MAX_SCREENINGS_PER_DAY; j++) {
		int currentScreening = ScreeningMat->getElement(i, j);
		if (currentScreening > ScreeningHour) return currentScreening;
	}
	return 0;
}

//destructor of Movie
Movie::~Movie() { delete ScreeningMat; }



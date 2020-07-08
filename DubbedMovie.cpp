#include "DubbedMovie.H"

//* constructor name: DubbedMovie
//* Description: the constructor of DubbedMovie
//* Parameters: MovieName - a pointer to the movie's name
//*				MovieLength - the movie length
//*             MovieLang - a pointer to a string representing the movie language
//*				TheaterNum - the theater number
//*				DubbedTheaterNum - the dubbed theater number
//* return value: None
DubbedMovie::DubbedMovie(char* MovieName, int MovieLength, char* MovieLang, int TheaterNum, int DubbedTheaterNum) : Movie(MovieName, MovieLength, MovieLang, TheaterNum), DubbedTheaterNum_(DubbedTheaterNum) {
	DubbedScreeningMat = new Mat(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY);
}

//* function name: getHebrewTheaterNum
//* Description: This function returns the theater number where the dubbed movie is screened
//* Parameters: the dubbed movie instance
//* return value: the theater number where the dubbed movie is screened
int DubbedMovie::getHebrewTheaterNum() const {
	return DubbedTheaterNum_;
}

//* function name: addHebrewScreening
//* Description: This function adds a new screening the screening matrix
//* Parameters: the dubbed movie instance
//*				screeningDay - the requested day of screening
//*				ScreeningHour - the requested hour of screening
//* return value: TRUE is screening was added and FALSE if not
BOOL DubbedMovie::addHebrewScreening(int ScreeningDay, int ScreeningHour) {
	if (ScreeningDay < 1 || ScreeningDay > 7 || ScreeningHour < 1 || ScreeningHour > 24) return FALSE;
	int i = ScreeningDay;
	int j = 1;
	double LengthInHours = double(MovieLength_) / 60;
	int currentScreening = DubbedScreeningMat->getElement(i, j); // first screening in given day
	// if the first cell is 0 then assign ScreeninHour
	if (currentScreening == 0) {
		DubbedScreeningMat->setElement(i, j, ScreeningHour);
		return TRUE;
	}
	// iterating the whole day and adding a screening if there is a valid cell
	for (j = 2; j <= MAX_SCREENINGS_PER_DAY; j++) {
		int prevScreening = DubbedScreeningMat->getElement(i, j - 1);
		currentScreening = DubbedScreeningMat->getElement(i, j);
		if (currentScreening == 0) { // if the cell is empty
			if ((ScreeningHour - prevScreening > LengthInHours)) {
				DubbedScreeningMat->setElement(i, j, ScreeningHour);
				return TRUE;
			}
			else return FALSE;
		}
	}
	return FALSE;

}

//* function name: getNextHebrewScreening
//* Description: finds the closest screening hour relativly to the given hour.
//* Parameters: the dubbed movie instance
//*				screeningDay - the requested day of screening
//*				ScreeningHour - the requested hour of screening
//* return value: the closest screening hour or 0 if the is no next screening 
int DubbedMovie::getNextHebrewScreening(int ScreeningDay, int ScreeningHour) {
	if (ScreeningDay < 1 || ScreeningDay > 7 || ScreeningHour < 0 || ScreeningHour > 24) return FALSE;
	int i = ScreeningDay; // to fit matrix indexes
	int j = 1;
	for (j = 1; j <= MAX_SCREENINGS_PER_DAY; j++) {
		int currentScreening = DubbedScreeningMat->getElement(i, j);

		// first screening in given day
		if (currentScreening > ScreeningHour) return currentScreening;
	}
	return 0;

}

// the destructor of DubbedMovie 
DubbedMovie::~DubbedMovie() { delete DubbedScreeningMat; }
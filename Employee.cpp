#include <string.h>
#include <stdlib.h>
#include "Employee.H"


//* constructor name: Employee
//* Description: the constructor of Employee
//* Parameters: name - a pointer to the Employee's name
//*				salary - the Employee salary
//*             schedule - a pointer to an array of pointers that represents the weekly scedule of the Employee.
//* return value: None
Employee::Employee(char* name, int salary, char** schedule): salary_(salary), schedule_(schedule){
	int size = strlen(name);
	name_ = new char[size + 1];
	strcpy(name_, name);
}

//* function name: getName
//* Description: This function returns the name of the employee
//* Parameters: the emloyee instance
//* return value: the name of the employee
char* Employee::getName() const{
	return name_;
}

//* function name: getSalary
//* Description: This function returns the salary of the employee
//* Parameters: the emloyee instance
//* return value: the salary of the employee
int Employee::getSalary() const {
	return salary_;
}

//* function name: getName
//* Description: calculated the weekly salary of a given emloyee
//* Parameters: the emloyee instance
//* return value: the weekly salary of the employee
int Employee::calcWeeklySalary() const {
	int i = 0;
	int sum = 0;
	for (i; i < 7; i++) {
		char* dest = new char[6];
		strcpy(dest, *(schedule_ + i));
		int begining = atoi(strtok(dest, "-"));
		int end = atoi(strtok(NULL, "\0"));
		sum += (end - begining);
		delete[]dest;
	}
	return sum * salary_;
}

// Employee destructor
Employee::~Employee() {
	delete[]name_;
};

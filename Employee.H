#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	
	//* constructor name: Employee
	//* Description: the constructor of Employee
	//* Parameters: name - a pointer to the Employee's name
	//*				salary - the Employee salary
	//*             schedule - a pointer to an array of pointers that represents the weekly scedule of the Employee.
	//* return value: None
	Employee(char* name, int salary, char** schedule); //constructor
	
	//* function name: getName
	//* Description: This function returns the name of the employee
	//* Parameters: the emloyee instance
	//* return value: the name of the employee
	char* getName() const;
	
	//* function name: getSalary
	//* Description: This function returns the salary of the employee
	//* Parameters: the emloyee instance
	//* return value: the salary of the employee
	int getSalary() const;
	
	//* function name: getName
	//* Description: calculated the weekly salary of a given emloyee
	//* Parameters: the emloyee instance
	//* return value: the weekly salary of the employee
	int calcWeeklySalary() const;
	
	// Employee destructor
	~Employee();

private:
	char* name_;
	int salary_;
	char** schedule_;
};




#endif
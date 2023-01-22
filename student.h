#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;


class Student
{
public:
	const static int DaysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[DaysArraySize];
	DegreeProgram degreeprogram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int days[DaysArraySize], DegreeProgram degreeprogram);
	~Student();

	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemail();
	int getage();
	int* getdays();
	DegreeProgram getdegreeprogram();

	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemail(string email);
	void setage(int age);
	void setdays(int days[]);
	void setdegreeprogram(DegreeProgram degreeprogram);

	static void printHeader();
	void print();
};
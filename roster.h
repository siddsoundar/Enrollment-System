#pragma once
#include "student.h"

class Roster
{
public:
	int  lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string data);
	void add(string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printbyDegreeProgram(DegreeProgram degreeprogram);

	~Roster();
};
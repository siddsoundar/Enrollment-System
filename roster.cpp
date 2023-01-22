#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "roster.h"
using std::vector;
using std::stringstream;


void Roster::parse(string data)
{
	DegreeProgram degreeprogram = SECURITY;
	if (data.back() == 'K') degreeprogram = NETWORK;
	else if (data.back() == 'E') degreeprogram = SOFTWARE;

	int R = data.find(",");
	string ID = data.substr(0, R);

	int L = R + 1;
	R = data.find(",", L);
	string first = data.substr(L, R - L);

	L = R + 1;
	R = data.find(",", L);
	string last = data.substr(L, R - L);

	L = R + 1;
	R = data.find(",", L);
	string email = data.substr(L, R - L);

	L = R + 1;
	R = data.find(",", L);
	int age = stoi(data.substr(L, R - L));

	L = R + 1;
	R = data.find(",", L);
	int day1 = stoi(data.substr(L, R - L));

	L = R + 1;
	R = data.find(",", L);
	int day2 = stoi(data.substr(L, R - L));

	L = R + 1;
	R = data.find(",", L);
	int day3 = stoi(data.substr(L, R - L));


	add(ID, first, last, email, age, day1, day2, day3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeprogram);
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getstudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i]; 
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed" << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " Error: Student not found" << std::endl << std::endl;
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}	 

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getstudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getdays()[0] + classRosterArray[i]->getdays()[1] + classRosterArray[i]->getdays()[2]) / 3.0 << std::endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = (classRosterArray[i]->getemail());
		if ((email.find('@') == string::npos) || (email.find('.') == string::npos) || (email.find(' ') != string::npos))
		{
			any = true;
			cout << email << std::endl;
		}
	}
	if (!any) cout << "N/A" << std::endl;
}

void Roster::printbyDegreeProgram(DegreeProgram degreeprogram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getdegreeprogram() == degreeprogram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

Roster::~Roster()
{
	cout << "Destructor called" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
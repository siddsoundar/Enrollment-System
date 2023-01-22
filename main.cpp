#include "roster.h"

int main()
{
	cout << "Course: SCRIPTING AND PROGRAMMING - APPLICATIONS - C867, Language used: C++, WGU ID: 010551033, Name: SIDD SOUNDAR" << std::endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Sidd,Soundar,siddsoundar@gmail.com,23,5,2,13,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Students:" << std::endl;
	classRoster.printAll();
	cout << endl;

	cout << "Invalid emails:" << std::endl;
	classRoster.printInvalidEmails();

	cout << "Average days for each course:" << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getstudentID());
	}


	classRoster.printbyDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	return 0;
}
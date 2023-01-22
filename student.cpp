#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < DaysArraySize; i++) this->days[i] = 0;
	this->degreeprogram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < DaysArraySize; i++) this->days[i] = days[i];
	this->degreeprogram = degreeprogram;
}

Student::~Student() {};

string Student::getstudentID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemail() { return this->email; }
int Student::getage() { return this->age; }
int* Student::getdays() { return this->days; }
DegreeProgram Student::getdegreeprogram() { return this->degreeprogram; }

void Student::setstudentID(string studentID) { this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemail(string email) { this->email = email; }
void Student::setage(int age) { this->age = age; }
void Student::setdays(int days[])
{
	for (int i = 0; i < DaysArraySize; i++) this->days[i] = days[i];
}
void Student::setdegreeprogram(DegreeProgram degreeprogram) { this->degreeprogram = degreeprogram; }

void Student::printHeader()
{
	cout << "Format: ID|First name|Last name|Email|Age|Days in course|Degree Program\n";
}

void Student::print()
{
	cout << this->getstudentID() << '\t';
	cout << this->getfirstName() << '\t';
	cout << this->getlastName() << '\t';
	cout << this->getemail() << '\t';
	cout << this->getage() << '\t';
	cout << this->getdays()[0] << ',';
	cout << this->getdays()[1] << ',';
	cout << this->getdays()[2] << '\t';
	cout << DegreeProgramStrings[this->getdegreeprogram()] << '\n';
}
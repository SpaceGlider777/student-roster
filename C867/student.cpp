#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student() { }

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourses[0] = daysInCourse1;
	this->daysInCourses[1] = daysInCourse2;
	this->daysInCourses[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

string Student::getStudentID() { return studentID; }

string Student::getFirstName() { return firstName; }

string Student::getLastName() { return lastName; }

string Student::getEmailAddress() { return emailAddress; }

int Student::getAge() { return age; }

int* Student::getDaysInCourses() { return daysInCourses; }

DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }

void Student::setFirstName(string firstName) { this->firstName = firstName; }

void Student::setLastName(string lastName) { this->lastName = lastName; }

void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }

void Student::setAge(int age) { this->age = age; }

void Student::setDaysInCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	daysInCourses[0] = daysInCourse1;
	daysInCourses[1] = daysInCourse2;
	daysInCourses[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
	cout << left << setw(6) << getStudentID();
	cout << "First Name: " << setw(11) << getFirstName();
	cout << "Last Name: " << setw(11) << getLastName();
	cout << "Email Address: " << setw(24) << getEmailAddress();
	cout << "Age: " << setw(6) << getAge();
	cout << "Days in Courses: " << "{" << getDaysInCourses()[0] << ", " << getDaysInCourses()[1] << ", " << getDaysInCourses()[2] << "}\t";

	switch (getDegreeProgram()) {
		case SECURITY:
			cout << "Degree Program: SECURITY" << endl;
			break;
		case NETWORK:
			cout << "Degree Program: NETWORK" << endl;
			break;
		case SOFTWARE:
			cout << "Degree Program: SOFTWARE" << endl;
			break;
	}
}
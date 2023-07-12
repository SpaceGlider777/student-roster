#include "roster.h"
#include <iostream>

const int NUM_STUDENTS = 5;

Roster::~Roster() {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}

	delete[] classRosterArray;
	cout << "Class roster deleted." << endl;
}

Student** Roster::getClassRosterArray() { return classRosterArray; }

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	classRosterArray[rosterCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	rosterCount++;
}

void Roster::remove(string studentID) {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			cout << "Student " << studentID << " removed." << endl;
			return;
		}
	}

	cout << "Student " << studentID << " not found." << endl;
}

void Roster::printAll() {
	cout << "Class Roster:" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}

	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			double averageDays = 0;
			for (int j = 0; j < 3; j++) {
				averageDays += classRosterArray[i]->getDaysInCourses()[j];
			}

			cout << "Average Days in Courses for " << classRosterArray[i]->getStudentID() << ": " << averageDays / 3.0 << endl;

			return;
		}
	}

	cout << "Student " << studentID << " not found." << endl;
}

void Roster::printInvalidEmails() {
	cout << "Invalid Email Addresses:" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}

		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << email << endl;
		}
	}

	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	switch (degreeProgram) {
		case SECURITY:
			cout << "Students in SECURITY:" << endl;
			break;
		case NETWORK:
			cout << "Students in NETWORK:" << endl;
			break;
		case SOFTWARE:
			cout << "Students in SOFTWARE:" << endl;
			break;
	}

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
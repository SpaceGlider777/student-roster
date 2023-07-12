#include <iostream>
#include "roster.h"
using namespace std;

int main() {
	cout << "Course Title: C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 011033793" << endl;
	cout << "Name: Stanley Chin" << endl << endl;

	const int NUM_STUDENTS = 5;
	const int NUM_FIELDS = 9;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Stanley,Chin,SChin11@wgu.edu,27,30,40,50,SOFTWARE"
	};

	Roster* classRoster = new Roster;
	string parsedData[NUM_FIELDS];

	// Add students to roster
	for (int i = 0; i < NUM_STUDENTS; i++) {
		string data = studentData[i];
		for (int j = 0; j < NUM_FIELDS; j++) {
			if (data.find(',') != string::npos) {
				parsedData[j] = data.substr(0, data.find(','));
				data = data.substr(data.find(',') + 1);
			}
			else {
				parsedData[j] = data; // Last element does not have a comma
			}
		}

		if (parsedData[8] == "SECURITY") {
			classRoster->add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], stoi(parsedData[4]), stoi(parsedData[5]), stoi(parsedData[6]), stoi(parsedData[7]), SECURITY);
		}
		else if (parsedData[8] == "NETWORK") {
			classRoster->add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], stoi(parsedData[4]), stoi(parsedData[5]), stoi(parsedData[6]), stoi(parsedData[7]), NETWORK);
		}
		else {
			classRoster->add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], stoi(parsedData[4]), stoi(parsedData[5]), stoi(parsedData[6]), stoi(parsedData[7]), SOFTWARE);
		}
	}

	// Function calls
	classRoster->printAll();
	classRoster->printInvalidEmails();
	
	for (int i = 0; i < NUM_STUDENTS; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getClassRosterArray()[i]->getStudentID());
	}

	cout << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->printAll();
	classRoster->remove("A3");
	cout << endl;
	
	delete classRoster;
}

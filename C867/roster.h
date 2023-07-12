#include "student.h"

class Roster {
	public:
		~Roster();
		Student** getClassRosterArray();
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

	private:
		Student** classRosterArray = new Student*[5];
		int rosterCount = 0;
};

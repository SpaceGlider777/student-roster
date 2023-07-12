#include <string>
#include "degree.h"
using namespace std;

class Student {
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysForCourse1, int daysForCourse2, int daysForCourse3, DegreeProgram degreeProgram);
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDaysInCourses();
		DegreeProgram getDegreeProgram();
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysInCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3);
		void setDegreeProgram(DegreeProgram degreeProgram);
		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourses[3];
		DegreeProgram degreeProgram;
};
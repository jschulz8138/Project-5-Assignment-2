//Justin S 2024
//Project 5 Assignment 2
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#define DELIMITER_OFFSET 2
#define FILENAME "StudentData.txt"
#define DELIMITER ','


//Student Data struct, containing a firstname and last name
struct STUDENT_DATA {
	string firstName;
	string lastName;

	STUDENT_DATA(string fName, string lName) {
		firstName = fName;
		lastName = lName;
	}

	friend ostream& operator<< (std::ostream& cout, STUDENT_DATA studentData) {
		return cout << studentData.firstName << " " << studentData.lastName << endl;
	}
};

//takes a filename to read from and a vector of student data to write in
void WriteDataToVector(string filename, vector<STUDENT_DATA>* dataVector) {
	std::ifstream input(filename);
	for (string line; getline(input, line); )
	{
		string firstName = line.substr(line.find(DELIMITER) + DELIMITER_OFFSET, line.length());
		string lastName = line.substr(0, line.find(DELIMITER));
		STUDENT_DATA lineStudent(firstName, lastName);
		dataVector->push_back(lineStudent);
	}
	return;
}

//given a vector of student data, display all of the names
void DisplayStudents(vector<STUDENT_DATA> dataVector) {
	for (int i = 0; i < dataVector.size(); i++) {
		cout << dataVector[i];
	}
}

int main() {
	vector<STUDENT_DATA> studentData;
	WriteDataToVector(FILENAME, &studentData);

	#if _DEBUG
	DisplayStudents(studentData);
	#endif

	return 1;
}

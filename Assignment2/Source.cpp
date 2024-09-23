//Justin S 2024
//Project 5 Assignment 2
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#define FILE_1 "StudentData.txt"
#define FILE_2 "StudentData_Emails.txt"
#define DELIMITER ','

//#define PRE_RELEASE


//Student Data struct, containing a firstname, last name, and email
struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
	std::string email;

	STUDENT_DATA(std::string fName, std::string lName, std::string eMail) {
		firstName = fName;
		lastName = lName;
		email = eMail;
	}

	STUDENT_DATA(std::string lineData) {
		std::vector<std::string> splitData;
		std::stringstream stream(lineData);
		for (std::string line; getline(stream, line, DELIMITER); )
			splitData.push_back(line);
		firstName = splitData[0];
		lastName = splitData[1];
#ifdef PRE_RELEASE
		email = splitData[2];
#endif
	}

	friend std::ostream& operator<< (std::ostream& cout, STUDENT_DATA studentData) {
#ifdef PRE_RELEASE
		return cout << studentData.firstName << studentData.lastName << " " << studentData.email;
#else
		return cout << studentData.firstName << studentData.lastName;
#endif
	}
};

//takes a filename to read from and a vector of student data to write in
void WriteDataToVector(std::string filename, std::vector<STUDENT_DATA>* dataVector) {
	std::ifstream input(filename);
	for (std::string line; getline(input, line); )
		dataVector->push_back(STUDENT_DATA(line));
}

//given a vector of student data, display all of the names
void DisplayStudents(std::vector<STUDENT_DATA> dataVector) {
	for (int i = 0; i < dataVector.size(); i++)
		std::cout << dataVector[i] << std::endl;
}

int main() {
	std::vector<STUDENT_DATA> studentData;
#ifdef PRE_RELEASE
	WriteDataToVector(FILE_2, &studentData);
#else
	WriteDataToVector(FILE_1, &studentData);
#endif

#ifdef _DEBUG
	DisplayStudents(studentData);
#endif

#ifdef PRE_RELEASE
	std::cout << "Application is running PreRelease";
#else
	std::cout << "Application is running Release";
#endif

	return 1;
}
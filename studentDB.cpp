/*******************************************************************************
Author:        Nick Stamas
CS Login:      stamas

Credits:       Program skeleton written by Professor Jim Skrentny

Course:        CS 368, Fall 2013
Assignment:    Programming Assignment 1
 *******************************************************************************/
#include <iostream>

using namespace std;

struct Student{
	int studentID;
	int numCredits;
	double gPA;
};

void addStudent(int iD, int numCredits, int gPA, int numStudent, Student dB[], dBSize){
	if(numStudent > 0){
		for(int i =0; i < dBSize; i++){
			if(dB[i].studentID == iD){
				cout << "error - student "<< iD << " already exists." << endl;
				break;
			}
		}
	}
	Student newStudent;
	newStudent.studentID = iD;
	newStudent.numCredits = numCredits;
	newStudent.gPA = gPA;
	if(numStudent < dB.length){
		dB[numStudent] = newStudent;
		numStudent++;
	} else {
		cout << "The student Database is at full capacity." << endl;
	}
}

double gPACalc(double oldGPA, int oldCredits, char grade, int newCredits){
	double newGPA;
	switch (grade){
	case 'A':
		newGPA = 4;
		break;
	case'B':
		newGPA = 3;
		break;
	case 'C':
		newGPA = 2;
		break;
	case'D':
		newGPA = 1;
		break;
	case'F':
		newGPA = 0;
		break;
	}
	return ((oldGPA * oldCredits) + (newGPA * newCredits))/(double)(oldCredits + newCredits);
}

void updateStudent(int iD, char grade, int credits, int numStudent, Student dB[], int dBSize){
	while(numStudent > 0){
		for(int i =0; i < dBSize; i++){
			if(dB[i].studentID == iD){
				dB[i].gPA = (gPACalc(dB[i].getGPA, dB[i].getCredits, grade, credits));
				db[i].numCredits = (dB[i].getCredits) + credits;
				break;
			}
		}
		cout << "error - student "<< studentID << " does not exist." << endl;
		break;
	}
	cout << "error - student "<< studentID << " does not exist." << endl;
}

bool deleteStudent(int iD, int numStudent, Student dB[], int dBSize){
	if(numStudent >0){
		for(int i =0; i < dBSize; i++){
			if(dB[i].studentID == iD){
				dB[i] = dB[numStudents];
				dB[numStudents] = 0;
				return true;
			}
		}
		cout << "error - student "<< &iD << " does not exist." << endl;
		return false;
	}
	cout << "error - student "<< &iD << " does not exist." << endl;
	return false;
}

void printDB(int numStudent, Student dB[], int dBSize){
	if(numStudent >0){
		for(int i =0; i < dBSize; i++){
			if(dB[i] != null){
				cout << dB[i].studentID << ',' << dB[i].numCredits << ',' << dB[i].gPA << endl;
			}
		}
	}
}


int main() {
	int studentID, numCredits, numStudent;
	char grade;
	double gPA;
	bool done = false;
	const int dBSize = 5000;
	char choice;
	Student dB[dBSize];
	numStudent = 0;

	cout << "Enter your commands at the > prompt:" << endl;
	while (!done) {
		cout << "> ";
		cin >> choice;

		switch (choice) {

		case 'a':
			cin >> studentID;
			cin >> numCredits;
			cin >> gPA;
			if(studentID < 10000 || studentID > 999999){
				cout << "Not a valid student ID" << endl;
				break;
			}
			if(numCredits < 0){
				cout << "Not a valid amount of credits" << endl;
				break;
			}
			if(gPA < 0 || gPA > 4){
				cout << "Not a valid GPA" << endl;
				break;
			}

			addStudent(studentID, numCredits, gPA, numStudent, dB, dBSize);

			break;

		case 'u':
			cin >> studentID;
			cin >> grade;
			cin >> numCredits;
			if(studentID < 10000 || studentID > 999999){
				cout << "Not a valid student ID" << endl;
				break;
			}
			if(grade.toUpper() < 'A' || grade.toUpper() > 'F'){
				cout << "Not a valid grade" << endl;
				break;
			}
			if(gPA < 0 || gPA > 4){
				cout << "Not a valid GPA" << endl;
				break;
			}
			updateStudent(studentID, grade, numCredits, numStudent, dB, dBSize);
			break;

		case 'd':
			cin >> studentID;  // read in the integer ID
			if(studentID < 10000 || studentID > 999999){
				cout << "Not a valid student ID" << endl;
				break;
			}
			deleteStudent(studentID, numStudent, dB, dBSize);
			break;

		case 'p':
			if(numStudents > 0){
				printDB(numStudent, dB, dBSize);
			}
			break;

		case 'q':
			done = true;
			cout << "quit" << endl;
			break;

			// If the command is not one listed in the specification, for the
			// purposes of this assignment, we will ignore it.  Note that you
			// will see multiple ?'s printed out if there is additional
			// information on the line (in addition to the unknown command
			// character).
		default: break;
		} // end switch

	} // end while

	return 0;
}


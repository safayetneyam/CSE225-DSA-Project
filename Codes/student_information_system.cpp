#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <algorithm>

using namespace std;

struct student {
	int id, semester;
	string name, dob, department, email, contact, address, bloodGroup;
	int isPaymentDone, isScholarshipCandidate, isGraduated;
	double completedCredits, cgpa;

	student *next, *prev;
};

student *head = NULL, *tail = NULL;

student *createStudent(int id);
student *createStudent(student *stud);
student *createStudent(int id, string name);

void insertStudent(int id);
void insertStudent(student *temp);
void insertStudent(int id, string name);

void updatePartialData();
void updateInfoByID();

void deleteNode(student *delNode);
void deleteAllInfo();
void deleteByID(int id);
void deleteByName(string name);
void deleteByCGPA(double cgpa, string dir);
void deleteByGradStatus();
void deleteProbatedStudents();

bool foundId(int id);
bool foundName(string name);
bool isComplete(student *stud);
bool compareString(string s1, string s2);

void searchById(int id);
void searchByName(string name);
void searchByCompletedCredits(double completedCredits, string dir);
void searchByCGPA(double cpga, string dir);
void searchByContact(string contact);
void searchByBloodGroup(string bloodGroup);
void searchByDepartment(string department);
void searchBySemester(int semester);
void searchByUnpaidStudents();
void searchByGraduateStudents();
void searchByProbationStudents();

void sortByID();
void sortByName();
void sortByCGPA();
void sortBySemester();
void sortByDepartment();
void sortByCompletedCredits();

int menu();
void showStudentInfo();
void addStudentInfo();
void updateStudentInfo();
void deleteStudentInfo();
void searchStudentInfo();
void sortStudentInfo();
void generateReport();

void generateParticularReport(student *stud, fstream &newFile);
void reportOnSpecificID(int id);
void reportOnAllStudents();
void reportBySemester(int sem);
void reportByCGPA(double cgpa, string dir);
void reportOnProbatedStudents();

void printSpecificID(int id);
void printSpecificID(student *updCur);

string makingLower(string str);
int stringToInteger(string line);
double stringToDouble(string line);

void inputManipulation();
void outputManipulation();

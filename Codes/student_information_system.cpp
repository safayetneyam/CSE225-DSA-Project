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

int main() {
    inputManipulation();
    int input;
    while (input != 0) {
        input = menu();
        if (input == 1) {
            showStudentInfo();
            cout<<"\nPress any key to return Main Menu...";
            getch();
        } else if (input == 2) {
            addStudentInfo();
        } else if (input == 3) {
            updateStudentInfo();
        } else if (input == 4) {
            deleteStudentInfo();
        } else if (input == 5) {
            searchStudentInfo();
        } else if (input == 6) {
            sortStudentInfo();
        } else if (input == 7) {
            generateReport();
        } else if (input == 0) {
            outputManipulation();
            exit(0);
        } else {
            cout << "\n\t\t\tInvalid Option!!" << "\n";
            cout << "\t\t       Please try again..." << "\n";
            cout << "\n";
            cout << "Press any key to continue...";
            getch();
        }
    }
}

student *createStudent(int id) {
    student *newStudent = new student();

    newStudent -> id = id;
    newStudent -> name = "Not Given";
    newStudent -> completedCredits = -1;
    newStudent -> cgpa = -1;
    newStudent -> dob = "Not Given";
    newStudent -> email = "Not Given";
    newStudent -> contact = "Not Given";
    newStudent -> address = "Not Given";
    newStudent -> bloodGroup = "Not Given";
    newStudent -> department = "Not Given";
    newStudent -> semester = -1;
    newStudent -> isPaymentDone = -1;
    newStudent -> isScholarshipCandidate = -1;
    newStudent -> isGraduated = -1;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

student *createStudent(student *stud){
    student *newStudent = new student();

    newStudent -> id = stud -> id;
    newStudent -> name = stud -> name;
    newStudent -> completedCredits = stud -> completedCredits;
    newStudent -> cgpa = stud -> cgpa;
    newStudent -> dob = stud -> dob;
    newStudent -> email = stud -> email;
    newStudent -> contact = stud -> contact;
    newStudent -> address = stud -> address;
    newStudent -> bloodGroup = stud -> bloodGroup;
    newStudent -> department = stud -> department;
    newStudent -> semester = stud -> semester;
    newStudent -> isPaymentDone = stud -> isPaymentDone;
    newStudent -> isScholarshipCandidate = stud -> isScholarshipCandidate;
    newStudent -> isGraduated = stud -> isGraduated;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

student *createStudent(int id, string name) {
    student *newStudent = new student();

    newStudent -> id = id;
    newStudent -> name = name;
    newStudent -> completedCredits = -1;
    newStudent -> cgpa = -1;
    newStudent -> dob = "Not Given";
    newStudent -> email = "Not Given";
    newStudent -> contact = "Not Given";
    newStudent -> address = "Not Given";
    newStudent -> bloodGroup = "Not Given";
    newStudent -> department = "Not Given";
    newStudent -> semester = -1;
    newStudent -> isPaymentDone = -1;
    newStudent -> isScholarshipCandidate = -1;
    newStudent -> isGraduated = -1;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

void insertStudent(int id) {
    student *newStd = createStudent(id);

    if(head == NULL) {
        head = newStd;
        tail = newStd;
    } else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

    system("CLS");
    cout << "\t\t\tA new ID has been Created!";
    cout << "\n\nPress any key to continue.....";
    getch();

}

void insertStudent(student *stud) {
    student *newStd;
    if (stud != NULL) {
        newStd = createStudent(stud);
    } else {
        student *newStudent = new student();

        cout << "\nEnter ID: ";
        int id; cin >> id; 
        if (foundId(id)) {
            cout << "\n\n\tID already Inserted" << endl << endl;
            cout << "Press any key to continue...";
            getch();
            return;
        } else {
            newStudent -> id = id;
        }

        cout << "Enter Name: ";
        string name; getline(cin >> ws, name); newStudent -> name = name;
        cout << "Enter Credit Count: ";
        double completedCredits; cin >> completedCredits; newStudent -> completedCredits = completedCredits;
        cout << "Enter CGPA: ";
        double cgpa; cin >> cgpa; newStudent -> cgpa = cgpa;
        cout << "Enter Date of Birth: ";
        string dob; getline(cin >> ws, dob); newStudent -> dob = dob;
        cout << "Enter Email: ";
        string email; getline(cin >> ws, email); newStudent -> email = email;
        cout << "Enter Contact: ";
        string contact; getline(cin >> ws, contact); newStudent -> contact = contact;
        cout << "Enter Address: ";
        string address; getline(cin >> ws, address); newStudent -> address = address;
        cout << "Enter Blood Group: ";
        string bloodGroup; getline(cin >> ws, bloodGroup); newStudent -> bloodGroup = bloodGroup;
        cout << "Enter Department: ";
        string department; getline(cin >> ws, department); newStudent -> department = department;
        cout << "Enter Semester(in digit): ";
        int semester; cin >> semester; newStudent -> semester = semester;

        cout << "Payment Done? If No, Press 0: ";
        int isPaymentDone; cin >> isPaymentDone;
        newStudent -> isPaymentDone = isPaymentDone;

        cout << "Scholarship Candidate? If No, Press 0: ";
        int isScholarshipCandidate; cin >> isScholarshipCandidate;
        newStudent -> isScholarshipCandidate = isScholarshipCandidate;

        cout << "Graduated? If No, Press 0: ";
        int isGraduated; cin >> isGraduated;
        newStudent -> isGraduated = isGraduated;

        newStudent -> next = NULL;
        newStudent -> prev = NULL;

        newStd = createStudent(newStudent);       
    }
    
    if (head == NULL) {
        head = newStd;
        tail = newStd;
    } else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }
}

void insertStudent(int id, string name) {
    student *newStd = createStudent(id, name);

    if (head == NULL) {
        head = newStd;
        tail = newStd;
    } else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

    system("CLS");
    cout << "\t\t\tA new ID with Name has been created!";
    cout << "\n\nPress any key to continue.....";
    getch();
}

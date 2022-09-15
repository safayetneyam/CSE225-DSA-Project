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

bool isComplete(student *stud) {
    if (stud -> name == "Not Given") return false;
    if (stud -> completedCredits == -1.0) return false;
    if (stud -> cgpa == -1.0) return false;
    if (stud -> dob == "Not Given") return false;
    if (stud -> email == "Not Given") return false;
    if (stud -> contact == "Not Given") return false;
    if (stud -> address == "Not Given") return false;
    if (stud -> bloodGroup == "Not Given") return false;
    if (stud -> department == "Not Given") return false;
    if (stud -> semester == -1) return false;
    if (stud -> isPaymentDone == -1) return false;
    if (stud -> isScholarshipCandidate == -1) return false;
    if (stud -> isGraduated == -1) return false;
    return true;
}

void updatePartialData() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tUpdate Incomplete Information\n\n";

    student *updCur = head;
    while (updCur != NULL) {
        if (!isComplete(updCur)) {
            cout << "\n\tUpdating Student ID: " << updCur -> id << endl << endl;
            if (updCur -> name == "Not Given") {
                cout << "Enter Name: ";
                string name; getline(cin >> ws, name);
                updCur -> name = name;
            }
            if (updCur -> completedCredits == -1) {
                cout << "Enter Credits Completed: ";
                double completedCredits; cin >> completedCredits;
                updCur -> completedCredits = completedCredits;
            }
            if (updCur -> cgpa == -1) {
                cout << "Enter Current CGPA: ";
                double cgpa; cin >> cgpa;
                updCur -> cgpa = cgpa;
            }
            if (updCur -> dob == "Not Given") {
                cout << "Enter Date of Birth: ";
                string dob; getline(cin >> ws, dob);
                updCur -> dob = dob;
            }
            if (updCur -> email == "Not Given") {
                cout << "Enter Email: ";
                string email; getline(cin >> ws, email);
                updCur -> email = email;
            }
            if (updCur -> contact == "Not Given") {
                cout << "Enter Contact: ";
                string contact; getline(cin >> ws, contact);
                updCur -> contact = contact;
            }
            if (updCur -> address == "Not Given") {
                cout << "Enter Address: ";
                string address; getline(cin >> ws, address);
                updCur -> address = address;
            }
            if (updCur -> bloodGroup == "Not Given") {
                cout << "Enter BloodGroup: ";
                string bloodGroup; getline(cin >> ws, bloodGroup);
                updCur -> bloodGroup = bloodGroup;
            }
            if (updCur -> department == "Not Given") {
                cout << "Enter Department: ";
                string department; getline(cin >> ws, department);
                updCur -> department = department;
            }
            if (updCur -> semester == -1) {
                cout << "Enter Semester (in digit): ";
                int semester; cin>>semester;
                updCur -> semester = semester;
            }
            if (updCur -> isPaymentDone == -1) {
                cout << "Is Payment Done? (0 or 1): ";
                int isPaymentDone; cin >> isPaymentDone;
                updCur -> isPaymentDone = isPaymentDone;
            }
            if (updCur -> isScholarshipCandidate == -1) {
                cout << "Is Scholarship Candidate? (0 or 1): ";
                int isScholarshipCandidate; cin >> isScholarshipCandidate;
                updCur -> isScholarshipCandidate = isScholarshipCandidate;
            }
            if (updCur -> isGraduated == -1) {
                cout << "Is Graduated? (0 or 1): ";
                int isGraduated; cin >> isGraduated;
                updCur -> isGraduated = isGraduated;
            }
        } updCur = updCur -> next;
    }

    system("CLS");
    cout << "\n\n\t\t\tAll Incomplete Information has been Inserted!";
    cout << "\n\nPress any key to continue.....";
    getch();
}

void updateInfoByID() {
    system("CLS");
    string input;
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t   Update Student by ID\n\n";

    cout << "\nEnter an ID to Update: ";
    int id; cin >> id;

    student *updCur = head;
    while (updCur != NULL) {
        if (updCur -> id == id) break;
        updCur = updCur -> next;
    }

    if (updCur == NULL) {
        cout << "\n\t\t\tID was not found!" << endl;
        cout << "\t\t\tPlease try again..." << endl;
        getch();
        updateStudentInfo();
        return;
    }
    cout << "Student ID: " << updCur -> id << endl;
    cout << "\nSerial\t" << "Info" << endl;
    cout << "1.\t" << "Name\t\t\t: " << updCur -> name << endl;
    if (updCur -> completedCredits == -1.0) {
        cout << "2.\t" << "Credits\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "2.\t" << "Credits\t\t\t: " << updCur -> completedCredits << endl;
    }

    if (updCur -> cgpa == -1.0) {
        cout << "3.\t" << "CGPA\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "3.\t" << "CGPA\t\t\t: " << updCur -> cgpa << endl;
    }

    cout << "4.\t" << "DoB\t\t\t: " << updCur -> dob << endl;
    cout << "5.\t" << "Email\t\t\t: " << updCur -> email << endl;
    cout << "6.\t" << "Contact\t\t\t: " << updCur -> contact << endl;
    cout << "7.\t" << "Address\t\t\t: " << updCur -> address << endl;
    cout << "8.\t" << "Blood Group\t\t: " << updCur -> bloodGroup << endl;
    cout << "9.\t" << "Department\t\t: " << updCur -> department << endl;
    if (updCur -> semester == -1) {
        cout << "10.\t" << "Semester\t\t: " << "Not Given" << endl; 
    } else {
        cout << "10.\t" << "Semester\t\t: " << updCur -> semester << endl;
    }

    if (updCur -> isPaymentDone == 0) {
        cout << "11.\t" << "Paid?\t\t\t: " << "No" << endl;
    } else if (updCur -> isPaymentDone == 1) {
        cout << "11.\t" << "Paid?\t\t\t: " << "Yes" << endl;
    } else if (updCur -> isPaymentDone == -1) {
        cout << "11.\t" << "Paid?\t\t\t: " << "Not Given" << endl;
    } 

    if (updCur -> isScholarshipCandidate == 0) {
        cout << "12.\t" << "Scholarship Candidate?\t: " << "No" << endl;
    } else if (updCur -> isScholarshipCandidate == 1) {
        cout << "12.\t" << "Scholarship Candidate?\t: " << "Yes" << endl;
    } else if (updCur -> isScholarshipCandidate == -1) {
        cout << "12.\t" << "Scholarship Candidate?\t: " << "Not Given" << endl;
    }

    if (updCur -> isGraduated == 0) {
        cout << "13.\t" << "Graduated?\t\t: " << "No" << endl;
    } else if (updCur -> isGraduated == 1) {
        cout << "13.\t" << "Graduated?\t\t: " << "Yes" << endl;
    } else if (updCur -> isGraduated == -1) {
        cout << "13.\t" << "Graduated?\t\t: " << "Not Given" << endl;
    }

    string yn = "yes";
    while (yn == "yes") {
        cout << "\nWant to Update Anything? YES / NO : ";
        cin >> yn;
        transform(yn.begin(), yn.end(), yn.begin(), ::tolower);
        if (yn == "yes") {
            cout << "Enter a Serial to Update: ";
            int serial; cin >> serial;
            if (serial == 1) {
                cout << "\nEnter Name to Update: ";
                string name; getline(cin >> ws, name);
                updCur -> name = name;
            } else if (serial == 2) {
                cout << "Enter Credit Count to Update: ";
                double completedCredits; cin >> completedCredits;
                updCur -> completedCredits = completedCredits;
            } else if (serial == 3) {
                cout << "Enter CGPA to Update: ";
                double cgpa; cin >> cgpa;
                updCur -> cgpa = cgpa;
            } else if (serial == 4) {
                cout << "Enter Date of Birth to Update: ";
                string dob; cin >> dob;
                updCur -> dob = dob;
            } else if (serial == 5) {
                cout << "Enter Email to Update: ";
                string email; cin >> email;
                updCur -> email = email;
            } else if (serial == 6) {
                cout << "Enter Contact to Update: ";
                string contact; cin >> contact;
                updCur -> contact = contact;
            } else if (serial == 7) {
                cout << "Enter Address to Update: ";
                string address; cin >> address;
                updCur -> address = address;
            } else if (serial == 8) {
                cout << "Enter Blood Group to Update: ";
                string bloodGroup; cin >> bloodGroup;
                updCur -> bloodGroup = bloodGroup;
            } else if (serial == 9) {
                cout << "Enter Department to Update: ";
                string department; cin >> department;
                updCur -> department= department;
            } else if (serial == 10) {
                cout << "Enter Semester to Update (in digit): ";
                int semester; cin >> semester;
                updCur -> semester = semester;
            } else if (serial == 11) {
                cout << "Enter Payment Status to Update (0 for False, or 1): ";
                int isPaymentDone; cin >> isPaymentDone;
                updCur -> isPaymentDone = isPaymentDone;
            } else if (serial == 12) {
                cout << "Enter Scholarship Status to Update (0 for False, or 1): ";
                int isScholarshipCandidate; cin >> isScholarshipCandidate;
                updCur -> isScholarshipCandidate = isScholarshipCandidate;
            } else if (serial == 13) {
                cout << "Enter Graduate Status to Update (0 for False, or 1): ";
                int isGraduated; cin >> isGraduated;
                updCur -> isGraduated = isGraduated;
            } else {
                cout << "Invalid Serial!" << endl;
            }
        } else {
            updateStudentInfo();
        }
    }

}

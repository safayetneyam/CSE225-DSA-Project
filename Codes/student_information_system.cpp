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

void deleteAllInfo(){
    while (true) {
        student *temp = head;
        if (temp == NULL) {
            head = NULL;
            tail = NULL;
            return;
        }
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
    }
}

void deleteNode(student *delNode) {
    if (head == tail) {
        head = NULL;
        tail = NULL;
        delete delNode;
        return;
    }
    if (head == delNode) {
        head = head -> next;
        head -> prev = NULL;
    }
    if (tail == delNode) {
        tail -> prev -> next = NULL;
        tail = tail -> prev;
    }
    if (head == tail) return;
    if (delNode -> next != NULL) {
        delNode -> next -> prev = delNode -> prev;
    }
    if (delNode -> prev != NULL) {
        delNode -> prev -> next = delNode -> next;
    }
    delete delNode;
    return;
}

void deleteByID(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            deleteNode(cur);
            return;
        } cur = cur -> next; 
    }
}

void deleteByName(string name) {
    student *cur = head;
    while (cur != NULL) {
        if (compareString(cur -> name, name)) {
            deleteNode(cur);
            return;
        } cur = cur -> next; 
    }
}

void deleteByCGPA(double cgpa, string dir) {
    student *cur = head;
    student *next;
    if (dir == "=") {
        while (cur != NULL) {
            if (cur -> cgpa == cgpa) {
                next = cur -> next;
                deleteNode(cur);
                cur = next;
            } else cur = cur -> next;
        }
    } else if (dir == ">") {
        while (cur != NULL) {
            if (cur -> cgpa > cgpa) {
                next = cur -> next;
                deleteNode(cur);
                cur = next;
            } else cur = cur -> next;
        }
    } else if (dir == ">=") {
        while (cur != NULL) {
            if (cur -> cgpa >= cgpa) {
                next = cur -> next;
                deleteNode(cur);
                cur = next;
            } else cur = cur -> next;
        }
    } else if (dir == "<") {
        while (cur != NULL) {
            if (cur -> cgpa < cgpa && cur -> cgpa != -1) {
                next = cur -> next;
                deleteNode(cur);
                cur = next;
            } else cur = cur -> next;
        }
    } else if (dir == "<=") {
        while (cur != NULL) {
            if (cur -> cgpa <= cgpa && cur -> cgpa != -1) {
                next = cur -> next;
                deleteNode(cur);
                cur = next;
            } else cur = cur -> next;
        }
    }
}

void deleteByGradStatus() {
    student *cur = head;
    student *next;
    while (cur != NULL) {
        if (cur -> isGraduated == 1 && cur -> isGraduated != -1) {
            next = cur -> next;
            deleteNode(cur);
            cur = next;
        } else {
            cur = cur -> next; 
        }
    }
}

void deleteProbatedStudents() {
    student *cur = head;
    student *next;
    while (cur != NULL) {
        if (cur -> cgpa < 2.0 && cur -> cgpa != -1.0) {
            next = cur -> next;
            deleteNode(cur);
            cur = next;
        } else {
            cur = cur -> next; 
        }
    }
}

bool foundId(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            return true;
        } cur = cur -> next;
    } return false;
}

bool foundName(string name) {
    student *cur = head;
    while (cur != NULL) {
        if (compareString(cur -> name, name)) {
            return true;
        } cur = cur -> next;
    } return false;
}

bool compareString(string s1, string s2) {
    string str1 = s1;
    string str2 = s2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    if (str1 == str2) return true;
    else return false;
}

void searchById(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            printSpecificID(cur);
            return;
        } cur = cur -> next;
    }
    cout << "Invalid ID!" << endl;
}

void searchByName(string name) {
    cout << "\nStudent List is Displayed by Name " << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (compareString(cur -> name, name)) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "Invalid Name!" << endl;
    }
}

void searchByCompletedCredits(double completedCredits, string dir) {
    cout << "\nStudent List is Displayed by Completed Credits" << endl;
    student *cur = head;
    int cnt = 0;
    if (dir == "=") {
        while (cur != NULL) {
            if (cur -> completedCredits == completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<") {
         while (cur != NULL) {
            if (cur -> completedCredits < completedCredits && cur -> completedCredits != -1.0) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">") {
        while (cur != NULL) {
            if (cur -> completedCredits > completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">=") {
        while (cur != NULL) {
            if (cur -> completedCredits >= completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<=") {
        while (cur != NULL) {
            if (cur -> completedCredits <= completedCredits && cur -> completedCredits != -1.0) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }

    if (cnt == 0) {
        cout << "Not found!" << endl;
    }
}

void searchByCGPA(double cgpa, string dir) {
    cout << "Student List is Displayed by CGPA" << endl;
    student *cur = head;
    int cnt = 0;

    if (dir == "=") {
        while (cur != NULL) {
            if (cur -> cgpa == cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<" && cur -> cgpa != -1.0) {
         while (cur != NULL) {
            if (cur -> cgpa < cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">") {
        while (cur != NULL) {
            if (cur -> cgpa > cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">=") {
        while (cur != NULL) {
            if (cur -> cgpa >= cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<=") {
        while (cur != NULL) {
            if (cur -> cgpa <= cgpa && cur -> cgpa != -1.0) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }

    if (cnt == 0) {
        cout << "CGPA Not Found!" << endl;
    }
}

void searchByContact(string contact) {
    cout << "Student List is Displayed by Contact" << endl;
    student *cur = head;
    while (cur != NULL) {
        if (cur -> contact == contact) {
            printSpecificID(cur);
            return;
        } cur = cur -> next;
    }
    cout << "\nInvalid Contact Number!" << endl;
}

void searchByBloodGroup(string bloodGroup) {
    cout << "Student List is Displayed by Blood Group" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (compareString(cur -> bloodGroup, bloodGroup)) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\nInvalid Blood Group!" << endl;
    }
}

void searchByDepartment(string department) {
    cout << "Student List is Displayed by Department" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (compareString(cur -> department, department)) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\nStudents Not found!" << endl;
    }
}

void searchBySemester(int semester) {
    cout << "Student List is Displayed by Semester" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> semester == semester) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\nStudents Not found!" << endl;
    }
}

void searchByUnpaidStudents() {
    cout << "Student List is Displayed by Payment Status" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> isPaymentDone == 0) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\nPayment of All Students is Cleared" << endl;
    }
}

void searchByGraduateStudents() {
    cout << "Student List is Displayed by Graduate Status" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> isGraduated == 1) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\nNo Graduate Students!" << endl;
    }
}

void searchByProbationStudents() {
    cout << "Student List is Displayed by Probation Students" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> cgpa < 2.00 && cur -> cgpa != -1.0 && cur -> cgpa >= 0.0) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\n\nNo Probated Student!" << endl;
    }
}

void sortByID() {
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> id >= cur -> id) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> id < cur -> id) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

string makingLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void sortByName(){
    student *sorted = NULL;
    student *cur = head;
    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (makingLower(sorted -> name) >= makingLower(cur -> name)) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && makingLower(temp -> next -> name) < makingLower(cur -> name)) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByCGPA(){
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> cgpa >= cur -> cgpa) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> cgpa < cur -> cgpa) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortBySemester() {
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> semester >= cur -> semester) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> semester < cur -> semester) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByDepartment() {
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (makingLower(sorted -> department) >= makingLower(cur -> department)) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && makingLower(temp -> next -> department) < makingLower(cur -> department)) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByCompletedCredits() {
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> completedCredits >= cur -> completedCredits) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> completedCredits < cur -> completedCredits) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

int menu() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t\tMain Menu\n\n";
    cout << "  I N D E X \n\n";
    cout << "\t1. Show Student List\n";
    cout << "\t2. Add Student Information\n";
    cout << "\t3. Update Student Information\n";
    cout << "\t4. Delete Student Information\n";
    cout << "\t5. Search Student Information\n";
    cout << "\t6. Sort Student List\n";
    cout << "\t7. Generate Report\n\n";
    cout << "\t0. Exit\n";

    cout << "\n   Enter Your Instruction: ";
    int input; cin >> input;
    return input;
}

void showStudentInfo() {
    system("CLS");
    cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout<<"\t\t\t   All Information\n\n";

    student *temp = head;
    int cnt = 0;
    string output;
    while (temp != NULL) {
        cout << "  Previewing Student " << ++cnt << ":   ID - " << temp -> id << endl;
        cout << "\n\t" << "Info\n" << endl;
        cout << "\t" << "Name\t\t\t: " << temp -> name << endl;

        if (temp -> completedCredits == -1.0) {
            cout << "\t" << "Credits\t\t\t: " << "Not Given" << endl; 
        } else {
            cout << "\t" << "Credits\t\t\t: " << temp -> completedCredits << endl;
        }

        if (temp -> cgpa == -1.0) {
            cout << "\t" << "CGPA\t\t\t: " << "Not Given" << endl; 
        } else {
            cout << "\t" << "CGPA\t\t\t: " << temp -> cgpa << endl;
        }

        cout << "\t" << "Date of Birth\t\t: " << temp -> dob << endl;
        cout << "\t" << "Email\t\t\t: " << temp -> email << endl;
        cout << "\t" << "Contact\t\t\t: " << temp -> contact << endl;
        cout << "\t" << "Address\t\t\t: " << temp -> address << endl;
        cout << "\t" << "Blood Group\t\t: " << temp -> bloodGroup << endl;
        cout << "\t" << "Department\t\t: " << temp -> department << endl;

        if (temp -> semester == -1) {
            cout << "\t" << "Semester\t\t: " << "Not Given" << endl; 
        } else {
            cout << "\t" << "Semester\t\t: " << temp -> semester << endl;
        }

        if (temp -> isPaymentDone == 0) {
            cout << "\t" << "Paid?\t\t\t" << ": No" << endl;
        } else if (temp -> isPaymentDone == 1) {
            cout << "\t" << "Paid?\t\t\t" << ": Yes" << endl;
        } else if (temp -> isPaymentDone == -1) {
            cout << "\t" << "Paid?\t\t\t" << ": Not Given" << endl;
        } 

        if (temp -> isScholarshipCandidate == 0) {
            cout << "\t" << "Scholarship Candidate?\t" << ": No" << endl;
        } else if (temp -> isScholarshipCandidate == 1) {
            cout << "\t" << "Scholarship Candidate?\t" << ": Yes" << endl;
        } else if (temp -> isScholarshipCandidate == -1) {
            cout << "\t" << "Scholarship Candidate?\t" << ": Not Given" << endl;
        }

        if (temp -> isGraduated == 0) {
            cout << "\t" << "Graduated?\t\t" << ": No" << endl;
        } else if (temp -> isGraduated == 1) {
            cout << "\t" << "Graduated?\t\t" << ": Yes" << endl;
        } else if (temp -> isGraduated == -1) {
            cout << "\t" << "Graduated?\t\t" << ": Not Given" << endl;
        }
        cout << endl << endl;
        temp = temp -> next;
    }

    if (cnt == 0) {
        cout << "\n\n\n\tEmpty Student Information!\n\n";
    } else {
        cout << "\n  There're A Total Number of "<< cnt << " Retrieved Data from the Designated File." << endl;
    }

}

void addStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tInsert Information\n\n";

    cout << "\t1. Insert All Information\n";
    cout << "\t2. Insert By ID\n";
    cout << "\t3. Insert By ID & Name\n";
    cout << "\t<. Return to Main Menu\n";
    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;
    if (input == "1") {
        student *newStudent = NULL;
        insertStudent(newStudent);
    } else if (input == "2") {
        int id;
        cout << "\nEnter ID: ";
        cin >> id;
        if (foundId(id)) {
            cout << "\n\n\tID already Inserted" << endl << endl;
            cout << "Press any key to continue...";
            getch();
        } else {
            insertStudent(id);
        }
    } else if (input == "3") {
        int id;
        string name;
        cout<<"\nEnter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        getline(cin >> ws, name);
        if (foundId(id)) {
            cout << "\n\n\tID already Inserted" << endl << endl;
            cout << "Press any key to continue...";
            getch();
        } else {
            insertStudent(id, name);
        }
        
    } else if (input == "<") {
        return;
    } else if (input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        addStudentInfo();
    }
    addStudentInfo();
}

void updateStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Update Information\n\n";

    cout << "\n\t1. Update By ID"<<endl;
    cout << "\t2. Update Incomplete Student List"<<endl;
    cout << "\t<. Return to Main Menu"<<endl;

    cout << "\n\t0. Exit"<<endl;

    cout << "\n\nEnter your Instruction: ";
    string input; cin >> input;

    if (input == "1") {
        updateInfoByID();
    } else if (input == "2") {
        updatePartialData();
    } else if (input == "<") {
        return;
    } else if (input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        updateStudentInfo();
    }
}

void deleteStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Delete Information\n\n";

    cout << "\t1. Delete All Information\n";
    cout << "\t2. Delete By ID\n";
    cout << "\t3. Delete By Name\n";
    cout << "\t4. Delete By CGPA\n";
    cout << "\t5. Delete By Graduation Status\n";
    cout << "\t6. Delete By Probation Status\n";
    cout << "\t<. Return to Main Menu\n";

    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;
    if (input == "1") {
        deleteAllInfo();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\t\tAll Information has been deleted!\n" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "2") {
        int id;
        cout << "\nEnter ID: ";
        cin >> id;
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        if (foundId(id)) {
            deleteByID(id);
            cout << "\n\n\t\t\tAll Information of ID: " << id << " has been Removed!" << endl;
            cout << "\n\n\nPress any key to continue...";
            getch();
        } else {
            cout << "\t\t" << id << " Not Found!" << endl;
            cout << "\n\nPress any key to continue.....";
            getch();
        }
        getch();
    } else if (input == "3") {
        string name;
        cout << "\nEnter Name: ";
        getline(cin >> ws, name);
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        if (foundName(name)) {
            deleteByName(name);
            cout << "\n\n\t\t\tAll Information of Name: " << name << " has been Removed!" << endl;
            cout << "\n\n\nPress any key to continue...";
        } else {
            cout << "\t\t" << name << " Not Found!" << endl;
            cout << "\n\nPress any key to continue.....";
        }
        getch();
    } else if (input == "4") {
        double cgpa;
        cout << "\nEnter CGPA: ";
        cin >> cgpa;
        cout << "Enter Direction (=, <, >, <=, >=): ";
        string dir; cin >> dir;
        deleteByCGPA(cgpa, dir);
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\tAll Information of CGPA: " << cgpa << " with direction: " << dir << " has been Removed!" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "5") {
        deleteByGradStatus();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\tAll Information of Graduated Students has been Removed!" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "6") {
        deleteProbatedStudents();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\tAll Information of Probated Students has been Removed!" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "<") {
        return;
    } else if(input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        deleteStudentInfo();
    } deleteStudentInfo();
}

void searchStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tSearch Information\n\n";

    cout << "\t1. Search By ID\n";
    cout << "\t2. Search By Name\n";
    cout << "\t3. Search By Contact\n";
    cout << "\t4. Search By CGPA\n";
    cout << "\t5. Search By Blood Group\n";
    cout << "\t6. Search By Semester\n";
    cout << "\t7. Search By Department\n";
    cout << "\t8. Search By Completed Credits\n";
    cout << "\t9. Search By Unpaid Students\n";
    cout << "\t10. Search By Graduate Students\n";
    cout << "\t11. Search By Probation Students\n";
    cout << "\t<. Return to Main Menu\n";

    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin>>input;

    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tSearch Information\n\n";

    if (input == "1") {
        int id;
        cout << "\nEnter ID to Search: ";
        cin >> id;
        searchById(id);
    } else if (input == "2") {
        string name;
        cout << "\nEnter Name to Search: ";
        getline(cin >> ws, name);
        searchByName(name);
    } else if (input == "3") {
        string contact;
        cout << "\nEnter Contact to Search: ";
        getline(cin >> ws, contact);
        searchByContact(contact);
    } else if (input == "4") {
        double cgpa;
        string dir;
        cout << "\nEnter CGPA to Search: ";
        cin >> cgpa;
        cout << "\nChoose an Option: \n";
        cout << "\t<. Less than the CGPA\n";
        cout << "\t>. Greater than the CGPA\n";
        cout << "\t=. Equal to the CGPA\n";
        cout << "\t<=. Less than or equal to the CGPA\n";
        cout << "\t>=. Greater than or equal to the CGPA\n";

        cout << "\nEnter your Instruction: ";
        getline(cin >> ws, dir);
        searchByCGPA(cgpa, dir);
    } else if (input == "5") {
        string bloodGroup;
        cout << "\nEnter Blood Group to Search: ";
        getline(cin >> ws, bloodGroup);
        searchByBloodGroup(bloodGroup);
    } else if (input == "6") {
        int semester;
        cout << "\nEnter Semester to Search: ";
        cin >> semester;
        searchBySemester(semester);
    } else if (input == "7") {
        string department;
        cout << "\nEnter Department to Search: ";
        getline(cin >> ws, department);
        searchByDepartment(department);
    } else if (input == "8") {
        int completedCredits;
        string dir;
        cout << "\nEnter Completed Credits to Search: ";
        cin >> completedCredits;
        cout << "\nChoose an Option: \n";
        cout << "\t<. Less than the Completed Credits\n";
        cout << "\t>. Greater than the Completed Credits\n";
        cout << "\t=. Equal to the Completed Credits\n";
        cout << "\t<=. Less than or equal to the Completed Credits\n";
        cout << "\t>=. Greater than or equal to the Completed Credits\n";

        cout << "\nEnter your Instruction: ";
        getline(cin >> ws, dir);
        searchByCompletedCredits(completedCredits, dir);
    } else if (input == "9") {
        searchByUnpaidStudents();
    } else if (input == "10") {
        searchByGraduateStudents();
    } else if (input == "11") {
        searchByProbationStudents();
    } else if (input == "<") {
        return;
    } else if (input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        searchStudentInfo();
    }
    cout << "\n\n\nPress any key to continue...";
    getch();
    searchStudentInfo();
}

void sortStudentInfo() {
    system("CLS");

    string line;
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tSort Information\n\n";

    cout << "\t1. Sort By ID\n";
    cout << "\t2. Sort By Name\n";
    cout << "\t3. Sort By CGPA\n";
    cout << "\t4. Sort By Semester\n";
    cout << "\t5. Sort By Department\n";
    cout << "\t6. Sort By Completed Credits\n";
    cout << "\t<. Return to Main Menu\n";

    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;

    if (input=="1") {
        sortByID();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by ID!\n";
        cout << "\n\nDo you want to the Sorted Student List by ID? (YES / NO): ";
        getline(cin >> ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line == "yes") {
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input == "2") {
        sortByName();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by Name!\n";
        cout << "\n\nDo you want to the Sorted Student List by Name? (YES / NO): ";
        getline(cin >> ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line == "yes") {
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input == "3") {
        sortByCGPA();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by CGPA!\n";
        cout << "\n\nDo you want to the Sorted Student List by CGPA? (YES / NO): ";
        getline(cin >> ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line == "yes"){
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input == "4") {
        sortBySemester();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by Semester!\n";
        cout << "\n\nDo you want to the Sorted Student List by Semester? (YES / NO): ";
        getline(cin >> ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line == "yes"){
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input=="5") {
        sortByDepartment();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by Department!\n";
        cout << "\n\nDo you want to the Sorted Student List by Department? (YES / NO): ";
        getline(cin >> ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line == "yes"){
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input=="6") {
        sortByCompletedCredits();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\tSort Information\n\n";
        cout << "\n\n\tInformation is sorted by Completed Credits!\n";
        cout << "\n\nDo you want to the Sorted Student List by Completed Credits? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line == "yes"){
            showStudentInfo();
            cout << "\n\nPress any key to continue...";
            getch();
        }
    } else if (input == "<") {
        return;
    } else if (input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\nPress any key to continue...";
        getch();
        sortStudentInfo();
    }
    sortStudentInfo();
}

void generateReport() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Report Manipulation\n\n";

    cout << "\t1. Report on All Students\n";
    cout << "\t2. Report on Specific ID\n";
    cout << "\t3. Report by Semester\n";
    cout << "\t4. Report by CGPA\n";
    cout << "\t5. Report on Probated Students\n";
    cout << "\t<. Return to Main Menu\n";
    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;
    if (input == "1") {
        reportOnAllStudents();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Report Manipulation\n\n";
        cout << "\n\n\t\t\tReport on All Students has been Created!\n" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "2") {
        int id;
        cout << "\n\nEnter ID: ";
        cin >> id;
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Report Manipulation\n\n";
        if (foundId(id)) {
            reportOnSpecificID(id);
            cout << "\n\n\t\t\tReport on ID " << id << " has been Created!\n" << endl;
        } else {
            cout << "\n\n\t\t\t  ID " << id << " Not Found!\n" << endl;
        }
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "3") {
        int semester;
        cout << "\n\nEnter Semester (in digit): ";
        cin >> semester;
        reportBySemester(semester);
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Report Manipulation\n\n";
        cout << "\n\n\t\t\tReport by Semester " << semester << " has been Created!\n" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "4") {
        double cgpa;
        string dir;
        cout << "\n\nEnter CGPA: ";
        cin >> cgpa;
        cout << "\n\nEnter Direction ( = < > <= >= ): ";
        cin >> dir;
        reportByCGPA(cgpa, dir);
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Report Manipulation\n\n";
        cout << "\n\n\t\t\tReport by CGPA " << cgpa << ", ( " << dir << " ) has been Created!\n" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "5") {
        reportOnProbatedStudents();
        system("CLS");
        cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout << "\t\t\t    Report Manipulation\n\n";
        cout << "\n\n\t\t\tReport on Probated Students has been Created!\n" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    } else if (input == "<") {
        return;
    } else if (input == "0") {
        outputManipulation();
        exit(0);
    } else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        generateReport();
    }
    generateReport();
}

void printSpecificID(int id) {
    student *updCur = head;
    while (updCur != NULL) {
        if (updCur -> id == id) break;
        updCur = updCur -> next;
    }
    if (updCur == NULL) return;

    cout << "\n  Previewing Student ID: " << updCur -> id << endl;
    cout << "\n\t" << "Info\n" << endl;
    cout << "\t" << "Name\t\t\t: " << updCur -> name << endl;

    if (updCur -> completedCredits == -1.0) {
        cout << "\t" << "Credits\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "Credits\t\t\t: " << updCur -> completedCredits << endl;
    }

    if (updCur -> cgpa == -1.0) {
        cout << "\t" << "CGPA\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "CGPA\t\t\t: " << updCur -> cgpa << endl;
    }

    cout << "\t" << "Date of Birth\t\t: " << updCur -> dob << endl;
    cout << "\t" << "Email\t\t\t: " << updCur -> email << endl;
    cout << "\t" << "Contact\t\t\t: " << updCur -> contact << endl;
    cout << "\t" << "Address\t\t\t: " << updCur -> address << endl;
    cout << "\t" << "Blood Group\t\t: " << updCur -> bloodGroup << endl;
    cout << "\t" << "Department\t\t: " << updCur -> department << endl;

    if (updCur -> semester == -1) {
       cout << "\t" << "Semester\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "Semester\t\t: " << updCur -> semester << endl;
    }

    if (updCur -> isPaymentDone == 0) {
        cout << "\t" << "Paid?\t\t\t" << ": No" << endl;
    } else if (updCur -> isPaymentDone == 1) {
        cout << "\t" << "Paid?\t\t\t" << ": Yes" << endl;
    } else if (updCur -> isPaymentDone == -1) {
        cout << "\t" << "Paid?\t\t\t" << ": Not Given" << endl;
    } 

    if (updCur -> isScholarshipCandidate == 0) {
        cout << "\t" << "Scholarship Candidate?\t" << ": No" << endl;
    } else if (updCur -> isScholarshipCandidate == 1) {
        cout << "\t" << "Scholarship Candidate?\t" << ": Yes" << endl;
    } else if (updCur -> isScholarshipCandidate == -1) {
        cout << "\t" << "Scholarship Candidate?\t" << ": Not Given" << endl;
    }

    if (updCur -> isGraduated == 0) {
        cout << "\t" << "Graduated?\t\t" << ": No" << endl;
    } else if (updCur -> isGraduated == 1) {
        cout << "\t" << "Graduated?\t\t" << ": Yes" << endl;
    } else if (updCur -> isGraduated == -1) {
        cout << "\t" << "Graduated?\t\t" << ": Not Given" << endl;
    }
    cout << endl << endl; 

}

void printSpecificID(student *updCur) {
    cout << "\n  Previewing Student ID: " << updCur -> id << endl;
    cout << "\n\t" << "Info\n" << endl;
    cout << "\t" << "Name\t\t\t: " << updCur -> name << endl;

    if (updCur -> completedCredits == -1.0) {
        cout << "\t" << "Credits\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "Credits\t\t\t: " << updCur -> completedCredits << endl;
    }

    if (updCur -> cgpa == -1.0) {
        cout << "\t" << "CGPA\t\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "CGPA\t\t\t: " << updCur -> cgpa << endl;
    }

    cout << "\t" << "Date of Birth\t\t: " << updCur -> dob << endl;
    cout << "\t" << "Email\t\t\t: " << updCur -> email << endl;
    cout << "\t" << "Contact\t\t\t: " << updCur -> contact << endl;
    cout << "\t" << "Address\t\t\t: " << updCur -> address << endl;
    cout << "\t" << "Blood Group\t\t: " << updCur -> bloodGroup << endl;
    cout << "\t" << "Department\t\t: " << updCur -> department << endl;

    if (updCur -> semester == -1) {
       cout << "\t" << "Semester\t\t: " << "Not Given" << endl; 
    } else {
        cout << "\t" << "Semester\t\t: " << updCur -> semester << endl;
    }

    if (updCur -> isPaymentDone == 0) {
        cout << "\t" << "Paid?\t\t\t" << ": No" << endl;
    } else if (updCur -> isPaymentDone == 1) {
        cout << "\t" << "Paid?\t\t\t" << ": Yes" << endl;
    } else if (updCur -> isPaymentDone == -1) {
        cout << "\t" << "Paid?\t\t\t" << ": Not Given" << endl;
    } 

    if (updCur -> isScholarshipCandidate == 0) {
        cout << "\t" << "Scholarship Candidate?\t" << ": No" << endl;
    } else if (updCur -> isScholarshipCandidate == 1) {
        cout << "\t" << "Scholarship Candidate?\t" << ": Yes" << endl;
    } else if (updCur -> isScholarshipCandidate == -1) {
        cout << "\t" << "Scholarship Candidate?\t" << ": Not Given" << endl;
    }

    if (updCur -> isGraduated == 0) {
        cout << "\t" << "Graduated?\t\t" << ": No" << endl;
    } else if (updCur -> isGraduated == 1) {
        cout << "\t" << "Graduated?\t\t" << ": Yes" << endl;
    } else if (updCur -> isGraduated == -1) {
        cout << "\t" << "Graduated?\t\t" << ": Not Given" << endl;
    }
    cout << endl << endl;
}

void inputManipulation() {
    fstream newFile;
    newFile.open("dataset.txt", ios::in);
    if (newFile.is_open()) {
        string line;
        student *newStudent;
        int counter = 0;
        while (!newFile.eof()) {
            getline(newFile, line);
            if (counter % 14 == 0) {
                newStudent = new student();
                int id = stringToInteger(line);
                newStudent -> id = id;
            } else if (counter % 14 == 1) {
                newStudent -> name = line;
            } else if (counter % 14 == 2) {
                double credits = stod(line);
                newStudent -> completedCredits = credits;
            } else if (counter % 14 == 3) {
                double cgpa = stod(line);
                newStudent -> cgpa = cgpa;
            } else if (counter % 14 == 4) {
                newStudent -> dob = line;
            } else if (counter % 14 == 5) {
                newStudent -> email = line;
            } else if (counter % 14 == 6) {
                newStudent -> contact = line;
            } else if (counter % 14 == 7) {
                newStudent -> address = line;
            } else if (counter % 14 == 8) {
                newStudent -> bloodGroup = line;
            } else if (counter % 14 == 9) {
                newStudent -> department = line;
            } else if (counter % 14 == 10) {
                int semester = stringToInteger(line);
                newStudent -> semester = semester;
            } else if (counter % 14 == 11) {
                int isPaymentDone = stringToInteger(line);
                newStudent -> isPaymentDone = isPaymentDone;
            } else if (counter % 14 == 12) {
                int isScholarshipCandidate = stringToInteger(line);
                newStudent -> isScholarshipCandidate = isScholarshipCandidate;
            } else if (counter % 14 == 13) {
                int isGraduated = stringToInteger(line);
                newStudent -> isGraduated = isGraduated;
                
                insertStudent(newStudent);
            }
            counter++;
        }
        newFile.close();
    }
}

int stringToInteger(string line) {
    int num = 0;
    int n = line.length();
    if (line == "0") {
        return 0;
    }
    if (line[0] == '-') {
        for (int i = 1; i < n; i++) {
            num = num * 10 + (int(line[i]) - 48);          
        } num *= -1;
    } else {
        for (int i = 0; i < n; i++) {
            num = num * 10 + (int(line[i]) - 48);
        }
    }
    return num;
}

void outputManipulation() {
    fstream newFile;
    newFile.open("dataset.txt", ios::out);
    if (newFile.is_open()) {
        student *cur = head;
        while (cur != NULL) {
            string c_id = to_string(cur -> id);
            newFile << c_id << endl;
            newFile << cur -> name << endl;
            string c_completedCredits = to_string(cur -> completedCredits);
            newFile << c_completedCredits << endl;
            string c_cgpa = to_string(cur -> cgpa);
            newFile << c_cgpa << endl;
            newFile << cur -> dob << endl;
            newFile << cur -> email << endl;
            newFile << cur -> contact << endl;
            newFile << cur -> address << endl;
            newFile << cur -> bloodGroup << endl;
            newFile << cur -> department << endl;
            newFile << cur -> semester <<endl;
            newFile << cur -> isPaymentDone <<endl;
            newFile << cur -> isScholarshipCandidate <<endl;
            newFile << cur -> isGraduated <<endl;
        
            cur = cur -> next;
        }
    }
}

void generateParticularReport(student *stud, fstream &newFile) {
    newFile << "\n\t" << "ID  \t\t: " << stud -> id << endl;
    newFile << "\t" << "Name\t\t: " << stud -> name << endl;

    if (stud -> completedCredits == -1.0) {
        newFile << "\t" << "Credits\t\t: " << "Not Given" << endl;
    } else {
        newFile << "\t" << "Credits\t\t: " << stud -> completedCredits << endl;
    }

    if (stud -> cgpa == -1.0) {
        newFile << "\t" << "CGPA\t\t: " << "Not Given" << endl;
    } else {
        newFile << "\t" << "CGPA\t\t: " << stud -> cgpa << endl;
    }
    
    newFile << "\t" << "DoB\t\t: " << stud -> dob << endl;
    newFile << "\t" << "Email\t\t: " << stud -> email << endl;
    newFile << "\t" << "Contact\t\t: " << stud -> contact << endl;
    newFile << "\t" << "Address\t\t: " << stud -> address << endl;
    newFile << "\t" << "Blood Group\t: " << stud -> bloodGroup << endl;
    newFile << "\t" << "Department\t: " << stud -> department << endl;
    
    if (stud -> semester == -1) {
        newFile << "\t" << "Semester\t: " << "Not Given" << endl; 
    } else {
        newFile << "\t" << "Semester\t: " << stud -> semester << endl;
    }
    
    if (stud -> isPaymentDone == 0) {
        newFile << "\t" << "Paid?\t\t: " << "NO" << endl;
    } else if (stud -> isPaymentDone == 1) {
        newFile << "\t" << "Paid?\t\t: " << "YES" << endl;
    } else if (stud -> isPaymentDone == -1) {
        newFile << "\t" << "Paid?\t\t: " << "Not Given" << endl;
    } 

    if (stud -> isScholarshipCandidate == 0) {
        newFile << "\t" << "Scholarship?\t: " << "NO" << endl;
    } else if (stud -> isScholarshipCandidate == 1) {
        newFile << "\t" << "Scholarship?\t: " << "YES" << endl;
    } else if (stud -> isScholarshipCandidate == -1) {
        newFile << "\t" << "Scholarship?\t: " << "Not Given"<< endl;
    }

    if (stud -> isGraduated == 0) {
        newFile << "\t" << "Graduated?\t: " << "NO" << endl;
    } else if (stud -> isGraduated == 1) {
        newFile << "\t" << "Graduated?\t: " << "YES" << endl;
    } else if (stud -> isGraduated == -1) {
        newFile << "\t" << "Graduated?\t: " << "Not Given" << endl;
    }
}

void reportOnSpecificID(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            fstream newFile;
            newFile.open("ReportOn" + to_string(cur -> id) + ".txt", ios::out);
            if (newFile.is_open()) {
                newFile << "\t\tReport on Specific ID " << endl << endl;
                generateParticularReport(cur, newFile);
            }
            return;
        } cur = cur -> next;
    }
}

void reportOnAllStudents() {
    fstream newFile;
    newFile.open("ReportOnAllStudents.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport on All Students" << endl << endl;
        student *cur = head;
        if(cur == NULL) {
            newFile << "\tNo Available Information Found!" << endl;
        }
        int cnt = 0;
        while (cur != NULL) {
            newFile << "  Previewing Student: " << ++cnt << endl;
            generateParticularReport(cur, newFile);
            newFile << endl << endl;
            cur = cur -> next;
        }
    }
}

void reportOnProbatedStudents() {
    fstream newFile;
    newFile.open("ReportOnProbatedStudents.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport on Probated Students\t" << endl << endl;
        student *cur = head;
        if(cur == NULL) {
            newFile << "\tNo Avalable Information Found!" << endl;
        }
        int cnt = 0;
        while (cur != NULL) {
            if (cur -> cgpa < 2.0) {
                newFile << "  Previewing Student: " << ++cnt << endl;
                generateParticularReport(cur, newFile);
                newFile << endl << endl;
            }
            cur = cur -> next;
        }
    }
}

void reportBySemester(int sem) {
    fstream newFile;
    newFile.open("ReportBySemester.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport by Semester " << sem << " Students\t" << endl << endl;
        student *cur = head;
        if(cur == NULL) {
            newFile << "\tNo Avalable Information Found!" << endl;
        }
        int cnt = 0; 
        while (cur != NULL) {
            if (cur -> semester == sem) {
                newFile << "  Previewing Student: " << ++cnt << endl;
                generateParticularReport(cur, newFile);
                newFile << endl << endl;
            }
            cur = cur -> next;
        }
    }
}

void reportByCGPA(double cgpa, string dir) {
    fstream newFile;
    newFile.open("ReportByCGPA.txt", ios::out);
    int cnt = 0;
    if (newFile.is_open()) {
        if (dir == "=") {
            newFile << "\t\tReport of Students having CGPA Equals to " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa == cgpa) {
                    newFile << "  Previewing Student: " << ++cnt << endl;
                    generateParticularReport(cur, newFile);
                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == "<") {
            newFile << "\t\tReport of Students having CGPA Less than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa < cgpa) {
                    newFile << "  Previewing Student: " << ++cnt << endl;
                    generateParticularReport(cur, newFile);
                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == ">") {
            newFile << "\t\tReport of Students having CGPA Greater than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa > cgpa) {
                    newFile << "  Previewing Student: " << ++cnt << endl;
                    generateParticularReport(cur, newFile);
                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == "<=") {
            newFile << "\t\tReport of Students having CGPA Equal or Less than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa <= cgpa) {
                    newFile << "  Previewing Student: " << ++cnt << endl;
                    generateParticularReport(cur, newFile);
                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == ">=") {
            newFile << "\t\tReport of Students having CGPA Equal or Greater than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa >= cgpa) {
                    newFile << "  Previewing Student: " << ++cnt << endl;
                    generateParticularReport(cur, newFile);
                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else {
            newFile << "Invalid Direction to Predict!" << endl;
        }
    }
}

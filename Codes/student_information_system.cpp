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

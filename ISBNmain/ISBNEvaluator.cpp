#include "CodeEvaulator.h"
#include <iostream>
using namespace std; 

void ISBNEvaluator::evaluate() {
	Node* current = head;
	while (current != nullptr) {
		if (current->data.size() != 13) {
			current->valid = Valid::NoValid;
			current = current->next; 
			continue;
		}
		int sum = 0; 
		for (int i = 0; i < 13; i++) {
			if (i % 2 == 0) {
				sum += current->data[i];
			}
			else {
				sum += current->data[i] * 3; 
			}
		}
		if (sum % 10 == 0) {
			current->valid = Valid::YesValid;
		}
		else {
			current->valid = Valid::NoValid;
		}
		current = current->next;
	}
}
void ISBNEvaluator::subjectEvaluate() {

    Node* iter = head;

    while (iter != nullptr) {

        if (iter->valid == Valid::YesValid) {

            int digitSum = 0;
            for (int d : iter->data)
                digitSum += d;

            if (digitSum % 61 == 0)
                iter->subject = "Biology";
            else if (digitSum % 71 == 0)
                iter->subject = "English";
            else if (digitSum % 97 == 0)
                iter->subject = "Math";
            else if (digitSum % 73 == 0)
                iter->subject = "Physics";
            else if (digitSum % 103 == 0)
                iter->subject = "Psychology";
            else if (digitSum % 79 == 0)
                iter->subject = "Computer Science";
            else if (digitSum % 53 == 0)
                iter->subject = "Spanish";
            else if (digitSum % 83 == 0)
                iter->subject = "French";
            else
                iter->subject = "Unknown";
        }
        else {
            iter->subject = "Invalid";
        }

        iter = iter->next;
    }
}
// Print all valid codes
void ISBNEvaluator::printValidCodes() {

    Node* iter = head;

    while (iter != nullptr) {

        if (iter->valid == Valid::YesValid) {
            cout << iter->name << " (" << iter->subject << ")" << endl;
        }

        iter = iter->next;
    }
}


// Print codes by subject
void ISBNEvaluator::printSubjectCode(const string& subjectName) {

    Node* iter = head;

    while (iter != nullptr) {

        if (iter->subject == subjectName) {
            cout << iter->name << endl;
        }

        iter = iter->next;
    }
}
#include <iostream>
#include <vector> 
#include <string>
#include <filesystem>
#include "CodeEvaulator.h"
using namespace std; 

int main() {
    CodeEvaluator* evaluator = new ISBNEvaluator("ISBN_Codes.txt");

    evaluator->evaluate();
    evaluator->subjectEvaluate();
    evaluator->printValidCodes();

    // Loop over all the subjects
    string subject = "Biology"; 
    evaluator->printSubjectCode(subject);

    delete evaluator; 
    return 0; 
}
#include "CodeEvaulator.h"
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

vector<int> CodeEvaluator::parse(const string& code, char delimiter) {
    vector<int> digits;

    for (char ch : code) {
        if (isdigit(static_cast<unsigned char>(ch))) {
            digits.push_back(ch - '0');
        }
    }

    if (digits.size() != 13) {
        return {};
    }

    return digits;
}

void CodeEvaluator::headInsert(const vector<int>& data, const string& name) {
    Node* newNode = new Node(data, name);
    newNode->next = head;
    head = newNode;
}

void CodeEvaluator::readFile(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening the file: " << fileName << endl;
        return;
    }
	cout << "File Opened Successfully: " << fileName << endl;

    string line;

    
    getline(inputFile, line);

    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        vector<int> digits = parse(line, '-');
        if (!digits.empty()) headInsert(digits, line);
    }

    inputFile.close();
}
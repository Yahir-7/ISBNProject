#pragma once
#include <string>
#include <vector>
#include <random>

using namespace std;

struct ISBNTester {
    vector<int> generateFirstNPrimeNumbers(int N);
    int getRandomNumberInVect(const vector<int>& primeVec, int N);
    vector<int> generatePrimeNumbers(int N);

    
    vector<int> generate12DigitsExactSum(int target, mt19937& gen);

    // Create Codes 13 digit codes - kyle hadit, bianca
    vector<vector<int>> createCodes(const vector<vector<int>>& input);

    // Jeffrey Miguel
    void saveToFile(const vector<vector<int>>& ISBNvectors, const vector<int>& list);
};

class CodeEvaluator {
protected:
    enum class Valid { NoValid, YesValid };

    struct Node {
        vector<int> data;
        string name;
        string subject;
        Valid valid;
        Node* next;

        Node(const vector<int>& d, const string& n)
            : data(d), name(n), subject(""), valid(Valid::NoValid), next(nullptr) {}
    };

    Node* head;

public:
    CodeEvaluator(const string& fileName) {
        head = nullptr;
        readFile(fileName);
    }

    virtual ~CodeEvaluator() = default;

    vector<int> parse(const string& code, char delimiter);
    void readFile(const string& fileName);
    void headInsert(const vector<int>& data, const string& name);

    virtual void evaluate() = 0;
    virtual void subjectEvaluate() = 0;
    virtual void printValidCodes() = 0;
    virtual void printSubjectCode(const string& subjectName) = 0;
};

class ISBNEvaluator : public CodeEvaluator {
public:
    ISBNEvaluator(const string& filename) : CodeEvaluator(filename) {}

    // Declarations 
    void evaluate() override;
    void subjectEvaluate() override;
    void printValidCodes() override;
    void printSubjectCode(const string& subjectName) override;
};

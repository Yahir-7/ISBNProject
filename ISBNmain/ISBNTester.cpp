#include "CodeEvaulator.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

// Group 1
vector<int> ISBNTester::generateFirstNPrimeNumbers(int N) {
    vector<int> primeNumberVect;

    int count = 0;
    int num = 50;
    bool isPrime = true;

    while (count < N) {
        for (int i = 2; i < 10; i++) {
            if (num % i == 0) {
                if (num != i) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            primeNumberVect.push_back(num);
            count++;
        }

        isPrime = true;
        num++;
    }

    return primeNumberVect;
}

int ISBNTester::getRandomNumberInVect(const vector<int>& primeVec, int N) {
    return primeVec[rand() % N];
}

vector<int> ISBNTester::generatePrimeNumbers(int N) {
    vector<int> primeNumbers = generateFirstNPrimeNumbers(N);
    vector<int> generatedPrimes;

    srand((unsigned)time(0));

    int x = (rand() % N) + 1;
    generatedPrimes.push_back(getRandomNumberInVect(primeNumbers, N));

    int count = 1;
    while (count < x) {
        int newPrime = getRandomNumberInVect(primeNumbers, N);

        bool isInVector = false;
        for (int i = 0; i < (int)generatedPrimes.size(); i++) {
            if (newPrime == generatedPrimes[i]) {
                isInVector = true;
            }
        }

        if (!isInVector) {
            generatedPrimes.push_back(newPrime);
            count++;
        }
    }

    return generatedPrimes;
}

// Group 3 (Me & Andrew) — FIXED name to match header
vector<int> ISBNTester::generate12DigitsExactSum(int target, mt19937& gen) {
    vector<int> output(12, 0);

    int filled = 0;
    int temp = target;
    int op_index = 0;

    for (int digit = 9;;) {
        if (digit < temp) {
            temp -= digit;
            output[op_index] = digit;
            op_index++;
            filled++;
            if (filled == 12) break;
        }
        else if (digit > temp) {
            digit--;
        }
        else {
            output[op_index] = digit;
            filled++;
            break;
        }
    }

    shuffle(output.begin(), output.end(), gen);
    return output;
}

// Group 4
vector<vector<int>> ISBNTester::createCodes(const vector<vector<int>>& input) {

    int sum = 0;
    int thirteenthnum;
    vector<vector<int>> finalList;
    int randomThirteenth;

    if (input.size() > 13) {
        cout << "Error: Input size is greater than 13. The maximum size allowed is 13!" << endl;
        return finalList;
    }

    srand((unsigned)time(0));

    for (int vectorNum = 0; vectorNum < (int)input.size(); vectorNum++) {

        sum = 0;
        vector<int> resultantThirteen = input[vectorNum];

        if (resultantThirteen.size() != 12) continue;

        if (vectorNum % 3 == 0) {

            for (int i = 0; i < 12; i++) {
                sum += resultantThirteen[i];
            }

            if (sum % 10 != 0) thirteenthnum = 10 - (sum % 10);
            else thirteenthnum = 0;

            resultantThirteen.push_back(thirteenthnum);
        }
        else {
            randomThirteenth = rand() % 10;
            resultantThirteen.push_back(randomThirteenth);
        }

        finalList.push_back(resultantThirteen);
    }

    return finalList;
}

// Save output file
void ISBNTester::saveToFile(const vector<vector<int>>& ISBNvectors, const vector<int>& list) {
    ofstream out("ISBN_Codes.txt");
    if (!out.is_open()) {
        cout << "Error opening the file for writing!" << endl;
        return;
    }

    for (int i = 0; i < (int)list.size(); i++) {
        out << list[i];
        if (i + 1 < (int)list.size()) out << ":";
    }

    out << "\n";

    for (const auto& code : ISBNvectors) {
        for (int d : code) out << d;
        out << "\n";
    }

    out.close();
}
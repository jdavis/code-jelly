#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

//
// Declaration
//

class ScalarProduct {
    public:
        void setSize(size_t size);
        void setFirstVector(string line);
        void setSecondVector(string line);
        void print();
        long int calculateMin();
        static long int reverseCmp(long int x, long int y);

    public:
        size_t size;
        long int *first;
        long int *second;

};

//
// Definition
//

void ScalarProduct::setSize(size_t size) {
    this->size = size;
    first = new long int[size];
    second = new long int[size];
}

void ScalarProduct::setFirstVector(string line) {
    size_t i, j, k;
    string word;

    for(i = 0, j = 0; i < size; i++) {
        k = j;
        j = line.find(' ', j);
        word = line.substr(k, j);
        first[i] = atoi(word.c_str());
        j += 1;
    }
}

void ScalarProduct::setSecondVector(string line) {
    size_t i, j, k;
    string word;

    for (i = 0, j = 0; i < size; i++) {
        k = j;
        j = line.find(' ', j);
        word = line.substr(k, j);
        second[i] = atoi(word.c_str());
        j += 1;
    }
}


void ScalarProduct::print() {
    size_t i;

    cout << "First: ";
    for (i = 0; i < size; i++) {
        cout << first[i] << ", ";
    }
    cout << endl;

    cout << "Second: ";
    for (i = 0; i < size; i++) {
        cout << second[i] << ", ";
    }
    cout << endl;
}

/*
 * Idea: Given two arrays, it is obvious that we want to do a greedy
 * calculation to calculate the minimum scalar product. If we select the
 * biggest item from the first array, then we want to multiply it with the
 * biggest NEGATIVE item from the second array. If we repeat this, we will get
 * the minimum scalar product.
 *
 * Example:
 *      1 2 -5 8 -9
 *      6 8 2 4 0 1
 *
 *      Will be calculated as: -9*8 + -5*6 + 1*4 + 2*2 + 8*0
 */
long int ScalarProduct::calculateMin() {
    size_t i;
    long int sum;

    sort(first, first + size);
    sort(second, second + size);
    reverse(second, second + size);

    for (i = 0, sum = 0; i < size; i++) {
        sum += first[i] * second[i];
    }

    return sum;
}

long int ScalarProduct::reverseCmp(long int x, long int y) {
    return (x * x) > (y * y);
}

//
// Main
//

int main(int argc, const char *argv[]) {
    int nCases, i;
    ifstream file;
    string line;
    ScalarProduct *scalars;

    file.open(argv[1]);

    // Read the number of cases defined
    getline(file, line);
    nCases = atoi(line.c_str());

    scalars = new ScalarProduct[nCases];
    for(i = 0; i < nCases; i++) {
        // Read in size of vectors
        getline(file, line);
        scalars[i].setSize(atoi(line.c_str()));

        // Read in first vector
        getline(file, line);
        scalars[i].setFirstVector(line);

        // Read in second vector
        getline(file, line);
        scalars[i].setSecondVector(line);

        // Output results
        cout << "Case #" << i + 1 << ": ";
        cout << scalars[i].calculateMin() << endl;
    }

    // Cleanup
    file.close();

    return 0;
}

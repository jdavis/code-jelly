#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//
// Declarations
//

int usage();
void reverse(string &s);

//
// Definitions
//

int usage() {
    cout << "Store Credit.\n\n";
    cout << "Usage:\n";
    cout << "\tstore-credit <input file>";

    return 1;
}

void reverse(string &s) {
    size_t i, j, k;
    char c;

    for (i = 0, j = s.length() - 1; i < j; i++, j--) {
        // Swap characters
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    for (i = 0; i < s.length(); i++) {
        k = s.find_first_of(' ', i + 1);

        if (k == string::npos) {
            k = s.length();
        }

        for (j = k - 1; i < j; i++, j--) {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        
        i = k;
    }
}

int main(int argc, const char *argv[]) {
    int nCases, i;
    ifstream file;
    string line;

    // Check...
    if (argc == 1) return usage();
    else if (argc > 2) return usage();

    file.open(argv[1]);


    // Read the number of cases defined
    getline(file, line);

    nCases = atoi(line.c_str());

    for(i = 0; i < nCases; i++) {
        getline(file, line);
        reverse(line);

        // Output new information
        cout << "Case #" << i + 1 << ": ";
        cout << line << endl;
    }

    // Cleanup
    file.close();

    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

//
// Class Declaration
//

class StoreCredit {
    public:
        void setCredit(int c);
        void setItems(int gItems[]);
        pair<int, int> *buyItems();

    private:
        int credit;
        int items[];
}

//
// Class Definition
//

void StoreCredit::setCredit(int c) {
    credit = c;
}

void StoreCredit::setItems(int gItems[]) {
    for(int i = 0; i < sizeof(gItems) / sizeof(int); i++) {
        items[i] = gItems[i];
    }
}

pair<int, int> *StoreCredit::buyItems() {
    return new pair<int, int>;
}

//
// Functions for Main
//

int usage();

int main(int argc, const char *argv[]) {
    string line;
    ifstream f;

    if (argc == 1) return usage();
    else if (argc > 2) return usage();

    f.open(argv[1]);

    return 0;
}

int usage() {
    cout << "Store Credit.\n\n";
    cout << "Usage:\n";
    cout << "\tstore-credit <input file>";

    return 1;
}

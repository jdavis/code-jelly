#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//
// Class Declarations
//

/**
 * Container class for each item in the list. The reason for this is because the
 * items are sorted to improve lookup time and the position is lost. This
 * preserves the position for when determining the values to add up to the
 * credit limit.
 */
class Item {
    public:
        int position;
        int value;

        static bool comp(const Item &i1, const Item &i2);
};

/**
 * Main class for the problem. Encapsulates the algorithm and data for each test
 * case.
 */
class StoreCredit {
    public:
        void print();
        void setCreditFromString(string s);
        void setItemsLengthFromString(string s);
        void setItemsFromString(string s);
        pair<int, int> *buyItems();
        pair<int, int> *buyItemsOptimized();

    private:
        int credit;
        int itemsLength;
        Item *items;
};

//
// Class Definitions
//

bool Item::comp(const Item &i1, const Item &i2) {
    return (i1.value < i2.value);
}

void StoreCredit::print() {
    cout << "StoreCredit:" << endl;
    cout << "\tTotal Credit: " << credit << endl;
    cout << "\tItems Length:" << itemsLength << endl;
}

void StoreCredit::setCreditFromString(string s) {
    credit = atoi(s.c_str());
}

void StoreCredit::setItemsLengthFromString(string s) {
    itemsLength = atoi(s.c_str());
}

void StoreCredit::setItemsFromString(string s) {
    int i, j, k;
    string word;

    items = new Item[itemsLength];

    for(i = 0, j = 0; i < itemsLength && j < s.size(); i++) {
        k = s.find(' ', j);
        word = s.substr(j, k);
        items[i].position = i;
        items[i].value = atoi(word.c_str());
        j = k + 1;
    }

    sort(items, items + itemsLength, Item::comp);
}

pair<int, int> *StoreCredit::buyItems() {
    int i, j;

    for(i = 0; i < itemsLength; i++) {
        for(j = i + 1; j < itemsLength; j++) {
            if (items[i].value + items[j].value == credit) {
                if (items[i].position > items[j].position) {
                    return new pair<int, int>(items[j].position, items[i].position);
                } else {
                    return new pair<int, int>(items[i].position, items[j].position);
                }
            }
        }
    }

    return new pair<int, int>;
}

//
// Functions for Main
//

int usage();

int main(int argc, const char *argv[]) {
    int nCases, i;
    ifstream file;
    string line;
    pair<int, int> *result;

    // Check...
    if (argc == 1) return usage();
    else if (argc > 2) return usage();

    file.open(argv[1]);

    // Read the number of cases defined
    getline(file, line);
    sscanf(line.c_str(), "%d", &nCases);

    StoreCredit *stores = new StoreCredit[nCases];

    // Read all StoreInfo
    for(i = 0; i < nCases; i++) {
        StoreCredit *store = &stores[i];

        // Set the credit limit
        getline(file, line);
        store->setCreditFromString(line);

        // Set the number of items
        getline(file, line);
        store->setItemsLengthFromString(line);

        // Set the actual items
        getline(file, line);
        store->setItemsFromString(line);

        //stores[i].print();
    }

    for(i = 0; i < nCases; i++) {
        cout << "Case #" << i + 1 << ": ";
        result = stores[i].buyItems();
        cout << result->first + 1 << " " << result->second + 1 << endl;
    }

    // Cleanup
    file.close();

    return 0;
}

int usage() {
    cout << "Store Credit.\n\n";
    cout << "Usage:\n";
    cout << "\tstore-credit <input file>";

    return 1;
}

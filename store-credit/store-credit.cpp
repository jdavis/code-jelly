#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//
// Class Declaration
//

class StoreCredit {
    public:
        void print();
        void setCredit(int c);
        void setItemsLength(int l);
        void setItems(int gItems[]);
        pair<int, int> *buyItems();

    private:
        int credit;
        int itemsLength;
        int items[];
};

//
// Class Definition
//

void StoreCredit::print() {
    cout << "StoreCredit:" << endl;
    cout << "\tTotal Credit: " << credit << endl;
    cout << "\tItems Length:" << itemsLength << endl;
}

void StoreCredit::setCredit(int c) {
    credit = c;
}

void StoreCredit::setItemsLength(int l) {
    itemsLength = l;
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
    int x, l, i;
    int *items;
    ifstream f;
    string line;
    pair<int, int> *result;
    vector<StoreCredit> stores;

    if (argc == 1) return usage();
    else if (argc > 2) return usage();

    f.open(argv[1]);

    // Read all StoreInfo
    while(f.good()) {
        StoreCredit store;

        // Read first value, credit
        getline(f, line);
        sscanf(line.c_str(), "%d", &x);
        store.setCredit(x);

        // Read second value, the number of items
        getline(f, line);
        sscanf(line.c_str(), "%d", &l);
        store.setItemsLength(l);

        // Read next line, all item prices
        items = new int[l];

        getline(f, line);
        for(i = 0; i < l; i++) {
            sscanf(line.c_str(), "%d", &x);
            items[i] = x;
        }

        store.setItems(items);
        stores.push_back(store);

        store.print();

        delete items;
    }

    for(i = 0; i < stores.size(); i++) {
        cout << "Case #" << i + 1 << ": ";
        result = stores[i].buyItems();
        cout << result->first << " " << result->second << endl;
    }

    return 0;
}

int usage() {
    cout << "Store Credit.\n\n";
    cout << "Usage:\n";
    cout << "\tstore-credit <input file>";

    return 1;
}

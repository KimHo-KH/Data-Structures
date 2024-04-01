#include <iostream>

using namespace std;

int main() {
    int savings = 50000;
    int* savingsPtr = &savings;
    int** savingsPtrPtr = &savingsPtr;

    cout << "savings: " << &savings << " " << savings << endl;
    cout << "savingsPtr: " << &savingsPtr << " " << savingsPtr << " " << *savingsPtr << endl;
    cout << "savingsPtrPtr: " << &savingsPtrPtr << " " << savingsPtrPtr << " " << *savingsPtrPtr << endl;
}
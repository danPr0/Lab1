#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "arrayHandlers.h"

using namespace std;

void arrayOutput(int* a, int size) {
    int maxLength = 2;
    for (int i = 0; i < size; i++)
        if (maxLength < int(log10(a[i]) + 1))
            maxLength = int(log10(a[i]) + 1);

    for (int i = 0; i < size; i++) {
        if (i % 5 == 0)
            cout << endl;
        for (int j = 0; j < maxLength - int(log10(a[i]) + 1); j++)
            cout << " ";
        cout << a[i] << " ";
    }
    cout << endl;
}

void fillArrayWithRandom(int* &a, int &size, int n) {
    cout << "Specify array's size (from 1 to " << n << "):" << endl;
    cin >> size;

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 99 + 1;
    }
}

void fillArrayWithKeyboard(int* &a, int &size, int n) {
    int i = 0;

    while (i < n) {
        int value;

        cout << "Enter " << i << " element:" << endl;
        cin >> value;

        if (cin.eof() || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            break;
        }

        size++;
        a[i] = value;
        i++;
    }
}
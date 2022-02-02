#include <iostream>
#include "arrayHandlers.h"

using namespace std;

int getUserInstruction() {
    int instruction;

    cout << "Enter your instruction (1 - fill array with random values, "
            "2 - enter values with keyboard, 9 - exit):" << endl;
    cin >> instruction;
    
    return instruction;
}

int main() {
    int n = 5;
    int size = 0;
    int *a = new int(n + 1);

    while (true) {
        int instruction = getUserInstruction();

        if (instruction == 1) {
            while (size < 1 || size > n) {
                cout << "Specify array's size (from 1 to " << n << "):" << endl;
                cin >> size;
            }
            fillArrayWithRandom(a, size);
            break;
        }
        else if (instruction == 2) {
            size = fillArrayWithKeyboard(a, n);
            break;
        }
        else if (instruction == 9)
            break;
    }

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;

    task4(a, size);
    task5(a, size);
    task7(a, size);
    task10(a, size, 10);
    task11(a, size, 11);

    return 0;
}

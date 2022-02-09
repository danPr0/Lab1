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

bool ifPrime(int a) {
    bool flag = a > 1;
    int d = 2;

    while (flag && d * d <= a) {
        flag = a % d != 0;
        d++;
    }

    return flag;
}

int main() {
    int n = 13;
    int size = 0;
    int *a = new int[1000];

    int instruction = getUserInstruction();

    if (instruction == 1)
        fillArrayWithRandom(a, n, size);
    else if (instruction == 2)
        fillArrayWithKeyboard(a, n, size);
    else if (instruction == 9)
        return 0;

    if (size == 0)
        return 0;

    arrayOutput(a, size);

    additional4(a, size);
    arrayOutput(a, size);

    additional5(a, size);
    arrayOutput(a, size);

    additional7(a, size);
    arrayOutput(a, size);

    try {
        task4(a, size, a + size, a + n);
        arrayOutput(a, size);
    }
    catch (const exception &e) {
        cout << "RANGE CHECK ERROR";
    }

    try {
        task5(a, size, a + size, a + n);
        arrayOutput(a, size);
    }
    catch (const exception &e) {
        cout << "RANGE CHECK ERROR";
    }

    return 0;
}

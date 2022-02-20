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
    int* a = new int [n];
    
    cout << "Lab 2-1. Arrays : K-15 : Proshyn Danylo" << endl;

    int instruction = getUserInstruction();

    if (instruction == 1)
        fillArrayWithRandom(a, size, n);
    else if (instruction == 2)
        fillArrayWithKeyboard(a, size, n);
    else if (instruction == 9)
        return 0;

    if (size == 0)
        return 0;

    arrayOutput(a, size, "Default");

    additional4(a, a + size);
    arrayOutput(a, size, "Additional4");

    additional5(a, a + size);
    arrayOutput(a, size, "Additional5");

    additional7(a, a + size);
    arrayOutput(a, size, "Additional7");

    try {
        task4(a, size, a + size, a + n);
        arrayOutput(a, size, "Task4");
    }
    catch (const exception &e) {
        arrayOutput(a, size, "RANGE CHECK ERROR");
    }

    try {
        task5(a, size, a + size, a + n);
        arrayOutput(a, size, "Task5");
    }
    catch (const exception &e) {
        arrayOutput(a, size, "RANGE CHECK ERROR");
    }

    return 0;
}

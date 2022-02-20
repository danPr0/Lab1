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

    arrayOutput(a, size);

    return 0;
}

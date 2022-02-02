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

    task4(a, size);
    task5(a, size);
    task7(a, size);
    task10(a, size, 10);
    task11(a, size, 11);

    return 0;
}

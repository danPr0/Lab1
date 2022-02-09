#include <iostream>
#include <fstream>
#include "arrayHandlers.h"

using namespace std;

string getInputPath() {
    string path;

    cout << "Enter path to input file" << endl;
    getline(cin, path);

    cout << path;

    if (path.empty())
        path = "in.txt";

    return path;
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
    int *a = new int[13];
    ifstream fin;

    string input_path = getInputPath();
    fin.open(input_path);

    while (!fin.is_open()) {
        input_path = getInputPath();
        fin.open(input_path);
    }

    a = getArrayFromFile(fin, a, size, n, a + size, a + n - 1);

    arrayOutput(a, size);

    fin.close();

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

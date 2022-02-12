#include <iostream>
#include <fstream>
#include "arrayHandlers.h"

using namespace std;

string getInputPath() {
    string path;

    cout << "Enter path to input file" << endl;
    getline(cin, path);

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
    int* a = new int[n];
    int* arr_end = a;
    int* arr_max = a + n;
    ifstream fin;

    string input_path = getInputPath();
    fin.open(input_path);

    while (!fin.is_open()) {
        input_path = getInputPath();
        fin.open(input_path);
    }

    if (!getArrayFromFile(fin, a, arr_end, arr_max))
        return 0;

    fin.close();

    arrayOutput(a, arr_end);

    additional4(a, arr_end);
    arrayOutput(a, arr_end);

    additional5(a, arr_end);
    arrayOutput(a, arr_end);

    additional7(a, arr_end);
    arrayOutput(a, arr_end);

    task4(a, arr_end, arr_max);
    arrayOutput(a, arr_end);

    task5(a, arr_end, arr_max);
    arrayOutput(a, arr_end);

    return 0;
}

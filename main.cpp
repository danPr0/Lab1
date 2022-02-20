#include <iostream>
#include <fstream>
#include "arrayHandlers.h"

using namespace std;

string getInputPath() {
    string path;

    cout << endl << "Enter path to input file" << endl;
    getline(cin, path);

    if (path.empty())
        path = "in.txt";

    return path;
}

string getOutputPath() {
    string path;

    cout << endl << "Enter path to output file" << endl;
    getline(cin, path);

    if (path.empty())
        path = "out.txt";

    return path;
}

void validateInput(std::ifstream &fin) {
    string input_path = getInputPath();
    fin.open(input_path);

    while (!fin.is_open()) {
        input_path = getInputPath();
        fin.open(input_path);
    }
}

void validateOutput(std::ofstream &fout) {
    string output_path = getOutputPath();
    fout.open(output_path);

    while (!fout.is_open()) {
        output_path = getInputPath();
        fout.open(output_path);
    }
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
    ofstream fout;

    cout << "Lab 2-1. Arrays : K-15 : Proshyn Danylo" << endl;

    validateInput(fin);
    if (!getArrayFromFile(fin, a, arr_end, arr_max))
        return 0;

    arrayOutput(a, arr_end, "Default");

    validateOutput(fout);
    saveArrayToFile(fout, a, arr_end);

    additional4(a, arr_end);
    arrayOutput(a, arr_end, "Additional4");

    additional5(a, arr_end);
    arrayOutput(a, arr_end, "Additional5");

    additional7(a, arr_end);
    arrayOutput(a, arr_end, "Additional7");

    task4(a, arr_end, arr_max);
    arrayOutput(a, arr_end, "Task4");

    task5(a, arr_end, arr_max);
    arrayOutput(a, arr_end, "Task5");

    return 0;
}

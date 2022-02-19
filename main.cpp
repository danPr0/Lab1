#include <iostream>
#include <fstream>
#include <vector>
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

string getOutputPath() {
    string path;

    cout << "Enter path to output file" << endl;
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
    vector<int> arr;
    ifstream fin;
    ofstream fout;

    cout << "Lab 2-1. Arrays : K-15 : Proshyn Danylo" << endl;

    validateInput(fin);
    if (!getArrayFromFile(fin, arr))
        return 0;

    arrayOutput(arr, "Default");

    validateOutput(fout);
    saveArrayToFile(fout, arr);

    additional4(arr);
    arrayOutput(arr, "Additional4");

    additional5(arr);
    arrayOutput(arr, "Additional5");

    additional7(arr);
    arrayOutput(arr, "Additional7");

    task4(arr);
    arrayOutput(arr, "Task4");

    task5(arr);
    arrayOutput(arr, "Task5");

    return 0;
}

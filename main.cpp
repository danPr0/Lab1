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
        path = "out.txt";

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

    validateInput(fin);
    if (!getArrayFromFile(fin, arr))
        return 0;

    arrayOutput(arr);

    validateOutput(fout);
    saveArrayToFile(fout, arr);

    additional4(arr);
    arrayOutput(arr);

    additional5(arr);
    arrayOutput(arr);

    additional7(arr);
    arrayOutput(arr);

    task4(arr);
    arrayOutput(arr);

    task5(arr);
    arrayOutput(arr);

    return 0;
}

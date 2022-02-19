#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <fstream>
#include "arrayHandlers.h"

using namespace std;

bool getArrayFromFile(std::ifstream &fin, vector<int> &arr) {
    while (!fin.eof()) {
        int element;
        fin >> element;
        arr.push_back(element);
    }

    fin.close();
    return !arr.empty();
}

void saveArrayToFile(std::ofstream &fout, vector<int> arr) {
    int maxLength = 2;
    for (int & it : arr)
        if (maxLength < int(log10(it) + 1))
            maxLength = int(log10(it) + 1);

    for (size_t i = 0; i < arr.size(); i++) {
        for (int j = 0; j < maxLength - int(log10(arr.at(i)) + 1); j++)
            fout << " ";
        fout << arr.at(i) << " ";
        if ((i + 1) % 5 == 0)
            fout << endl;
    }
}

void arrayOutput(vector<int> arr) {
    int maxLength = 2;
    for (int & it : arr)
        if (maxLength < int(log10(it) + 1))
            maxLength = int(log10(it) + 1);

    for (size_t i = 0; i < arr.size(); i++) {
        for (int j = 0; j < maxLength - int(log10(arr.at(i)) + 1); j++)
            cout << " ";
        cout << arr.at(i) << " ";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    cout << endl;
}

//4 номер з попереднього списку
void additional4(vector<int> &arr) {
    for (int j = 0; j < 2; j++) {
        int t1 = arr.front();

        for (auto it = arr.begin(); it != arr.end(); ++it)
            *it = *(it + 1);

        arr.back() = t1;
    }
}

//5 номер з попереднього списку
void additional5(vector<int> &arr) {
    for (int j = 0; j < 2; j++) {
        int t1 = arr.back();

        for (auto it = arr.end(); it != arr.begin(); --it)
            *it = *(it - 1);

        arr.front() = t1;
    }
}

//7 номер з попереднього списку
void additional7(vector<int> &arr) {
    int size = arr.size();
    int n = size / 2;

    if (arr.size() % 2 == 1) {
        auto t = arr.end();
        for (auto it = arr.end(); it != arr.begin() + n; --it)
            *it = *(it - 1);
        *(arr.begin() + n) = *t;
        n++;
    }

    for (auto it = arr.end(); it != arr.begin() + n - 1; --it) {
        int temp = *(it - n);
        *(it - n) = *it;
        *it = temp;
    }
}

//4 номер з нового списку
void task4(vector<int> &arr) {
    auto minIndex = arr.begin();
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (auto it = arr.begin() + 1; it != arr.end() - 1; ++it) {
        if (*minIndex > *it)
            minIndex = it;
    }

    arr.insert(minIndex + 1, element);
}

//5 номер з попереднього списку
void task5(vector<int> &arr) {
    auto minIndex = arr.begin();
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (auto it = arr.begin() + 1; it != arr.end() - 1; ++it) {
        if (*minIndex > *it)
            minIndex = it;
    }

    arr.insert(minIndex, element);
}

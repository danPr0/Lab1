#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <fstream>
#include "arrayHandlers.h"

using namespace std;

void arrayOutput(int* a, int* arr_end, string task) {
    cout << task;
    int maxLength = 2;
    for (int i = 0; a + i < arr_end; i++)
        if (maxLength < int(log10(a[i]) + 1))
            maxLength = int(log10(a[i]) + 1);

    for (int i = 0; a + i != arr_end; i++) {
        if (i % 5 == 0)
            cout << endl;
        for (int j = 0; j < maxLength - int(log10(a[i]) + 1); j++)
            cout << " ";
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

bool enlargeArray(int* &a, int* &arr_end, int* &arr_max) {
    int n = (int) (arr_max - a);
    int* b = new(nothrow) int[2 * n];

    if (b == nullptr)
        return false;

    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }

    delete [] a;
    a = b;
    arr_end = a + n;
    arr_max = a + n * 2;

    return true;
}

bool getArrayFromFile(ifstream &fin, int* &a, int* &arr_end, int* &arr_max) {
    while (!fin.eof()) {
        fin >> *arr_end;
        arr_end++;

        if (arr_end == arr_max) {
            if (!enlargeArray(a, arr_end, arr_max))
                return false;
            cout << "MEMORY ALLOC " << arr_max - a << endl;
        }
    }

    fin.close();
    return true;
}

void saveArrayToFile(std::ofstream &fout, int* &a, int* &arr_end) {
    int maxLength = 2;
    for (int i = 0; a + i != arr_end; i++)
        if (maxLength < int(log10(a[i]) + 1))
            maxLength = int(log10(a[i]) + 1);

    for (int i = 0; a + i != arr_end; i++) {
        for (int j = 0; j < maxLength - int(log10(a[i]) + 1); j++)
            fout << " ";
        fout << a[i] << " ";
        if ((i + 1) % 5 == 0)
            fout << endl;
    }
}

//4 номер з попереднього списку
void additional4(int* a, int* arr_end) {
    for (int j = 0; j < 2; j++) {
        int t1 = a[0];

        for (int* i = a; i < arr_end - 1; i++)
            *i = *(i + 1);

        *(arr_end - 1) = t1;
    }
}

//5 номер з попереднього списку
void additional5(int* a, int* arr_end) {
    for (int j = 0; j < 2; j++) {
        int t1 = *(arr_end - 1);

        for (int* i = arr_end - 1; i > a; i--)
            *i = *(i - 1);

        a[0] = t1;
    }
}

//7 номер з попереднього списку
void additional7(int* a, int* arr_end) {
    int size = (int)(arr_end - a);
    int n = size / 2;
    if (size % 2 == 1) {
        int t = a[size - 1];
        for (int i = size - 1; i > n; i--)
            a[i] = a[i - 1];
        a[n] = t;
        n++;
    }

    for (int i = size - 1; i > n - 1; i--) {
        int temp = a[i - n];
        a[i - n] = a[i];
        a[i] = temp;
    }
}

//4 номер з нового списку
void task4(int* &a, int* &arr_end, int* &arr_max) {
    if (arr_end == arr_max) {
        enlargeArray(a, arr_end, arr_max);
    }

    int minIndex = 0;
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (int i = 1; a+i != arr_end; i++) {
        if (a[minIndex] > a[i])
            minIndex = i;
    }

    for (int* elem = arr_end; elem != a + minIndex + 1; elem--) {
        *elem = *(elem - 1);
    }
    arr_end++;
    a[minIndex + 1] = element;
}

//5 номер з попереднього списку
void task5(int* &a, int* &arr_end, int* &arr_max) {
    if (arr_end == arr_max) {
        enlargeArray(a, arr_end, arr_max);
    }

    int minIndex = 0;
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (int i = 1; a+i != arr_end; i++) {
        if (a[minIndex] > a[i])
            minIndex = i;
    }

    for (int* elem = arr_end; elem != a + minIndex; elem--) {
        *elem = *(elem - 1);
    }
    arr_end++;
    a[minIndex] = element;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <exception>
#include <stdexcept>
#include "arrayHandlers.h"

using namespace std;

void arrayOutput(int *a, int size) {
    int maxLength = 2;
    for (int i = 0; i < size; i++)
        if (maxLength < int(log10(a[i]) + 1))
            maxLength = int(log10(a[i]) + 1);

    for (int i = 0; i < size; i++) {
        if (i % 5 == 0)
            cout << endl;
        for (int j = 0; j < maxLength - int(log10(a[i]) + 1); j++)
            cout << " ";
        cout << a[i] << " ";
    }
    cout << endl;
}

void fillArrayWithRandom(int *a, int n, int &size) {
    cout << "Specify array's size (from 1 to " << n << "):" << endl;
    cin >> size;

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 99 + 1;
    }
}

void fillArrayWithKeyboard(int *a, int n, int &size) {
    int i = 0;

    while (i < n) {
        int value;

        cout << "Enter " << i << " element:" << endl;
        cin >> value;
        if (cin.eof())
            break;

        size++;
        a[i] = value;
        i++;
    }
}

//4 номер з попереднього списку
void additional4(int *a, int size) {
    for (int j = 0; j < 2; j++) {
        int t1 = a[0];

        for (int i = 0; i < size - 1; i++)
            a[i] = a[i + 1];

        a[size - 1] = t1;
    }
}

//5 номер з попереднього списку
void additional5(int *a, int size) {
    for (int j = 0; j < 2; j++) {
        int t1 = a[size - 1];

        for (int i = size - 1; i > 0; i--)
            a[i] = a[i - 1];

        a[0] = t1;
    }
}

//7 номер з попереднього списку
void additional7(int *a, int size) {
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
void task4(int *a, int &size, int *arr_end, int *arr_max) {
    if (arr_end == arr_max) {
        throw exception();
    }

    int minIndex = 0;
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (int i = 1; a+i != arr_end; i++) {
        if (a[minIndex] > a[i])
            minIndex = i;
    }

    for (int i = size; i > minIndex + 1; i--) {
        a[i] = a[i - 1];
    }
    size++;
    a[minIndex + 1] = element;
}

//5 номер з попереднього списку
void task5(int *a, int &size, int *arr_end, int *arr_max) {
    if (arr_end == arr_max) {
        throw exception();
    }

    int minIndex = 0;
    int element;
    cout << "Enter element:" << endl;
    cin >> element;

    for (int i = 1; a+i != arr_end; i++) {
        if (a[minIndex] > a[i])
            minIndex = i;
    }

    for (int i = size; i > minIndex; i--) {
        a[i] = a[i - 1];
    }
    size++;
    a[minIndex] = element;
}

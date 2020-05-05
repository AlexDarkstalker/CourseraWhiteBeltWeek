//
// Created by aiger on 04.05.2020.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main3() {
    string path = "input.txt";
    ifstream input(path);
    double num;
    cout << fixed << setprecision(3);
    if(input) {
        while(!input.eof()) {
            input >> num;
            cout << num << endl;
        }
    }
    return 0;
}


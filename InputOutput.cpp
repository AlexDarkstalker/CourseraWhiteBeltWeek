//
// Created by aiger on 04.05.2020.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main2() {
    string path = "input.txt";
    ifstream input(path);
    string line;
    if(input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
    return 0;
}

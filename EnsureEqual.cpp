//
// Created by aiger on 05.05.2020.
//
#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

void EnsureEqual (const string& left, const string& right) {
    if ( left != right) {
        stringstream ex;
        ex << left << " != " << right;
        throw runtime_error (ex.str());
    }
}


int main11() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
//
// Created by aiger on 04.05.2020.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main1() {
    string path = "input.txt";
    ifstream input(path);
    ofstream out("output.txt");
    string line;
    if(input) {
        while (getline(input, line)) {
            out << line << endl;
        }
    }
    return 0;
}

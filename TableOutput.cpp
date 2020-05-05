//
// Created by aiger on 04.05.2020.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main4() {
    string path = "input.txt";
    ifstream input(path);
    int n, m;
    double num;
    string line;
    cout << fixed << setprecision(3);
    if(input) {
        input >> n;
        vector<vector<string>> table(n);
        input.ignore(1);
        input >> m;
        getline(input, line);
        for (int i = 0; i < n; i++) {
            for( int j = 0; j < m - 1; j++) {
                getline(input, line, ',');
                table[i].push_back(line);
            }
            getline(input, line);
            table[i].push_back(line);
        }
        cout << right;
        cout << setfill(' ');
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < m - 1; ++j) {
                cout << setw(10) << table[i][j] << " ";
            }
            cout << setw(10) << table[i][m - 1];
            cout << endl;
        }
        for (int i = 0; i < m - 1; ++i)
            cout << setw(10) << table[n-1][i] << " ";
        cout << setw(10) << table[n-1][m - 1];

    }
    return 0;
}


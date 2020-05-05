//
// Created by aiger on 04.05.2020.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Student {
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};

struct Request {
    string request;
    int num_student;
};

int main10() {
    int num_students;
    cin >> num_students;
    vector<Student> students;
    for(int i = 0; i < num_students; ++i) {
        Student student;
        cin >> student.first_name >> student.last_name >> student.day >> student.month >> student.year;
        students.push_back(student);
    }
    int num_requests;
    cin >> num_requests;
    vector<Request> requests;
    for(int i = 0; i < num_requests; ++i) {
        Request request;
        cin >> request.request >> request.num_student;
        requests.push_back(request);
    }
    for(int i = 0; i < num_requests; i++) {
        if (requests[i].request != "name" && requests[i].request != "date") {
            cout << "bad request";
            if(i != requests.size() - 1)
                cout << endl;
        }
        else {
            if(requests[i].request == "name" && requests[i].num_student > 0 && requests[i].num_student <= num_students) {
                cout << students[requests[i].num_student - 1].first_name << " " << students[requests[i].num_student - 1].last_name;
                if(i != num_requests - 1)
                    cout << endl;
            } else if (requests[i].request == "date" && requests[i].num_student > 0 && requests[i].num_student <= num_students) {
                cout << students[requests[i].num_student - 1].day << "." << students[requests[i].num_student - 1].month << "." << students[requests[i].num_student - 1].year;
                if(i != num_requests - 1)
                    cout << endl;
            } else {
                cout << "bad request";
                if(i != requests.size() - 1)
                    cout << endl;
            }
        }
    }

    return 0;
}
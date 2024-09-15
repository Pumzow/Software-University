#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "BaseStudent.h"

using namespace std;

class Student : public BaseStudent {
public:
    void init(istream& iS)
    {
        iS >> name >> grade;
    }
};

typedef vector<shared_ptr<Student>>& StudentsData;
typedef vector<size_t> Totals;

bool readStudent(StudentsData buffer, string data)
{
    if (data == "end") return false;
    istringstream ss(data);
    auto x = new Student();
    x->init(ss);
    buffer.push_back(shared_ptr<Student>(x));
    return true;
}

Totals processStudents(StudentsData data)
{
    Totals t(10, 0);
    for (auto s : data) {
        int g = s->getGrade() / 10; // intended truncate
        t[g]++;
    }
    return t;
}
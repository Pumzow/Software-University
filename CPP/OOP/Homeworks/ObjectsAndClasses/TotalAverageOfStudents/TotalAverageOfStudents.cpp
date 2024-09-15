#include <iostream>

using namespace std;

class Student
{
	string _firstName, _lastName;
	double _grade;

public:
	Student(string firstName, string lastName, double grade)
	{
		_firstName = firstName;
		_lastName = lastName;
		_grade = grade;
	}

	void print()
	{
		cout << _firstName << " " << _lastName << " " << _grade << endl;
	}
};

int main()
{
	int studentsCount;
	double totalGrade = 0;

	cin >> studentsCount;
	if (studentsCount <= 0)
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	for (size_t i = 0; i < studentsCount; i++)
	{
		string firstName, lastName;
		double grade;

		cin >> firstName >> lastName;
		cin >> grade;
		Student student(firstName, lastName, grade);
		student.print();
		totalGrade += grade;
	}
	cout << totalGrade / studentsCount << endl;
}

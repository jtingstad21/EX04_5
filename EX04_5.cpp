﻿// EX04_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// 14/20

//PT -- as in EX04_04, put these in separate header files

class Course
{
private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;

public:
	Course(const string& courseName, int capacity)
	{
		numberOfStudents = 0;
		this->courseName = courseName;
		this->capacity = capacity;
		students = new string[capacity];
	}
	string getCourseName() const
	{
		return courseName;
	}
	void dropStudent(const string& name)
	{
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students[i] == name)
				students[i] = "";
		}
		//PT -- need to slide students that are passed the given student back one slot, rather than have a student named ""
		// -2
		/*
		int i=0;
		//find the student
		while (i < numberOfStudents && students[i] != name)
			i++;
		//Found them, slide the other students back one slot
		for (; i<numberOfStudents-1; i++) {
			students[i] = students[i+1];
		}
		*/

		numberOfStudents--;
	}
	void addStudent(const string& name)
	{
		if (numberOfStudents > this->capacity)
		{
			string* newList = new string[capacity * 2];

			for (int i = 0; i < capacity; i++)
			{
				newList[i] = students[i];
			}
			
			//PT -- Now have students point to the new array
			// -1
			/*
			delete[] students;
			students = newList;
			*/
		}

		students[numberOfStudents] = name;
		numberOfStudents++;

		//PT -- Don't need this at all.
		//  -2
		string* newStudentArray = new string[numberOfStudents * 2];

	}
	string* getStudents() const
	{
		return students;
	}
	int getNumberOfStudents() const
	{
		return numberOfStudents;
	}
	void clear()
	{
		//PT -- actually, all you need to do is set numberOfStudents to 0
		/*
		numberOfStudents = 0;
		*/
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students[i] != "")
				students[i] = "";
			numberOfStudents--;
		}
	}
	Course(const Course& course)
	{
		courseName = course.courseName;
		numberOfStudents = course.numberOfStudents;
		capacity = course.capacity;
		students = new string[capacity];
		
		//PT -- copy the students over
		// -2
		/*
		for (int i=0; i<capacity; i++) {
			students[i] = course.students[i];
		}
		*/
	}
	~Course()
	{
		delete [] students;
	}
};

int main()
{
	Course c1("Calc", 3);
	Course c2(c1);
	c1.addStudent("Chris");
	c1.addStudent("Nikki");
	c1.addStudent("John");

	c1.dropStudent("John");

	c1.clear();

	string* studentList = c1.getStudents();
	int numOfStu = c1.getNumberOfStudents();
	for (int i = 0; i < numOfStu; i++)
		cout << studentList[i] << endl;

	delete [] studentList;

    return 0;
}


//----------------------------------------------------------------------------------------------------
// File list01.cpp defines class List. List is a static array of numbers.
//----------------------------------------------------------------------------------------------------
// Author: Mr. Connor Bowlan
// Student ID: *20319760
// Course: CMSC 2613 - Programming II
// CRN: 21256, Spring, 2015
// Project: p01
// Due: January 23, 2015
// Account: tt111
//----------------------------------------------------------------------------------------------------
// Copyright January, 2015 by Mr. Connor Bowlan
// Do not reproduce without permission from Mr. Connor Bowlan
//----------------------------------------------------------------------------------------------------
// C++ Standard Include Files
//----------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream> /* For ifstream and ofstream */
#include <string.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
//----------------------------------------------------------------------------------------------------
struct ListException {
	ListException(const char* m)
	{
		cout << endl;
		cout << "I am the list and I am" << m;
		cout << endl;
	}
};
//----------------------------------------------------------------------------------------------------
// Class List contains member functions to sort and find the mean,
// median, and mode of an array of numbers.
//----------------------------------------------------------------------------------------------------

class List
{
	int size; // Available elements in array
	int count; // Occupied - Index of next available
	int* L; // Reference to L - allocating memory
	
	public:
	List(int sz = 100): size(sz), count(0)
	{
		L = new int[size];
	}
	~List() {
		if(L) {
			delete[] L;
		}
	}

	bool isFull(void);

	bool isEmpty(void);

	void Insert(int v);

	void Scan(istream& input);
	
	void Print(ostream& output);

	void Print(ostream& output, double result);
	
	void Print(ostream& output, int result);
	
	void Sort();
	
	double findMean();
	
	double findMedian();
	
	int findMode();
};
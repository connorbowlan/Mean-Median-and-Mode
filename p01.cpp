//----------------------------------------------------------------------------------------------------
// File p01.cpp exercises finding mean, median, and mode
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
// Application Include Files
//----------------------------------------------------------------------------------------------------
#include "List01.h"
//----------------------------------------------------------------------------------------------------
// File Exception - too many arguments
//----------------------------------------------------------------------------------------------------
struct FileException
{
	FileException(const char* fileName)
	{
		cout << endl;
		cout << "File " << fileName << "could not be opened.";
        cout << endl;
    }
};
//----------------------------------------------------------------------------------------------------
// Command Line Exception - too many arguments
//----------------------------------------------------------------------------------------------------
struct CommandLineException {
	CommandLineException(int max, int actual)
	{
		cout << endl;
		cout << "Too many arguments on the command line.";
		cout << endl;
		cout << "A maximum of " << max << " arguments may appear on the command line.";
		cout << endl;
		cout << actual << " arguments were on the command line.";
		cout << endl;
	}
};
//----------------------------------------------------------------------------------------------------
// PRIMARY FUNCTION TO EXECUTE INPUT TO OUTPUT GOES HERE
//----------------------------------------------------------------------------------------------------
void mmmMGR(istream &input, ostream &output)
{
List L;
L.Scan(input);
// L.Print(cout); // COMMENT OUT PRINT LATER
L.Sort();
// L.Print(cout); // COMMENT OUT PRINT LATER

output << left << setw(10) << "Mean" << "=" << setw(10) << fixed << setprecision(2);
output << setw(10) << right << "";
L.Print(output, L.findMean());
output << endl;

output << left << setw(10) << "Median" << "=" << setw(10) << setprecision(0);
output << setw(10) << "";
L.Print(output, L.findMedian());
output << endl;

output << left << setw(10) << "Mode" << "=";
output << setw(10) << "";
L.Print(output, L.findMode());
output << endl;

}
//----------------------------------------------------------------------------------------------------
// Function main processes command line arguments
//----------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	try {
		char inputFileName[255], outputFileName[255];
		
		switch(argc)
		{
			case 1:
				cout << "Enter the input file name. ";
				cin >> inputFileName;
				cout << "Enter the output file name. ";
				cin >> outputFileName;
			break;
			
			case 2:
				cout << argv[1] << endl;
				cout << argv[0] << endl;
				strcpy(inputFileName, argv[1]);
				cout << "Enter the output file name. ";
				cin >> outputFileName;
			break;
			
			case 3:
                strcpy(inputFileName, argv[1]);
                strcpy(outputFileName, argv[2]);
			break;
			
			default:
				throw CommandLineException(2, argc-1);
			break;
		}
		
		/* Attempts to open files and throws error if not possible */
		ifstream input(inputFileName);
		if(!input)
		{
			throw FileException(inputFileName);
		}
		ofstream output(outputFileName);
		if(!output)
		{
			throw FileException(outputFileName);
		}
		
		/* Function that processes and outputs data */
		mmmMGR(input, output);

		output.close();
		input.close();
			}
	catch (...)
	{
		cout << endl;
		cout << "Program terminated.";
		cout << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
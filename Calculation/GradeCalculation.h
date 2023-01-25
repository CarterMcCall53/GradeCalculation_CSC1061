#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class GradeCalculation {
private:
	struct GradeRecord
	{
		int studentNum;
		string firstName, lastName, answers;
		double score, percent;
		char grade;
	};
	char DELIM = ',';
	int recordsSize, anSize;

	vector<GradeCalculation> recs;
	GradeRecord records[25];
public:
	void readRecords(string);
	void calculateGrades();
	void printGrades();
};
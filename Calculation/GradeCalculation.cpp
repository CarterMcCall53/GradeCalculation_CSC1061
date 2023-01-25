#include "GradeCalculation.h";

void GradeCalculation::readRecords(string file) {
	string line;
	ifstream input;
	int recNum = 0;
	char delim;
	input.open(file);
	if (input) {
		while (!input.eof()) {
			getline(input, line);
			delim = (int)line.find(DELIM);
			records[recNum].studentNum = stoi(line.substr(0, delim));
			line = line.substr(delim + 1, line.size());
			delim = line.find(DELIM);
			records[recNum].firstName = line.substr(0, delim);
			line = line.substr(delim + 1, line.size());
			delim = line.find(DELIM);
			records[recNum].lastName = line.substr(0, delim);
			line = line.substr(delim + 1, line.size());
			records[recNum].answers = line;
			recNum++;
		}
	}
	recordsSize = recNum;
}

void GradeCalculation::calculateGrades() {
	string answers = records[0].answers;
	anSize = answers.size();
	int score = 0;
	for (int i = 1; i < recordsSize; i++) {
		score = 0;
		for (int j = 0; j < anSize; j++) {
			if (answers[j] == records[i].answers[j]) score++;
		}
		records[i].score = score;
		records[i].percent = (double)(100.0 * score / anSize);
		if (records[i].percent >= 90.0) records[i].grade = 'A';
		else if (records[i].percent >= 80) records[i].grade = 'B';
		else if (records[i].percent >= 70) records[i].grade = 'C';
		else if (records[i].percent >= 60) records[i].grade = 'D';
		else records[i].grade = 'F';
	}
}

void GradeCalculation::printGrades() {
	for (int i = 1; i < recordsSize; i++) {
		cout << records[i].firstName << " " << records[i].lastName << " scored: " <<
			records[i].score << "/" << anSize << " - " << records[i].percent <<
			"% - " << records[i].grade << endl;
	}
}
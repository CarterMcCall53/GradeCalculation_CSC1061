/* Main.cpp
 * Wayne Cook
 * 12 January 2023
 * Purpose:
 *		Read names and answers into a structure. Calcualte grade.
 *		Has method to print summaries.
 */
#include "GradeCalculation.h"

int main() {
	GradeCalculation gc;
	gc.readRecords("TestAnswers.txt");
	gc.calculateGrades();
	gc.printGrades();
}
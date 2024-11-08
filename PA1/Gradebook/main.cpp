#include <iostream>
#include "helpers.h"
using namespace std;

int main() {

    // declare variables
    const int total_exams = 5; // total number of exams
    float exam_scores[total_exams] = {99, 87, 94, 92, 85}; // array to hold exam scores

    const int total_pas = 5; // total number of PAs
    float pa_scores[total_pas] = {100, 94, 100, 84, 70}; // array to hold PA scores

    // calculate totalCategory scores
    float pa_total = categoryTotal(pa_scores, total_pas); 
    cout << "HW total score: " << pa_total << endl; // output should be 0.896

    // calculate grade using each method
    float grade_m1 = gradeCalcM1(exam_scores, total_exams, pa_scores, total_pas); 
    float grade_m2 = gradeCalcM2(exam_scores, total_exams, pa_scores, total_pas);
    cout << "Numerical grade using Method 1: " << grade_m1 << endl; // output should be 91.64
    cout << "Numerical grade using Method 2: " << grade_m2 << endl; // output should be 90.32

    // calculate letter grade when Method 2 us used 
    cout << "Letter Grade: " << letterGrade(grade_m1) << endl; // should output A

    // calculate best letter grade
    cout << "Best letter grade is " << bestGrade(grade_m1, grade_m2) << endl; // should output A

}

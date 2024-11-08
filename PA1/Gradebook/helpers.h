#include <iostream>
#include <string>
using namespace std;

/* This function calculates the total percentage of all
 * the scores in the array that is passed into it. This function
 * also assumes that each assignment is out of a total 100 points.
 *
 * Parameters:
 *    float arr[]-- the array that holds the values to be averaged
 *    int size -- the size of arr[]
 *
 * Return value:
 *    float result -- the average of all the data
 */
float categoryTotal(float arr[], int size);


/* This function drops the lowest test score and then calculates
 * the grade using the formula:
 * 0.6 * (test_scores_percentage) + 0.4 * (hw_scores_percentage)
 *
 * Parameters:
 *    float test_scores[]-- the array that holds all the exam scores
 *    int test_scores_size -- the size of test_scores[]
 *    float hw_scores[]-- the array that holds all the PA scores
 *    int hw_scores_size -- the size of hw_scores[]
 *
 * Return value:
 *    float total_score -- the total numerical score calculated using Method 1
 */
float gradeCalcM1(float test_scores[], int test_scores_size, float hw_scores[], int hw_scores_size);


/* This function  calculates the grade using the formula:
 * 0.4 * (test_scores_average) + 0.6 * (hw_scores_average)
 *
 * Parameters:
 *    float test_scores[]-- the array that holds all the exam scores
 *    int test_scores_size -- the size of test_scores[]
 *    float hw_scores[]-- the array that holds all the PA scores
 *    int hw_scores_size -- the size of hw_scores[]
 *
 * Return value:
 *    float total_score -- the total numerical score calculated using Method 2
 */
float gradeCalcM2(float test_scores[], int test_scores_size, float hw_scores[], int hw_scores_size);


/* This function finds the letter grade
 * corresponding to the numerical score
 *
 * Parameters:
 *    float num_score -- the numerical score
 *
 * Return value:
 *    char -- the letter grade corresponding to num_score
 */
char letterGrade(float num_score);


/* This function returns the letter grade 
 * that corresponds to the better score of
 * the two input scores 
 *
 * Parameters:
 *    float score1 -- the first numerical score
 *    float score2 -- the second numerical score
 *
 * Return value:
 *    char -- the letter grade corresponding to the best num_score
 */
char bestGrade(float score1, float score2);

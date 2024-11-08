#include "helpers.h"
using namespace std;

float categoryTotal(float arr[], int size){

    float total = 0;
    for(int i=0; i < size; i++){
        total += arr[i];
    }
    return total/(size * 100);

}

float gradeCalcM1(float test_scores[], int test_scores_size, float hw_scores[], int hw_scores_size) {

    float min_score = test_scores[0];
    float total_tests = 0;
    for (int i=0; i < test_scores_size; i++){
        total_tests += test_scores[i];
        if(test_scores[i] < min_score){
            min_score = test_scores[i];
        }
    }
    total_tests -= min_score;
    float test_avg = total_tests/ ((test_scores_size-1)*100);
    float hw_avg = categoryTotal(hw_scores,hw_scores_size);
    return (0.6 * test_avg + 0.4 * hw_avg) * 100; 
}

float gradeCalcM2(float test_scores[], int test_scores_size, float hw_scores[], int hw_scores_size){

    float total_tests = 0;
    for (int i=0; i < test_scores_size; i++){
        total_tests += test_scores[i];
    }
    float test_avg = total_tests/ (test_scores_size*100);
    float hw_avg = categoryTotal(hw_scores,hw_scores_size);
    return (0.4 * test_avg + 0.6 * hw_avg) * 100; 

}

char letterGrade(float num_score) {

    if(num_score >= 90){
        return 'A';
    } else if (num_score >= 80){
        return 'B';
    }  else if (num_score >= 70){
        return 'C';
    } else if (num_score >= 60){
        return 'D';
    } else {
        return 'F';
    }

}

char bestGrade(float score1, float score2) {
    float best_score = (score1 > score2) ? score1 : score2;
    return letterGrade(best_score);
}

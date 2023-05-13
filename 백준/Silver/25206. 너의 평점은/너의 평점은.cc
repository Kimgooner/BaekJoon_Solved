#include <iostream>
#include <iomanip>

int main() {
    std::string name, score;
    double grade, grade_score, grade_sum = 0, grade_score_sum = 0;
    for(int i = 0; i < 20; i++) {
        std::cin >> name >> grade >> score;
        if (score == "A+")
            grade_score = 4.5;
        else if (score == "A0")
            grade_score = 4.0;
        else if (score == "B+")
            grade_score = 3.5;
        else if (score == "B0")
            grade_score = 3.0;
        else if (score == "C+")
            grade_score = 2.5;
        else if (score == "C0")
            grade_score = 2.0;
        else if (score == "D+")
            grade_score = 1.5;
        else if (score == "D0")
            grade_score = 1.0;
        else if (score == "F")
            grade_score = 0.0;
        else if (score == "P")
            continue;
        grade_sum += grade;
        grade_score_sum += grade * grade_score;
    }
    std::cout << std::fixed << std::setprecision(6);
    std::cout << grade_score_sum / grade_sum;
}

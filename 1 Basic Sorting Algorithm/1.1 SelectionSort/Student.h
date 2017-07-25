//
// Created by 廖佳玲 on 7/24/17.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct  Student{

    string name;
    int score;

    // Overload the operator < for the comparison
    bool operator<(const Student &otherStudent){

        // If two students have the same score, student with smaller name will be the first
        return score != otherStudent.score? score < otherStudent.score : name < otherStudent.name;
        // Currently the sort is in ascending order
        // If change to return score > otherStudent.score then the sort is in descending order
    }

    // Overload the operator << for the output stream format
    friend ostream& operator<<(ostream &os, const Student &student){

        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //SELECTIONSORT_STUDENT_H

#pragma once

#include "Assessment.h"

using namespace std;

// genetic test sub class
class GeneticTest : public Assessment {
public:
    // constructor 
    GeneticTest() {
        // all 5 questions 
        questions = { 
            "Do you have genetic marker APOE-e4?",
            "Do you have the genetic marker for Amyloid Precursor Protein (APP) on chromosome 21?",
            "Do you have the genetic marker for Presenilin 1 (PSEN1) on chromosome 14?",
            "Do you have the genetic marker for Presenilin 2 (PSEN2) on chromosome 1?",
            "Do you have a family member who has been diagnosed with Alzheimer's Disease?" 
        };

        // options to the question in the corresponding index **ASK ABOUT THIS**
        options = { 
            {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"} 
        };
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector
        vector<char> correctAnswers = { 'B', 'B', 'B', 'B', 'B' };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == '\0' || answers[i] != correctAnswers[i]) {
                numIncorrect++;
            }
        }

        // determine risk score
        // 5 points possible
        riskScore = numIncorrect / 5 * 10;
    }
};
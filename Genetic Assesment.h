#pragma once
#include "Assesment.h"
// genetic test sub class
class GeneticTest : public Assesment {
private:
    vector<string> geneticQuestions;
    vector<vector<string>> geneticOptions;
    vector<string> geneticAnswer;
    double geneticRiskScore;

public:
    // constructor 
    GeneticTest() {
        // all 5 questions 
        geneticQuestions = { "Do you have genetic marker APOE-e4?",
            "Do you have the genetic marker for Amyloid Precursor Protein (APP) on chromosome 21?",
            "Do you have the genetic marker for Presenilin 1 (PSEN1) on chromosome 14?",
            "Do you have the genetic marker for Presenilin 2 (PSEN2) on chromosome 1?",
            "Do you have a family member who has been diagnosed with Alzheimer's Disease?" };

        // options to the question in the corresponding index **ASK ABOUT THIS**
        geneticOptions = { {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"},
            {"Yes", "No"} };
    }

    // function to display the question to the user with options
    void displayQuestion(int index) {
        // print the question
        if (index >= 0 && index < geneticQuestions.size()) {
            cout << "Question: " << index + 1 << ": " << geneticQuestions[index] << endl;

            // char to represent the options
            char answerOptions = 'A';

            // print the options to the user
            for (const string& option : geneticOptions[index]) {
                cout << answerOptions << ") " << option << endl;
                // increment the char
                answerOptions++;
            }
        }
        // alert if there is an error
        else {
            cout << "Invalid Question." << endl;
        }
    }

    // record response function to add answer to the vector
    void recordResponse(int index, const string& userAnswer) {
        // make sure the answer is valid
        if (index >= 0 && index < geneticAnswer.size()) {
            // assign to the proper index in the array
            geneticAnswer[index] = userAnswer;
        }
        else {
            // alert if invalid
            cout << "Invalid response." << endl;
        }
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector
        vector <string> correctAnswers = { "A", "A", "A", "A", "A"};

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < geneticAnswer.size(); i++) {
            if (geneticAnswer[i].empty() || geneticAnswer[i] != correctAnswers[i] && i <= 10) {
                numIncorrect++;
            }
        }

        // determine risk score
        // 5 points possible
        geneticRiskScore = numIncorrect / 5 * 10;
    }

    // return risk score
    double getRisk() {
        return geneticRiskScore;
    }
};
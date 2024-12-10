#pragma once
#include "Assesment.h"
// lifestyle test sub class
class LifestyleTest : public Assesment {
private:
    vector<string> lifestyleQuestions;
    vector<vector<string>> lifestyleOptions;
    vector<string> lifestyleAnswer;
    double lifestyleRiskScore;

public:
    // constructor 
    LifestyleTest() {
        // all 10 questions 
        lifestyleQuestions = { "How often do you drink water in a day?",
            "Do you smoke cigarettes?",
            "How often do you consume alcohol?",
            "How often do you eat fruits or vegetables?",
            "Do you have a regular exercise routine?",
            "How often do you visit a doctor for checkups?",
            "Do you take any prescribed medications as directed?",
            "How often do you get at least 6-8 hours of sleep per night?",
            "How often do you eat fast food or unhealthy snacks?",
            "Do you feel confident managing your own hygiene (bathing, grooming, etc.)?" };

        // options to the question in the corresponding index
        lifestyleOptions = { {"Frequently (6 or more glasses)", "Occasionally (2-5 glasses)", "Rarely (1 or fewer glasses)", "I don't know"},
            {"Yes, regularly", "Occasionally", "No, I don't smoke", "I don't know"},
            {"Daily", "Occassionally", "Rarely or never", "I don't know"},
            {"Everyday", "A few times a week", "Rarely or never", "I don't know"},
            {"Yes, daily", "Occasionally (a few times a week)", "No, I don't exercise", "I don't know"},
            {"Regularly (at least once a year)", "Occasionally (every few years)", "Rarely or never", "I don't know"},
            {"Yes, always", "Sometimes", "No, I often forget", "I don't know"},
            {"Almost ever night", "Occassionally", "Rarely", "I don't know"},
            {"Frequently (multiple times a week)", "Occasionally (once or twice a week)", "Rarely or never", "I don't know"},
            {"Yes, I manage it well", "I need occasional help", "I need regular assistance", "I don't know"} };
    }

    // function to display the question to the user with options
    void displayQuestion(int index) {
        // print the question
        if (index >= 0 && index < lifestyleQuestions.size()) {
            cout << "Question: " << index + 1 << ": " << lifestyleQuestions[index] << endl;

            // char to represent the options
            char answerOptions = 'A';

            // print the options to the user
            for (const string& option : lifestyleOptions[index]) {
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
        if (index >= 0 && index < lifestyleAnswer.size()) {
            // assign to the proper index in the array
            lifestyleAnswer[index] = userAnswer;
        }
        else {
            // alert if invalid
            cout << "Invalid response." << endl;
        }
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector
        vector <string> correctAnswers = { "A", "C", "C", "A", "A", "A", "A", "A", "C", "A" };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < lifestyleAnswer.size(); i++) {
            if (lifestyleAnswer[i].empty() || lifestyleAnswer[i] != correctAnswers[i]) {
                numIncorrect++;
            }
        }

        // determine risk score
        // 10 points possible
        lifestyleRiskScore = numIncorrect / 10 * 10;
    }

    // return risk score
    double getRisk() {
        return lifestyleRiskScore;
    }
};
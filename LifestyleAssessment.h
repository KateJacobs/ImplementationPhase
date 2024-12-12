#pragma once

#include "Assessment.h"

using namespace std;

// lifestyle test sub class
class LifestyleTest : public Assessment {
public:
    // constructor 
    LifestyleTest() {
        // all 10 questions 
        questions = {
            "How often do you drink water in a day?",
            "Do you smoke cigarettes?",
            "How often do you consume alcohol?",
            "How often do you eat fruits or vegetables?",
            "Do you have a regular exercise routine?",
            "How often do you visit a doctor for checkups?",
            "Do you take any prescribed medications as directed?",
            "How often do you get at least 6-8 hours of sleep per night?",
            "How often do you eat fast food or unhealthy snacks?",
            "Do you feel confident managing your own hygiene (bathing, grooming, etc.)?"
        };

        // options to the question in the corresponding index
        options = {
            {"Frequently (6 or more glasses)", "Occasionally (2-5 glasses)", "Rarely (1 or fewer glasses)", "I don't know"},
            {"Yes, regularly", "Occasionally", "No, I don't smoke", "I don't know"},
            {"Daily", "Occassionally", "Rarely or never", "I don't know"},
            {"Everyday", "A few times a week", "Rarely or never", "I don't know"},
            {"Yes, daily", "Occasionally (a few times a week)", "No, I don't exercise", "I don't know"},
            {"Regularly (at least once a year)", "Occasionally (every few years)", "Rarely or never", "I don't know"},
            {"Yes, always", "Sometimes", "No, I often forget", "I don't know"},
            {"Almost ever night", "Occassionally", "Rarely", "I don't know"},
            {"Frequently (multiple times a week)", "Occasionally (once or twice a week)", "Rarely or never", "I don't know"},
            {"Yes, I manage it well", "I need occasional help", "I need regular assistance", "I don't know"}
        };

        answers.resize(questions.size(), '\0');
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector
        vector<char> correctAnswers = { 'A', 'C', 'C', 'A', 'A', 'A', 'A', 'A', 'C', 'A' };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == '\0' || answers[i] != correctAnswers[i]) {
                numIncorrect++;
            }
        }

        // determine risk score
        // 10 points possible
        riskScore = 10 - numIncorrect;
    }
};
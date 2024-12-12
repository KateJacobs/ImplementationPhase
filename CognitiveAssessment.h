#pragma once

#include "Assessment.h"

using namespace std;

// cognitive test sub class
class CognitiveTest : public Assessment {
public:
    // constructor
    CognitiveTest() {
        // all 20 questions 
        questions = {
            "Which of these is a color?",
            "What is 1 + 1?",
            "Which of these is a fruit?",
            "What do you use to drink water?",
            "Which of these is a number?",
            "What is the opposite of day?",
            "Which of these is used for writing?",
            "What is 2 + 2?",
            "What do you wear on your feet?",
            "What do we drink when we are thirsty?",
            "What do we call the season when leaves fall off trees?",
            "Which of these is used for cutting paper?",
            "How many legs does a dog have?",
            "What is the third month of the year?",
            "Which of these is hot?",
            "What do you see in the sky during the day?",
            "What is the shape with three sides called?",
            "If you have 3 apples and give 1 away, how many are left?",
            "What is 10 - 7?",
            "Which of these is a day of the week?" };

        // options to the question in the corresponding index
        options = {
            {"Red", "Chair", "Dog", "I don't know"},
            {"1", "2", "3", "I don't know"},
            {"Apple", "Chair", "Table", "I don't know"},
            {"Glass", "Shoes", "Blanket", "I don't know"},
            {"Five", "Tree", "Dog", "I don't know"},
            {"Morning", "Night", "Afternoon", "I don't know"},
            {"Pen", "Shoe", "Spoon", "I don't know"},
            {"3", "4", "5", "I don't know"},
            {"Shoes", "Hat", "Jacket", "I don't know"},
            {"Water", "Rock", "Paper", "I don't know"},
            {"Summer", "Winter", "Autumn", "I don't know"},
            {"Scissors", "Fork", "Plate", "I don't know"},
            {"Two", "Four", "Six", "I don't know"},
            {"January", "March", "May", "I don't know"},
            {"Ice", "Fire", "Snow", "I don't know"},
            {"Sun", "Moon", "Stars", "I don't know"},
            {"Square", "Triangle", "Circle", "I don't know"},
            {"2", "3", "4", "I don't know"},
            {"1", "2", "3", "I don't know"},
            {"Monday", "January", "Summer", "I don't know"}
        };

        answers.resize(questions.size(), '\0');
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector 
        vector<char> correctAnswers = { 'A', 'B', 'A', 'A', 'A', 'B', 'A', 'B', 'A', 'A', 'C', 'A', 'B', 'B', 'B', 'A', 'B', 'A', 'C', 'A' };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == '\0' || answers[i] != correctAnswers[i] && i <= 10) {
                numIncorrect++;
            }
            else if (answers[i] == '\0' || answers[i] != correctAnswers[i] && (i > 10 && i <= 17)) {
                numIncorrect = numIncorrect + 2;
            }
            else if (answers[i] == '\0' || answers[i] != correctAnswers[i] && (i <= 10)) {
                numIncorrect = numIncorrect + 3;
            }
        }

        // determine risk score
        // 33 points possible
        riskScore = 33 - numIncorrect;
    }
};
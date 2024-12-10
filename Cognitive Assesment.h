#pragma once
#include "Assesment.h"
// cognitive test sub class
class CognitiveTest : public Assesment {
private:
    vector<string> cognitiveQuestions;
    vector<vector<string>> cognitiveOptions;
    vector<string> cognitiveAnswer;
    double cognitiveRiskScore;

public:
    // constructor 
    CognitiveTest() {
        // all 20 questions 
        cognitiveQuestions = { "Which of these is a color?",
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
        cognitiveOptions = { {"Red", "Chair", "Dog", "I don't know"},
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
            {"Monday", "January", "Summer", "I don't know"} };
    }

    // function to display the question to the user with options
    void displayQuestion(int index) {
        // print the question
        if (index >= 0 && index < cognitiveQuestions.size()) {
            cout << "Question: " << index + 1 << ": " << cognitiveQuestions[index] << endl;

            // char to represent the options
            char answerOptions = 'A';

            // print the options to the user
            for (const string& option : cognitiveOptions[index]) {
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
        if (index >= 0 && index < cognitiveAnswer.size()) {
            // assign to the proper index in the array
            cognitiveAnswer[index] = userAnswer;
        }
        else {
            // alert if invalid
            cout << "Invalid response." << endl;
        }
    }

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector 
        vector <string> correctAnswers = { "A", "B", "A", "A", "A", "B", "A", "B", "A", "A", "C", "A", "B", "B", "B", "A", "B", "A", "C", "A" };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < cognitiveAnswer.size(); i++) {
            if (cognitiveAnswer[i].empty() || cognitiveAnswer[i] != correctAnswers[i] && i <= 10) {
                numIncorrect++;
            }
            else if (cognitiveAnswer[i].empty() || cognitiveAnswer[i] != correctAnswers[i] && (i > 10 && i <= 17)) {
                numIncorrect = numIncorrect + 2;
            }
            else {
                numIncorrect = numIncorrect + 3;
            }
        }

        // determine risk score
        // 33 points possible
        cognitiveRiskScore = numIncorrect / 33 * 10;
    }

    // return risk score
    double getRisk() {
        return cognitiveRiskScore;
    }
};
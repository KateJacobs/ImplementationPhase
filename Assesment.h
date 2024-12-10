#pragma once
# include <iostream>
# include <string>
# include <iomanip>
# include <vector>
using namespace std;


// assesment class
class Assesment {
protected:
    // create vectors to hold each aspect of the question
    vector<string> questions;
    vector<vector<string>> options;
    vector<string> answer;
    double riskScore;

public:
    // conctructor 
    Assesment() {
        riskScore = 0;
    }

    // function to display the question to the user with options
    void displayQuestion(int index) {
        // print the question
        if (index >= 0 && index < questions.size()) {
            cout << "Question: " << index + 1 << ": " << questions[index] << endl;

            // char to represent the options
            char answerOptions = 'A';

            // print the options to the user
            for (const string& option : options[index]) {
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
        if (index >= 0 && index < answer.size()) {
            // assign to the proper index in the array
            answer[index] = userAnswer;
        }
        else {
            // alert if invalid
            cout << "Invalid response." << endl;
        }
    }

    void calculateRisk()
    {
        //Overridden in each subclass
    }

    // return risk score
    double getRisk() {
        return riskScore;
    }
};
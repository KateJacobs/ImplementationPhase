#pragma once

/*

Assessment.h

This header file provides:
    - Storage for questions, options, and user responses.
    - Methods to display questions and record user responses.
    - A pure virtual function for risk calculation to be implemented by derived classes.
    - A method to retrieve the risk score.

The Assessment class provides the structure for each of its assessment sub-classes. 
Vectors should be initialized with the questions and options in each sub-class constructor.

*/

#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Assessment {
protected:
    vector<string> questions; // List of questions
    vector<vector<string>> options; // List of options
    vector<char> answers; // List of answers
    double riskScore; // Calculated risk score

public:
    Assessment() : riskScore(0.0) {} // Constructor that initializes riskScore to 0

    // Displays the question and its options for the given index
    void displayQuestion(int index) const {
        if (index >= 0 && index < questions.size()) { // Check if index is valid
            cout << "\nQuestion " << index + 1 << ": " << questions[index] << "\n"; // Display question

            char answerOptions = 'A'; // Initialize a character for different options

            // Iterate through the options for the current question
            for (const string& option : options[index]) {
                cout << answerOptions << ") " << option << "\n"; // Display options and their characters
                answerOptions++; // Increment the option counter
            }
        }
        else {
            // Display an error message if the index is invalid
            cout << "Invalid question index.\n";
        }
    }

    // Records user response for each question
    void recordResponse(int index, char userResponse) {
        if (index >= 0 && index < answers.size() && isalpha(userResponse)) { // Check if question index and response are valid
            userResponse = toupper(userResponse); // Convert reponse to uppercase

            // Check if response is within the available options (A, B, C, D for cognitive and lifestyle; A, B for genetic)
            if (userResponse >= 'A' && userResponse < 'A' + options[index].size()) {
                answers[index] = userResponse; // Store response in the answers vector
            }
            else {
                // Display an error if the response is outside the valid options
                cout << "Invalid response. Please select from the given options.\n";
            }
        }
    }

    // Virtual function for calculating risk score. Override in each derived class
    virtual void calculateRisk() = 0;

    // Retrieves risk score for the assessment
    double getRisk() const {
        return riskScore;
    }
};
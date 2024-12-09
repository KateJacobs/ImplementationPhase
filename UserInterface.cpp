/*

UserInterface.cpp

This file contains the definitions of the functions declared in the UserInterface header file.

The UserInterface class handles the main user interaction for the system, including:
    - Displaying the menu
    - Processing user inputs
    - Managing interactions with CognitiveTest, LifestyleAssessment, GeneticAssessment,
      RiskAssessment, Recommendations, and GraphicalReport classes

The class provides a menu-driven interface for users to complete their assessments and view their results.

*/

#include <iostream>
#include <vector>
#include <string>
#include "UserInterface.h"
#include "CognitiveTest.h"
#include "LifestyleAssessment.h"
#include "GeneticAssessment.h"
#include "RiskAssessment.h"
#include "GraphicalReport.h"
#include "Recommendations.h"

using namespace std;

UserInterface::UserInterface() : currentScreen("menu") {} // Constructor that initializes currentScreen to the menu

// Displays the main menu and returns the user's choice
int UserInterface::displayMenu() {
    cout << "\n===================================\n";
    cout << " Alzheimer's Disease Risk Assessment \n";
    cout << "===================================\n";
    cout << "1. Take Cognitive Test\n";
    cout << "2. Take Lifestyle Assessment\n";
    cout << "3. Enter Genetic Information\n";
    cout << "4. View Results and Recommendations\n";
    cout << "5. Exit\n";
    cout << "Please select an option: ";
    int choice;
    cin >> choice;
    return choice;
}

// Starts the cognitive test
void UserInterface::loadCognitiveTest() {
    cout << "\nStarting Cognitive Test...\n";
    CognitiveTest cognitiveTest;
    userResponses.clear(); // Clear previous responses

    // Display each question, get responses, and record them
    for (size_t i = 0; i < 20; ++i) {
        cognitiveTest.displayQuestion(i);
        char response;
        cout << "Your response (A, B, C, or D): ";
        cin >> response;
        userResponses.push_back(response);
        cognitiveTest.recordResponse(i, response);
    }
}

// Starts the lifestyle assessment
void UserInterface::loadLifestyleAssessment() {
    cout << "\nStarting Lifestyle Assessment...\n";
    LifestyleAssessment lifestyleAssessment;
    userResponses.clear(); // Clear previous responses

    // Display each question, get responses, and record them
    for (size_t i = 0; i < 10; ++i) {
        lifestyleAssessment.displayQuestion(i);
        char response;
        cout << "Your response (A, B, C, or D): ";
        cin >> response;
        userResponses.push_back(response);
        lifestyleAssessment.recordResponse(i, response);
    }
}

// Starts the genetic assessment
void UserInterface::loadGeneticAssessment() {
    cout << "\nStarting Genetic Assessment...\n";
    GeneticAssessment geneticAssessment;
    userResponses.clear(); // Clear previous responses

    // Display each question, get responses, and record them
    for (size_t i = 0; i < 5; ++i) {
        geneticAssessment.displayQuestion(i);
        char response;
        cout << "Your response (A or B): ";
        cin >> response;
        userResponses.push_back(response);
        geneticAssessment.recordResponse(i, response);
    }
}

// Display results and recommendations
void UserInterface::loadResultsAndRecommendations() {
    cout << "\nGenerating Results and Recommendations...\n";

    // Create assessment objects to get risk scores
    CognitiveTest cognitiveTest;
    LifestyleAssessment lifestyleAssessment;
    GeneticAssessment geneticAssessment;

    // Get risk scores
    double cognitiveRisk = cognitiveTest.getRisk();
    double lifestyleRisk = lifestyleAssessment.getRisk();
    double geneticRisk = geneticAssessment.getRisk();

    // Calculate total risk and generate report
    RiskAssessment riskAssessment;
    riskAssessment.totalRisk(cognitiveRisk, lifestyleRisk, geneticRisk);
    double totalRisk = riskAssessment.calculateFinalRisk();
    string riskReport = riskAssessment.generateRiskReport();

    // Display risk report
    cout << "\nRisk Report:\n" << riskReport << "\n";

    // Generate and display graphical reports
    GraphicalReport graphicalReport;
    for (int i = 0; i < 3; ++i) {
        graphicalReport.generateGraph(i);
        graphicalReport.displayGraph(i);
    }

    // Generate recommendations based on total risk
    Recommendations recommendations;
    recommendations.generateRecommendations(totalRisk);
    recommendations.displayRecommendations();
}

// Main loop for running the user interface
void UserInterface::run() {
    bool running = true;
    while (running) {
        int choice = displayMenu();
        switch (choice) {
        case 1:
            loadCognitiveTest();
            break;
        case 2:
            loadLifestyleAssessment();
            break;
        case 3:
            loadGeneticAssessment();
            break;
        case 4:
            loadResultsAndRecommendations();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            running = false;
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    }
}
#pragma once

/*
*
UserInterface.h

This header file defines the UserInterface class, including its functions and implementation.
It provides a menu-driven interface for interacting with the user and coordinating data flow
between various components of the Alzheimer's Disease Risk Assessment system, such as:
    - CognitiveTest
    - LifestyleAssessment
    - GeneticAssessment
    - RiskAssessment
    - Recommendations
    - GraphicalReport

The class enables users to complete assessments, view results, and receive recommendations.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include "CognitiveAssessment.h"
#include "LifestyleAssessment.h"
#include "GeneticAssessment.h"
#include "RiskAssessment.h"
#include "Recommendations.h"
#include "GraphicalReport.h"

using namespace std;

class UserInterface {
private:
    string currentScreen;           // Tracks the current screen
    vector<char> userResponses;    // Temporarily stores user responses
    CognitiveTest cognitiveTest;
    LifestyleTest lifestyleTest;
    GeneticTest geneticTest;
    RiskAssessment riskAssessment;

    // Displays the main menu and returns the user's choice
    int displayMenu() {
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

    // Handles the cognitive test
    void loadCognitiveTest() {
        //CognitiveTest cognitiveTest;
        for (size_t i = 0; i < 20; ++i) {
            cognitiveTest.displayQuestion(i);
            char response;
            cout << "Your response (A, B, C, or D): ";
            cin >> response;
            cognitiveTest.recordResponse(i, response);
        }
        cognitiveTest.calculateRisk();
    }

    // Handles the lifestyle assessment
    void loadLifestyleAssessment() {
       // LifestyleTest lifestyleTest;
        for (size_t i = 0; i < 10; ++i) {
            lifestyleTest.displayQuestion(i);
            char response;
            cout << "Your response (A, B, C, or D): ";
            cin >> response;
            lifestyleTest.recordResponse(i, response);
        }
        lifestyleTest.calculateRisk();
    }

    // Handles the genetic assessment
    void loadGeneticAssessment() {
       // GeneticTest geneticTest;
        for (size_t i = 0; i < 5; ++i) {
            geneticTest.displayQuestion(i);
            char response;
            cout << "Your response (A or B): ";
            cin >> response;
            geneticTest.recordResponse(i, response);
        }
        geneticTest.calculateRisk();
    }

    // Displays results and recommendations
    void loadResultsAndRecommendations() {

        double cognitiveRisk = cognitiveTest.getRisk();
        double lifestyleRisk = lifestyleTest.getRisk();
        double geneticRisk = geneticTest.getRisk();

        double totalRisk = riskAssessment.setTotalRisk(cognitiveRisk, lifestyleRisk, geneticRisk);
        string riskReport = riskAssessment.generateRiskReport();

        cout << "\nRisk Report:\n" << riskReport << "\n";

        GraphicalReport graphicalReport;
        string filename = "risk_report_graph.png";
        graphicalReport.generateGraph(cognitiveRisk, lifestyleRisk, geneticRisk, totalRisk, filename);
        cout << "Graph saved as " << filename << "\n";

        Recommendations recommendations;
        recommendations.generateRecommendations(cognitiveRisk, lifestyleRisk, geneticRisk);
    }

public:
    UserInterface() : currentScreen("menu") {} // Constructor initializes currentScreen to "menu"

    // Main loop for running the interface
    void run() {
        bool running = true;
        while (running) {
            int choice = displayMenu();
            switch (choice) {
            case 1: loadCognitiveTest(); break;
            case 2: loadLifestyleAssessment(); break;
            case 3: loadGeneticAssessment(); break;
            case 4: loadResultsAndRecommendations(); break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
            }
        }
    }
};
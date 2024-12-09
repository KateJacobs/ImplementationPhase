/*

UserInterface.h

This header file defines the UserInterface class. It provides the structure for interacting with the 
user, displaying menus, and coordinating data flow between various components of the product, including:
    - CognitiveTest
    - LifestyleAssessment
    - GeneticAssessment
    - RiskAssessment
    - Recommendations
    - GraphicalReport

The class provides a menu-driven interface for users to complete their assessments and view their results.

*/


#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <vector>
#include <string>
#include "CognitiveTest.h"
#include "LifestyleAssessment.h"
#include "GeneticAssessment.h"
#include "RiskAssessment.h"
#include "Recommendations.h"
#include "GraphicalReport.h"

class UserInterface {
private:
    std::string currentScreen; // Tracks the current screen
    std::vector<char> userResponses; // Stores user responses

    // Displays the main menu and returns the user's choice
    int displayMenu();

    // Starts the cognitive test
    void loadCognitiveTest();

    // Starts the lifestyle assessment
    void loadLifestyleAssessment();

    // Starts the genetic assessment
    void loadGeneticAssessment();

    // Displays results and recommendations
    void loadResultsAndRecommendations();

public:
    UserInterface(); // Constructor

    // Main loop for running the user interface
    void run();
};

#endif
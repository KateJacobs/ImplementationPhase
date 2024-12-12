#pragma once

#include <iostream>

using namespace std;

class RiskAssessment {
private:
    double cognitiveRisk;
    double lifestyleRisk;
    double geneticRisk;
    double totalRisk;
public:
    // constructor
    RiskAssessment() {
        cognitiveRisk = 0;
        lifestyleRisk = 0;
        geneticRisk = 0;
        totalRisk = 0;
    }

    // combine risk scores
    double setTotalRisk(double cognitiveRisk, double lifestyleRisk, double geneticRisk) {
        // get and set value for each risk
        this->cognitiveRisk = cognitiveRisk;
        this->lifestyleRisk = lifestyleRisk;
        this->geneticRisk = geneticRisk;

        // calculate risk
        totalRisk = cognitiveRisk + lifestyleRisk + geneticRisk;
        return totalRisk;
    }

    // Determine risk level (out of 53 points)
    string calculateFinalRisk() const {
        if (totalRisk >= 36) {
            return "Low Risk";
        }
        else if (totalRisk >= 24) {
            return "Moderate Risk";
        }
        else {
            return "High Risk";
        }
    }

    string generateRiskReport() const {
        string report;
        report += "Final Risk Assessment:\n";
        report += "Cognitive Risk: " + to_string(cognitiveRisk) + "\n";
        report += "Lifestyle Risk: " + to_string(lifestyleRisk) + "\n";
        report += "Genetic Risk: " + to_string(geneticRisk) + "\n";
        report += "Total Risk: " + to_string(totalRisk) + "\n";
        report += "Final Risk Level: " + calculateFinalRisk() + "\n";
        return report;
    }

};
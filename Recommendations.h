#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Recommendations {
private:
    vector<string> exerciseBank;
    vector<string> cognitiveExerciseBank;
    vector<string> mentalHealthBank;

    void questionBank() {
        exerciseBank = { "1. Take short, leisurely walks in a safe and familiar environment for 15?20 minutes daily\n",
        "2. Perform seated exercises, such as arm raises, leg lifts, or seated marching.\n",
        "3. Engage in light stretching or gentle yoga to improve flexibility and relaxation.\n",
        "4. Practice breathing exercises combined with light arm movements to enhance lung capacity.\n",
        "5. Use light resistance bands for basic upper-body strengthening exercises.\n" };

        cognitiveExerciseBank = { "1. Engage in brain-stimulating activities, such as puzzles, chess, or learning a new skill.\n",
        "2. Maintain regular social interactions to support emotional and cognitive health.\n",
        "3. Continue with good sleep hygiene?quality sleep promotes cognitive resilience.\n",
        "4. Eat foods that support brain health, like fatty fish, nuts, and whole grains. \n",
        "5. Stay physically active, as exercise improves blood flow to the brain.\n" };

        mentalHealthBank = { "1. Maintain a daily routine that incorporates work, hobbies, and relaxation.\n",
        "2. Engage in social interactions with friends and family to foster emotional connections.\n",
        "3. Continue regular physical exercise to boost endorphins and improve mood.\n",
        "4. Practice mindfulness or meditation to enhance emotional regulation.\n",
        "5. Get 7?9 hours of restful sleep to support mental well-being.\n" };

    }

public:
    void generateRecommendations(double lifestyleScore, double geneticScore, double cognitiveScore) {
        questionBank();
        // physical recommendations
        if (lifestyleScore >= 36) {
            cout << "Lifestyle Low Risk Recommendations: Take short, leisurely walks in a safe and familiar environment for 15?20 minutes daily" << endl;
        }
        else if (lifestyleScore >= 24) {
            cout << "Lifestyle Moderate Risk Recomendations: Perform standing exercises with support, such as squats while holding onto a stable surface." << endl;
        }
        else {
            cout << "Lifestlye High Risk Recomendations: Participate in short, supervised walking sessions, even within the home, to reduce inactivity." << endl;
        }

        // cognitive recommendations
        if (cognitiveScore >= 36) {
            cout << "Cognitive Low Risk Recommendations: Engage in brain-stimulating activities, such as puzzles, chess, or learning a new skill." << endl;
        }
        else if (cognitiveScore >= 24) {
            cout << "Cognitive Moderate Risk Recomendations: Schedule cognitive assessments or memory screenings to track changes over time." << endl;
        }
        else {
            cout << "Cognitive High Risk Recomendations: Adopt cognitive rehabilitation therapies to strengthen mental faculties." << endl;
        }

        // mental health recommendations
        if (lifestyleScore >= 36) {
            cout << "Cognitive Low Risk Recommendations: Engage in social interactions with friends and family to foster emotional connections." << endl;
        }
        else if (cognitiveScore >= 24) {
            cout << "Cognitive Moderate Risk Recomendations: Seek professional counseling or therapy to address emotional concerns." << endl;
        }
        else {
            cout << "Cognitive High Risk Recomendations: Consult a licensed mental health professional for personalized treatment." << endl;
        }

        cout << "Here are some recommended exercises: " << endl;
        cout << "Physical Exercises: \n";
        for (int i = 0; i < exerciseBank.size(); i++) {
            cout << exerciseBank[i];
        }
        cout << "Cognitive Exercises: \n";
        for (int i = 0; i < cognitiveExerciseBank.size(); i++) {
            cout << cognitiveExerciseBank[i];
        }
        cout << "Mental Health Exercises: \n";
        for (int i = 0; i < mentalHealthBank.size(); i++) {
            cout << mentalHealthBank[i];
        }
    }
};
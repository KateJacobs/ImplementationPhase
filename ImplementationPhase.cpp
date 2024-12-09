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

    // return risk score
    double getRisk() {
        return riskScore;
    }
};

// cognitive test sub class
class CognitiveTest : public Assesment {
public:
    // constructor 
    CognitiveTest() {
        // all 20 questions 
        questions = { "Which of these is a color?",
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
        options = { {"Red", "Chair", "Dog", "I don't know"},
            {"1", "2", "3", "I don't know"},
            {"Apple", "Chair", "Table", "I don't know"},
            {"Glass", "Shoes", "Blanket", "I don't know"},
            {"Five", "Tree", "Dog", "I don't know"},
            {"Morning", "Night", "Afternoon", "I don't know"},
            {"Pen", "Shoe", "Spoon", "I don't know"},
            {"3", "4", "5", "I don't know"},
            {"Shoes", "Hat", "Jacket", "I don't know"},
            {"Water", "Rock", "Paper", "I don;t know"},
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

    // calculate risk function to score the results
    void calculateRisk() {
        // populate the correct answers vector 
        vector <string> correctAnswers = { "A", "B", "A", "A", "A", "B", "A", "B", "A", "A", "C", "A", "B", "B", "B", "A", "B", "A", "C", "A" };

        // variable to keep track of num incorrect 
        double numIncorrect = 0;

        // determine if answer is correct, if not then add the proper point values
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i].empty() || answer[i] != correctAnswers[i] && i <= 10) {
                numIncorrect++;
            }
            else if (answer[i].empty() || answer[i] != correctAnswers[i] && (i > 10 && i <= 17)) {
                numIncorrect = numIncorrect + 2;
            }
            else {
                numIncorrect = numIncorrect + 3;
            }
        }

        // determine risk score
        // 33 points possible
        riskScore = numIncorrect / 33 * 10;
    }
};

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
    void setTotalRisk(double cognitiveRisk, double lifestyleRisk, double geneticRisk) {
        // get and set value for each risk
        this->cognitiveRisk = cognitiveRisk;
        this->lifestyleRisk = lifestyleRisk;
        this->geneticRisk = geneticRisk;

        // calculate risk
        totalRisk = cognitiveRisk + lifestyleRisk + geneticRisk;
    }

    // determine risk level
    void calculateFinalRisk() {
        if (totalRisk < 5.0) {
            cout << "Low Risk";
        }
        else if (totalRisk >= 5 && totalRisk < 8) {
            cout << "Medium Risk";
        }
        else {
            cout << "High Risk";
        }
    }

    void generateRiskReport() {
        cout << "Final Risk Assesment: \n";
        cout << "Cognitive Risk: " << cognitiveRisk << "\n";
        cout << "Lifestyle Risk: " << lifestyleRisk << "\n";
        cout << "Geneic Risk: " << geneticRisk << "\n";
        cout << "Total Risk: " << totalRisk << "\n";
        cout << "Final Risk Level: ";
        calculateFinalRisk();
        cout << "\n";
    }
};

class GraphicalReport {
private:
    double graphData[3];
    string graphTitles[3];

public:
    // constructor
    GraphicalReport() {
        graphData[0] = 0;
        graphData[1] = 0;
        graphData[2] = 0;
        graphTitles[0] = "Cognitive Risk";
        graphTitles[1] = "Lifestyle Risk";
        graphTitles[2] = "Genetic Risk";
    }
};

class Recomendations {
private:
    vector<string> exerciseBank;
    vector<string> cognitiveExerciseBank;
    vector<string> mentalHealthBank;

    void questionBank() {
        exerciseBank = { "1. Take short, leisurely walks in a safe and familiar environment for 15–20 minutes daily\n",
        "2. Perform seated exercises, such as arm raises, leg lifts, or seated marching.\n",
        "3. Engage in light stretching or gentle yoga to improve flexibility and relaxation.\n",
        "4. Practice breathing exercises combined with light arm movements to enhance lung capacity.\n",
        "5. Use light resistance bands for basic upper-body strengthening exercises.\n" };

        cognitiveExerciseBank = { "1. Engage in brain-stimulating activities, such as puzzles, chess, or learning a new skill.\n",
        "2. Maintain regular social interactions to support emotional and cognitive health.\n",
        "3. Continue with good sleep hygiene—quality sleep promotes cognitive resilience.\n",
        "4. Eat foods that support brain health, like fatty fish, nuts, and whole grains. \n",
        "5. Stay physically active, as exercise improves blood flow to the brain.\n" };

        mentalHealthBank = { "1. Maintain a daily routine that incorporates work, hobbies, and relaxation.\n",
        "2. Engage in social interactions with friends and family to foster emotional connections.\n",
        "3. Continue regular physical exercise to boost endorphins and improve mood.\n",
        "4. Practice mindfulness or meditation to enhance emotional regulation.\n",
        "5. Get 7–9 hours of restful sleep to support mental well-being.\n" };

    }

public:
    void generateRecommendations(double lifestyleScore, double geneticScore, double cognitiveScore) {
        questionBank();
        // physical recommendations
        if (lifestyleScore >= 15) {
            cout << "Lifestyle Low Risk Recommendations: Take short, leisurely walks in a safe and familiar environment for 15–20 minutes daily" << endl;
        }
        else if (lifestyleScore >= 8 && lifestyleScore <= 14) {
            cout << "Lifestyle Moderate Risk Recomendations: Perform standing exercises with support, such as squats while holding onto a stable surface." << endl;
        }
        else {
            cout << "Lifestlye High Risk Recomendations: Participate in short, supervised walking sessions, even within the home, to reduce inactivity." << endl;
        }

        // cognitive recommendations
        if (cognitiveScore >= 15) {
            cout << "Cognitive Low Risk Recommendations: Engage in brain-stimulating activities, such as puzzles, chess, or learning a new skill." << endl;
        }
        else if (cognitiveScore >= 8 && cognitiveScore <= 14) {
            cout << "Cognitive Moderate Risk Recomendations: Schedule cognitive assessments or memory screenings to track changes over time." << endl;
        }
        else {
            cout << "Cognitive High Risk Recomendations: Adopt cognitive rehabilitation therapies to strengthen mental faculties." << endl;
        }

        // mental health recommendations
        if (lifestyleScore >= 15) {
            cout << "Cognitive Low Risk Recommendations: Engage in social interactions with friends and family to foster emotional connections." << endl;
        }
        else if (cognitiveScore >= 8 && cognitiveScore <= 14) {
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

int main() {
    RiskAssessment risk;

    risk.setTotalRisk(3, 4, 5);
    risk.generateRiskReport();

    Recomendations rec;
    double lifestyleScore = 6;
    double geneticScore = 8;
    double cognitiveScore = 15;

    rec.generateRecommendations(lifestyleScore, geneticScore, cognitiveScore);

    return 0;
}
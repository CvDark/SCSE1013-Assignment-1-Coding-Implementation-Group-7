#include <iostream>
#include <string>
using namespace std;


int main() {
    // defining variables for feature 1
    int subjects;

    cout << "Please enter totals subject you have registered for this semester: ";
    cin >> subjects;

    const int MAX = subjects;
    string grade[MAX],SubjectName[MAX];
    int LabToolMark[MAX], LabCodeMark[MAX], Assign1Mark[MAX], Assign2Mark[MAX], QuizMark[MAX], FEMark[MAX], TestMark[MAX],OverallScore[MAX];

    for (int i = 0; i < subjects; i++) {
        cout << "Please enter subject's name: ";
        getline(cin >> ws, SubjectName[i]); // Use ws to consume any leading whitespace

        cout << "Please enter student Lab Exercise (Tools) mark (in percentage):";
        cin >> LabToolMark[i];
        
        cout << "Please enter student Lab Exercise (Code) mark (in percentage):";
        cin >> LabCodeMark[i];

        cout << "Please enter student Assignment 1 mark (in percentage):";
        cin >> Assign1Mark[i];

        cout << "Please enter student Assignment 2 mark (in percentage):";
        cin >> Assign2Mark[i];

        cout << "Please enter student total Quiz mark (in percentage):";
        cin >> QuizMark[i];

        cout << "Please enter student total Test mark (in percentage):";
        cin >> TestMark[i];

        cout << "Please enter student Final Exam mark (in percentage):";
        cin >> FEMark[i];

        //calculate overall score
        OverallScore[i] = LabToolMark[i] + LabCodeMark[i] + Assign1Mark[i] + Assign2Mark[i] + QuizMark[i] + TestMark[i] + FEMark[i];

        // START determine grade based on overall score
        if (OverallScore[i] > 100 || OverallScore[i] < 0) {//check whether the overal score is valid or no
            cout << "Error: Please enter a valid mark between 0 and 100\n";
            return 1; // Exit the program with an error code
        } else if (OverallScore[i] >= 90) {
            grade[i] = "A+";
        } else if (OverallScore[i] >= 80) {
            grade[i] = "A";
        } else if (OverallScore[i] >= 75) {
            grade[i] = "A-";
        } else if (OverallScore[i] >= 70) {
            grade[i] = "B+";
        } else if (OverallScore[i] >= 65) {
            grade[i] = "B";
        } else if (OverallScore[i] >= 60) {
            grade[i] = "B-";
        } else if (OverallScore[i] >= 55) {
            grade[i] = "C+";
        } else if (OverallScore[i] >= 50) {
            grade[i] = "C";
        } else if (OverallScore[i] >= 45) {
            grade[i] = "C-";
        } else if (OverallScore[i] >= 40) {
            grade[i] = "D+";
        } else if (OverallScore[i] >= 35) {
            grade[i] = "D";
        } else if (OverallScore[i] >= 30) {
            grade[i] = "D-";
        } else {
            grade[i] = "F";
        }
    }
    
    for (int i = 0; i < subjects; i++) {
        cout << "Subject: " << SubjectName[i] << " | Overall Score: " << OverallScore[i] << " | Grade: " << grade[i] << '\n';
    }
    return 0;
}
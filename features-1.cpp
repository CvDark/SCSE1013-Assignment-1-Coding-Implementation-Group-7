#include <iostream>
#include <string>
using namespace std;


int main() {
    int LabToolMark,LabCodeMark,Assign1Mark,Assign2Mark,QuizMark,FEMark,TestMark;
    float FLabToolMark,FLabCodeMark,FAssign1Mark,FAssign2Mark,FQuizMark,TFEMark,FTestMark,OverallScore;
    string grade;

    cout << "Please enter student Lab Exercise (Tools) mark:"<< '\n';
    cin >> LabToolMark;
    FLabToolMark = (LabToolMark/)*0.1;

    cout << "Please enter student Lab Exercise (Code) mark:"<< '\n';
    cin >> LabCodeMark;
    FLabCodeMark = (LabCodeMark/)*0.1;

    cout << "Please enter student Assignment 1 mark:"<< '\n';
    cin >> Assign1Mark;
    FAssign1Mark = (Assign1Mark/)*0.1;

    cout << "Please enter student Assignment 2 mark:"<< '\n';
    cin >> Assign2Mark;
    FAssign2Mark = (Assign2Mark/)*0.1;

    cout << "Please enter student total Quiz mark:"<< '\n';
    cin >> QuizMark;
    FQuizMark = (QuizMark/)*0.1;    
    
    cout << "Please enter student total Test mark:"<< '\n';
    cin >> TestMark;
    FTestMark = (TestMark/)*0.2;

    cout << "Please enter student Final Exam mark:"<< '\n';
    cin >> FEMark;
    TFEMark = (FEMark/)*0.3;
    
    OverallScore = FLabToolMark + FLabCodeMark + FAssign1Mark + FAssign2Mark + FQuizMark + FTestMark + TFEMark;
    if (OverallScore > 100 || OverallScore < 0)  {
        cout <<"Error: Please enter a valid mark between 0 and 100"<< "n";
        
    } else if (OverallScore >= 90) {
        grade = "A+";
        cout << grade << '\n';

    } else if (OverallScore >= 80) {
        grade = "A";
        cout << grade << '\n';

    } else if (OverallScore >= 75) {
        grade = "A-";
        cout << grade << '\n';

    } else if (OverallScore >= 70) {
        grade = "B+";
        cout << grade << '\n';

    } else if (OverallScore >= 65) {
        grade = "B";
        cout << grade << '\n';

    } else if (OverallScore >= 60) {
        grade = "B-";
        cout << grade << '\n';

    } else if (OverallScore >= 55) {
        grade = "C+";
        cout << grade << '\n';

    } else if (OverallScore >= 50) {
        grade = "C";
        cout << grade << '\n';

    } else if (OverallScore >= 45) {
        grade = "C-";
        cout << grade << '\n';

    } else if (OverallScore >= 40) {
        grade = "D+";
        cout << grade << '\n';

    } else if (OverallScore >= 35) {
        grade = "D";
        cout << grade << '\n';

    } else if (OverallScore >= 30) {
        grade = "D-";
        cout << grade << '\n';
        
    } else {
        grade = "F";
        cout << grade << '\n';
    }
   return 0;
}
